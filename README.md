# Automotive_Wiper_MBD
Automotive wiper control desing using simulink model based approach to generate Embedded C code

System Operation Modes:  
0 --> OFF  
1 --> Automaitc Speed Mode (user select wiper speed using input spinner)  
2 --> LowSpeed Mode (wiper operates on fixed speed 40% duty cycle)  
4 --> High Speed Mode (wiper operates on fixed speed 70% duty cycle)  

System constrains:   
0- an indicator is used to tell if the wipers are working or not
1- if rain sensor fired && Mode (1) is activated --> then stop the wipers  
2- if system operates on Mode (1) && user changed speed --> Change speed gradually not instantaneously !!

TODOs:
1- apply gradual increase method to all speed changes
2- simulate model generated code in proteus
3- Add graphical representations for wipers and speed knops

![System](https://github.com/msamygawad/Automotive_Wiper_MBD/blob/main/readmeImage.png)
