%************************************************************************
% you may instead use C-Function block in simulink to directly write C
% functions in simulink, however it is not the best cast for abstraction,
% optimization and utilization of matlab and simulink capabilites. using
% S_function block will give the advantage of using matlab coding and pre
% define toolboxes and libraries. it also give better results while using
% autocode generation as it is way more understandable to simulink solvers
% that C blocks.

%************************************************************************

%check if you have a vaild compiler or not
%mex -setup
%select the required environment as MinGW if you want to 
%setenv('MW_MINGW64_LOC','path\to\MinGW')

%check if mex work properly by trying to generate Matlab Executable using
%mex command 
%mex C_file.c

%start generating S-Function (Simulink Function)%

% 1- create *.c and *.h files that will have the function implementation in
% C language

% 2- initialize you S-Function using the following command. note that it
% is not mandatory to create S-Function frm C files. you may creat a stand
% alone S_function that have its loginc implemented using some APIs
% provided by MEX tool. legacy_code('initialize') will initiate your object
% members required for Sfunction
my_S_function = legacy_code('initialize')

% 3-  define name of S-Function
my_S_function.SFunctionName = "my_S_Func"

% 4- add function prototype of the function. make sure to provide the
% arguments as u1, u2, u3 ...etc, also output must be y1,y2,...etc.
my_S_function.OutputFcnSpec = 'double y1 = my_S_Func(double u1, double u2)'

% 5- header and source file adding
my_S_function.HeaderFiles = {'HeaderFileName.h'}
my_S_function.SourceFiles = {'SrcFileName.c'}

% 6- process files and generate legacy compatible *.c file that will be later
% compiled to produce executable matlab file (*.mex) and DLL files if any.
% this file will contain basic function that is being called in the
% starting, executing, and terminating the simulation. these are default
% functions and you user defined function  my_S_Func(double u1, double u2)
% will be called in the execution {calculating output} phase.
legacy_code('sfcn_cmex_generate',my_S_function)
%notice new .c file with your SFunctionName is created.

% 7- compile and generate .mex file
legacy_code('compile',my_S_function)

% 8- mex file is generated in you workspace successfully. You may now creat
% SFunction block in simulink and change its "S_function name" parameter to
% you Sfunction name which is in my case 'my_S_function'
