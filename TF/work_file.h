
#include <cstdint>
#include "iqmath.h"

namespace user{
    extern const float _PI;
    extern const float _2PI;
    extern const float FREQ;
    extern const float W;

    void wt_sat(iq_t& _wt);
    
    extern iq_t m_currentAngle;
    
    iq_t angle_est(iq_t _W, iq_t _Ts);

}