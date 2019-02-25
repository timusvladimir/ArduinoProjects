#pragma once


#if defined(USE_UAVTALK)
// see https://librepilot.atlassian.net/wiki/display/LPDOC/UavObjects

#include "protocols/UAVTalk.h"

#elif defined(USE_MWII)
#include "protocols/cleanflight.h"

#elif defined(USE_LTM)
#include "protocols/LTM.h"

#elif defined(USE_MAVLINK)
 #include "../GCS_MAVLink/include/mavlink/v1.0/mavlink_types.h"
#else
 #warn "no protocol defined!"
 #define USE_MAVLINK
 #include "../GCS_MAVLink/include/mavlink/v1.0/mavlink_types.h"
#endif

#include "gsm.h"

#define MAVLINK_EXTERNAL_RX_BUFFER 1
#define m_mavlink_message 1


union {
#if defined(USE_MAVLINK)
    mavlink_message_t m;
#endif
#if defined(USE_UAVTALK)
    uavtalk_message_t u;
#endif
#if defined(USE_MWII)
    MWII_buffer mwii;
#endif
#if defined(USE_LTM)
    LTM ltm;
#endif
    char response[RESPONCE_LENGTH];

} msg;



#if defined(USE_MAVLINK)
#define  m_mavlink_buffer (&msg.m)
#include "../GCS_MAVLink/GCS_MAVLink.h"
#include "protocols/MAVLink.h"
#endif
