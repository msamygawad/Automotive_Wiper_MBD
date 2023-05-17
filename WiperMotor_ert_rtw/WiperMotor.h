/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: WiperMotor.h
 *
 * Code generated for Simulink model 'WiperMotor'.
 *
 * Model version                  : 1.22
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu May 18 02:18:54 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_WiperMotor_h_
#define RTW_HEADER_WiperMotor_h_
#ifndef WiperMotor_COMMON_INCLUDES_
#define WiperMotor_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* WiperMotor_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S2>/Unit Delay' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  uint8_T wiperModeInput;              /* '<Root>/wiperModeInput' */
  uint8_T rainSensorInput;             /* '<Root>/rainSensorInput' */
  real_T wiperSpeedInput;              /* '<Root>/wiperSpeedInput' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T DutyCycle;                    /* '<Root>/DutyCycle' */
  boolean_T WiperIndicator;            /* '<Root>/WiperIndicator' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void WiperMotor_initialize(void);
extern void WiperMotor_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S5>/SelectMethod' : Unused code path elimination
 * Block '<S8>/Add' : Unused code path elimination
 * Block '<S8>/Add1' : Unused code path elimination
 * Block '<S8>/Saturation' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('Automotive_Wiper/WiperMotor')    - opens subsystem Automotive_Wiper/WiperMotor
 * hilite_system('Automotive_Wiper/WiperMotor/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Automotive_Wiper'
 * '<S1>'   : 'Automotive_Wiper/WiperMotor'
 * '<S2>'   : 'Automotive_Wiper/WiperMotor/Automotive_Wiper_Controller'
 * '<S3>'   : 'Automotive_Wiper/WiperMotor/Automotive_Wiper_Controller/Default'
 * '<S4>'   : 'Automotive_Wiper/WiperMotor/Automotive_Wiper_Controller/Mode0'
 * '<S5>'   : 'Automotive_Wiper/WiperMotor/Automotive_Wiper_Controller/Mode1'
 * '<S6>'   : 'Automotive_Wiper/WiperMotor/Automotive_Wiper_Controller/Mode2'
 * '<S7>'   : 'Automotive_Wiper/WiperMotor/Automotive_Wiper_Controller/Mode3'
 * '<S8>'   : 'Automotive_Wiper/WiperMotor/Automotive_Wiper_Controller/Mode1/Smoother_FeedBackIncrementMethod_1'
 * '<S9>'   : 'Automotive_Wiper/WiperMotor/Automotive_Wiper_Controller/Mode1/Smoother_LowPathFilterMethod_0'
 */
#endif                                 /* RTW_HEADER_WiperMotor_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
