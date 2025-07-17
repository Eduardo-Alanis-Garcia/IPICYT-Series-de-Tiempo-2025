/*
 * File: HolaMundo.c
 *
 * Code generated for Simulink model 'HolaMundo'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Fri Jul 11 12:43:34 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "HolaMundo.h"
#include "HolaMundo_private.h"
#include "rtwtypes.h"
#include <math.h>

/* Block states (default storage) */
DW_HolaMundo_T HolaMundo_DW;

/* Real-time model */
static RT_MODEL_HolaMundo_T HolaMundo_M_;
RT_MODEL_HolaMundo_T *const HolaMundo_M = &HolaMundo_M_;
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void HolaMundo_step(void)
{
  real_T rtb_PulseGenerator;
  uint8_T tmp;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (HolaMundo_DW.clockTickCounter <
                        HolaMundo_P.PulseGenerator_Duty) &&
    (HolaMundo_DW.clockTickCounter >= 0L) ? HolaMundo_P.PulseGenerator_Amp : 0.0;
  if (HolaMundo_DW.clockTickCounter >= HolaMundo_P.PulseGenerator_Period - 1.0)
  {
    HolaMundo_DW.clockTickCounter = 0L;
  } else {
    HolaMundo_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* MATLABSystem: '<Root>/Digital Output' */
  rtb_PulseGenerator = rt_roundd_snf(rtb_PulseGenerator);
  if (rtb_PulseGenerator < 256.0) {
    if (rtb_PulseGenerator >= 0.0) {
      tmp = (uint8_T)rtb_PulseGenerator;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(13, tmp);

  /* End of MATLABSystem: '<Root>/Digital Output' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.5, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  HolaMundo_M->Timing.clockTick0++;
}

/* Model initialize function */
void HolaMundo_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(HolaMundo_M, 10.0);

  /* External mode info */
  HolaMundo_M->Sizes.checksums[0] = (1619630127U);
  HolaMundo_M->Sizes.checksums[1] = (1062583478U);
  HolaMundo_M->Sizes.checksums[2] = (3804109316U);
  HolaMundo_M->Sizes.checksums[3] = (468645522U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    HolaMundo_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(HolaMundo_M->extModeInfo,
      &HolaMundo_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(HolaMundo_M->extModeInfo, HolaMundo_M->Sizes.checksums);
    rteiSetTFinalTicks(HolaMundo_M->extModeInfo, 20);
  }

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  HolaMundo_DW.obj.matlabCodegenIsDeleted = false;
  HolaMundo_DW.obj.isInitialized = 1L;
  digitalIOSetup(13, 1);
  HolaMundo_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void HolaMundo_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!HolaMundo_DW.obj.matlabCodegenIsDeleted) {
    HolaMundo_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
