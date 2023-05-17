/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: WiperMotor.c
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

#include "WiperMotor.h"
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (rtM->Timing.TaskCounters.TID[1])++;
  if ((rtM->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [1.0s, 0.0s] */
    rtM->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function */
void WiperMotor_step(void)
{
  real_T rtb_MultiportSwitch;

  /* S-Function (fcgen): '<S1>/Schedular_10ms' incorporates:
   *  SubSystem: '<S1>/Automotive_Wiper_Controller'
   */
  /* MultiPortSwitch: '<S2>/Multiport Switch' incorporates:
   *  Constant: '<S2>/Constant10'
   *  Constant: '<S2>/Constant11'
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S2>/Constant5'
   *  Constant: '<S2>/Constant6'
   *  Constant: '<S2>/Constant7'
   *  Constant: '<S2>/Constant8'
   *  Constant: '<S2>/Constant9'
   *  Inport: '<Root>/wiperSpeedInput'
   */
  switch ((int32_T)rtU.wiperSpeedInput) {
   case 0:
    rtb_MultiportSwitch = 0.0;
    break;

   case 1:
    rtb_MultiportSwitch = 0.4;
    break;

   case 2:
    rtb_MultiportSwitch = 0.45;
    break;

   case 3:
    rtb_MultiportSwitch = 0.5;
    break;

   case 4:
    rtb_MultiportSwitch = 0.55;
    break;

   case 5:
    rtb_MultiportSwitch = 0.6;
    break;

   case 6:
    rtb_MultiportSwitch = 0.65;
    break;

   default:
    rtb_MultiportSwitch = 0.7;
    break;
  }

  /* End of MultiPortSwitch: '<S2>/Multiport Switch' */

  /* SwitchCase: '<S2>/Switch Case' incorporates:
   *  Inport: '<Root>/wiperModeInput'
   */
  switch (rtU.wiperModeInput) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S2>/Mode0' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* Merge: '<S2>/Merge' incorporates:
     *  Constant: '<S2>/Constant'
     *  SignalConversion generated from: '<S4>/In1'
     */
    rtb_MultiportSwitch = 0.0;

    /* End of Outputs for SubSystem: '<S2>/Mode0' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S2>/Mode1' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Switch: '<S5>/Switch' incorporates:
     *  Inport: '<Root>/rainSensorInput'
     */
    if (rtU.rainSensorInput > 0) {
      /* Merge: '<S2>/Merge' incorporates:
       *  Constant: '<S5>/Constant'
       */
      rtb_MultiportSwitch = 0.0;
    } else {
      /* Merge: '<S2>/Merge' incorporates:
       *  Gain: '<S9>/Gain'
       *  Gain: '<S9>/Gain1'
       *  Sum: '<S9>/Add2'
       *  UnitDelay: '<S2>/Unit Delay'
       */
      rtb_MultiportSwitch = 0.1 * rtb_MultiportSwitch + 0.9 *
        rtDW.UnitDelay_DSTATE;
    }

    /* End of Switch: '<S5>/Switch' */
    /* End of Outputs for SubSystem: '<S2>/Mode1' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S2>/Mode2' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    /* Merge: '<S2>/Merge' incorporates:
     *  Constant: '<S2>/Constant3'
     *  SignalConversion generated from: '<S6>/In1'
     */
    rtb_MultiportSwitch = 0.4;

    /* End of Outputs for SubSystem: '<S2>/Mode2' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S2>/Mode3' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    /* Merge: '<S2>/Merge' incorporates:
     *  Constant: '<S2>/Constant2'
     *  SignalConversion generated from: '<S7>/In1'
     */
    rtb_MultiportSwitch = 0.7;

    /* End of Outputs for SubSystem: '<S2>/Mode3' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S2>/Default' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* Merge: '<S2>/Merge' incorporates:
     *  Constant: '<S2>/Constant1'
     *  SignalConversion generated from: '<S3>/In1'
     */
    rtb_MultiportSwitch = 0.0;

    /* End of Outputs for SubSystem: '<S2>/Default' */
    break;
  }

  /* End of SwitchCase: '<S2>/Switch Case' */

  /* Outport: '<Root>/WiperIndicator' incorporates:
   *  Logic: '<S2>/AND'
   */
  rtY.WiperIndicator = (rtb_MultiportSwitch != 0.0);

  /* Update for UnitDelay: '<S2>/Unit Delay' */
  rtDW.UnitDelay_DSTATE = rtb_MultiportSwitch;

  /* End of Outputs for S-Function (fcgen): '<S1>/Schedular_10ms' */

  /* Outport: '<Root>/DutyCycle' */
  rtY.DutyCycle = rtb_MultiportSwitch;
  rate_scheduler();
}

/* Model initialize function */
void WiperMotor_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
