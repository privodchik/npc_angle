#include "work_file.h"

namespace user{
    const float _PI = 3.14159265358979;
    const float _2PI = 2.0*_PI;
    const float FREQ = 400.0;
    const float W = 2.0 * _PI * FREQ;

    void wt_sat(iq_t& _wt){
        if (_wt > _PI) _wt -= 2.0 * _PI;
        else if (_wt < -_PI) _wt += 2.0 * _PI; 
    }
    
    iq_t m_currentAngle = 0;
    
    iq_t angle_est(iq_t _W, iq_t _Ts){
        iq_t _delWt = IQmpy(_W, _Ts);
        //_delWt = IQmpy(IQ(0.000001), _delWt);
        m_currentAngle += _delWt;

        if (m_currentAngle > _PI) m_currentAngle -= _2PI;
        else if (m_currentAngle < -_PI) m_currentAngle += _2PI;
    
        return m_currentAngle;    
    }
    
    
    

}
