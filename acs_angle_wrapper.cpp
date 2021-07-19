
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
#include <memory>
#include "TF/integrator.h"
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
const float FREQ = 400;
const float PERIOD = 1.0/FREQ;
const float _PI = 3.14159265;
const float _2PI = 2.0 * _PI;

auto p_angleRemote = std::make_unique<CIntegrator>(CIntegrator());
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Start function
 *
 */
void acs_angle_Start_wrapper(const real_T *_Ts, const int_T p_width0)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
p_angleRemote->Ti_set(PERIOD/_2PI);
p_angleRemote->Ts_set(_Ts[0]);
p_angleRemote->sat_set(_2PI, -_2PI);
p_angleRemote->config_set();
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
void acs_angle_Outputs_wrapper(const real_T *rand,
			real_T *y0,
			const real_T *_Ts, const int_T p_width0)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
 
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


