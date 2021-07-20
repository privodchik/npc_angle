
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
const float _PI = 3.141592;
const float _2PI = 2.0*_PI;

CIntegrator* p_angleRemote;
CIntegrator* p_angleSelfRef;
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Start function
 *
 */
void acs_angle_Start_wrapper(const real_T *_Ts, const int_T p_width0)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
p_angleRemote = new CIntegrator(_Ts[0], PERIOD/_2PI, _2PI, -_2PI);
p_angleRemote->config_set();

p_angleSelfRef = new CIntegrator(_Ts[0], PERIOD/_2PI, _2PI, -_2PI);
p_angleSelfRef->config_set();

/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
void acs_angle_Outputs_wrapper(const real_T *rand,
			const real_T *errQ,
			real_T *RemoteQ,
			real_T *SelfQ,
			const real_T *_Ts, const int_T p_width0)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
float _angle = p_angleRemote->out_est(1.0);
_angle += rand[0];

float _angleSelf = p_angleSelfRef->out_est(1.0);

auto f = [](float& _angle){
    if (_angle > _PI){
    _angle = -_PI + (_angle - _PI);
    } 
    else if (_angle < -_PI){
        _angle = -_PI - _angle;
    }
};

f(_angle);

_angleSelf += errQ[0];
f(_angleSelf);



p_angleRemote->out_set(_angle);
p_angleSelfRef->out_set(_angleSelf);

RemoteQ[0] = p_angleRemote->out_get();
SelfQ[0] = p_angleSelfRef->out_get();

/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Terminate function
 *
 */
void acs_angle_Terminate_wrapper(const real_T *_Ts, const int_T p_width0)
{
/* %%%-SFUNWIZ_wrapper_Terminate_Changes_BEGIN --- EDIT HERE TO _END */
delete p_angleRemote;
/* %%%-SFUNWIZ_wrapper_Terminate_Changes_END --- EDIT HERE TO _BEGIN */
}

