/* 
 * File: HolaMundo.c
 *  
 * Code generated for Simulink model 'HolaMundo'.
 * 
 * Model version                  : 1.0
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Fri Jul 11 12:38:43 2025
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

            

        

        





        




                                    
                                    



/* {S!d220}DiscretePulseGenerator: '<Root>/Pulse Generator' */
/*@>36c4c*/rtb_PulseGenerator/*@>3582c*/ = (/*@>38407*/HolaMundo_DW./*@>38720*/clockTickCounter/*@>35825*/ < /*@>383f1*/HolaMundo_P./*@>38717*/PulseGenerator_Duty)/*@>35829*/ && (/*@>3840d*/HolaMundo_DW./*@>38723*/clockTickCounter/*@>35828*/ >= /*@>3743c*/0L)/*@>35829*/ ? /*@>383f7*/HolaMundo_P./*@>3871a*/PulseGenerator_Amp : /*@>36c4b*/0.0;
/*@>3725e*/if (/*@>38413*/HolaMundo_DW./*@>38726*/clockTickCounter/*@>35832*/ >= /*@>383fd*/HolaMundo_P./*@>3871d*/PulseGenerator_Period/*@>3582f*/ - /*@>36c5b*/1.0) {
    /*@>38419*/HolaMundo_DW./*@>38729*/clockTickCounter/*@>37261*/ = /*@>37449*/0L;
} else {
    /*@>3841f*/HolaMundo_DW./*@>3872c*/clockTickCounter/*@>386dc*/++;
}
/* {E!d220}End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

/* {S!d222}MATLABSystem: '<Root>/Digital Output' */
/*@>36ca3*/rtb_PulseGenerator/*@>36ca5*/ = /*@[3867b*/rt_roundd_snf(/*@>38753*/rtb_PulseGenerator)/*@]*/;
/*@>3726c*/if (/*@>371f4*/rtb_PulseGenerator/*@>371f2*/ < /*@>371f5*/256.0) {
    /*@>37271*/if (/*@>371f9*/rtb_PulseGenerator/*@>371f7*/ >= /*@>371fa*/0.0) {
        /*@>37275*/tmp/*@>37274*/ = /*@>37459*/(uint8_T)/*@>371fd*/rtb_PulseGenerator;
    } else {
        /*@>37270*/tmp/*@>3726f*/ = /*@>386d3*/0U;
    }
} else {
    /*@>37265*/tmp/*@>37267*/ = /*@>37450*/MAX_uint8_T;
}
/*@>38127*/writeDigitalPin(/*@>3745c*/13, /*@>37269*/tmp);
/* {E!d222}End of MATLABSystem: '<Root>/Digital Output' */









        








                    



        
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
                    static const sysRanDType  rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
                    static RTWExtModeInfo rt_ExtModeInfo;
                    static const sysRanDType *systemRan[2];



                HolaMundo_M->extModeInfo = (&rt_ExtModeInfo);
                rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
                
                systemRan[0] = &rtAlwaysEnabled;
                systemRan[1] = &rtAlwaysEnabled;


                rteiSetModelMappingInfoPtr(HolaMundo_M->extModeInfo, &HolaMundo_M->SpecialInfo.mappingInfo);

                rteiSetChecksumsPtr(HolaMundo_M->extModeInfo, HolaMundo_M->Sizes.checksums);


                    rteiSetTFinalTicks(HolaMundo_M->extModeInfo, 20);
        }








        








            



        















        

    
            
    
        











                                            
                                    

        



        



        



/* Start for MATLABSystem: '<Root>/Digital Output' */
/*@>38437*/HolaMundo_DW./*@>387b9*/obj./*@>387b0*/matlabCodegenIsDeleted/*@>35a0b*/ = /*@>36c77*/false;
/*@>3843d*/HolaMundo_DW./*@>387bc*/obj./*@>387b3*/isInitialized/*@>35a05*/ = /*@>374b2*/1L;
/*@>3812f*/digitalIOSetup(/*@>374b5*/13, /*@>374b8*/1);
/*@>38443*/HolaMundo_DW./*@>387bf*/obj./*@>387b6*/isSetupComplete/*@>35a02*/ = /*@>36c7c*/true;

















    





                



        
    }        






        




        
        /* Model terminate function */
                    void HolaMundo_terminate(void)

        {
            


                                                            




        




                                    

                        
                                    /* {S!d224}Terminate for MATLABSystem: '<Root>/Digital Output' */
/*@>35986*/if (!/*@<35984*//*@>3842b*/HolaMundo_DW./*@>3877f*/obj.matlabCodegenIsDeleted) {
    /*@>38431*/HolaMundo_DW./*@>38782*/obj./*@>3877c*/matlabCodegenIsDeleted/*@>35983*/ = /*@>36c63*/true;
}
/* {E!d224}End of Terminate for MATLABSystem: '<Root>/Digital Output' */








                    



                    









                                



                        }
            





    





    


    


    


    


/* 
 * File trailer for generated code.
 * 
 * [EOF]
 */

