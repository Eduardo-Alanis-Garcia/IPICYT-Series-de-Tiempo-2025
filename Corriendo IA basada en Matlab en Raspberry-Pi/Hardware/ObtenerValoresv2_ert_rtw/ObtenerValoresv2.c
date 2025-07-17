/*
 * File: ObtenerValoresv2.c
 *
 * Code generated for Simulink model 'ObtenerValoresv2'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Fri Jul 11 02:43:24 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ObtenerValoresv2.h"
#include "rtwtypes.h"
#include "ObtenerValoresv2_private.h"

/* Block signals (default storage) */
B_ObtenerValoresv2_T ObtenerValoresv2_B;

/* Block states (default storage) */
DW_ObtenerValoresv2_T ObtenerValoresv2_DW;

/* Real-time model */
static RT_MODEL_ObtenerValoresv2_T ObtenerValoresv2_M_;
RT_MODEL_ObtenerValoresv2_T *const ObtenerValoresv2_M = &ObtenerValoresv2_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void ObtenerValoresv2_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(ObtenerValoresv2_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (ObtenerValoresv2_M->Timing.TaskCounters.TID[1])++;
  if ((ObtenerValoresv2_M->Timing.TaskCounters.TID[1]) > 32) {/* Sample time: [0.0033s, 0.0s] */
    ObtenerValoresv2_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void ObtenerValoresv2_step0(void)      /* Sample time: [0.0001s, 0.0s] */
{
  {                                    /* Sample time: [0.0001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.0001, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  ObtenerValoresv2_M->Timing.clockTick0++;
}

/* Model step function for TID1 */
void ObtenerValoresv2_step1(void)      /* Sample time: [0.0033s, 0.0s] */
{
  uint16_T b_varargout_1;

  /* MATLABSystem: '<Root>/Analog Input' */
  ObtenerValoresv2_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(14UL);
  MW_AnalogInSingle_ReadResult
    (ObtenerValoresv2_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1, MW_ANALOGIN_UINT16);

  /* Gain: '<Root>/Gain' incorporates:
   *  MATLABSystem: '<Root>/Analog Input'
   * */
  ObtenerValoresv2_B.Gain = (uint32_T)ObtenerValoresv2_P.Gain_Gain *
    b_varargout_1;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.0033, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  ObtenerValoresv2_M->Timing.clockTick1++;
}

/* Model initialize function */
void ObtenerValoresv2_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(ObtenerValoresv2_M, 29.700000000000003);

  /* External mode info */
  ObtenerValoresv2_M->Sizes.checksums[0] = (3810559142U);
  ObtenerValoresv2_M->Sizes.checksums[1] = (3419144919U);
  ObtenerValoresv2_M->Sizes.checksums[2] = (2059971472U);
  ObtenerValoresv2_M->Sizes.checksums[3] = (453384660U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    ObtenerValoresv2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ObtenerValoresv2_M->extModeInfo,
      &ObtenerValoresv2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ObtenerValoresv2_M->extModeInfo,
                        ObtenerValoresv2_M->Sizes.checksums);
    rteiSetTFinalTicks(ObtenerValoresv2_M->extModeInfo, 297000);
  }

  /* Start for MATLABSystem: '<Root>/Analog Input' */
  ObtenerValoresv2_DW.obj.matlabCodegenIsDeleted = false;
  ObtenerValoresv2_DW.obj.isInitialized = 1L;
  ObtenerValoresv2_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(14UL);
  ObtenerValoresv2_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void ObtenerValoresv2_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  if (!ObtenerValoresv2_DW.obj.matlabCodegenIsDeleted) {
    ObtenerValoresv2_DW.obj.matlabCodegenIsDeleted = true;
    if ((ObtenerValoresv2_DW.obj.isInitialized == 1L) &&
        ObtenerValoresv2_DW.obj.isSetupComplete) {
      ObtenerValoresv2_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(14UL);
      MW_AnalogIn_Close
        (ObtenerValoresv2_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
