// Date: 2021.05.07
// Creator: ID

#ifndef _CRMS_H
#define _CRMS_H

#include "iqmath.h"
#include "integrator.h"

class CRMS{
  private:
      CIntegrator m_integrator{IQ(0.0001), IQ(1.0), IQ(1000), IQ(-1000)};
      iq_t m_freq;
      iq_t m_currentValue;
      
  public:
    CRMS(iq_t _Ts, iq_t _freq);
    
    void Ts_set(iq_t _Ts);
    
    iq_t out_est(iq_t _in);
    
    void rms_set(){ m_currentValue = m_integrator.out_get();}
    iq_t rms(){return m_currentValue;}
    
    void out_reset();
};

#endif //_CRMS_H
