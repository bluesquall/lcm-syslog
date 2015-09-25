// lcm-syslog.cpp
//

#include "lcm-syslog.hpp"

LCMSyslog::LCMSyslog(const process_management::process_t &process){
    msg.process = process;
}

LCMSyslog::~LCMSyslog(){}

/*
void LCMSyslog::log(const std::string &text, const int64_t &epoch_usec, const Level level){
    msg.epoch_usec = ( epoch_usec > 0 ? epoch_usec : epoch_usec_now() );
    msg.text = text;
    lcm.publish("syslog.{level}", &msg);
}
*/

void LCMSyslog::critical(const std::string &text, const int64_t &epoch_usec){
    msg.epoch_usec = ( epoch_usec > 0 ? epoch_usec : epoch_usec_now() );
    msg.text = text;
    lcm.publish("syslog.CRITICAL", &msg);
}

void LCMSyslog::fault(const std::string &text, const int64_t &epoch_usec){
    msg.epoch_usec = ( epoch_usec > 0 ? epoch_usec : epoch_usec_now() );
    msg.text = text;
    lcm.publish("syslog.FAULT", &msg);
}

void LCMSyslog::error(const std::string &text, const int64_t &epoch_usec){
    msg.epoch_usec = ( epoch_usec > 0 ? epoch_usec : epoch_usec_now() );
    msg.text = text;
    lcm.publish("syslog.ERROR", &msg);
}

void LCMSyslog::important(const std::string &text, const int64_t &epoch_usec){
    msg.epoch_usec = ( epoch_usec > 0 ? epoch_usec : epoch_usec_now() );
    msg.text = text;
    lcm.publish("syslog.IMPORTANT", &msg);
}

void LCMSyslog::warning(const std::string &text, const int64_t &epoch_usec){
    msg.epoch_usec = ( epoch_usec > 0 ? epoch_usec : epoch_usec_now() );
    msg.text = text;
    lcm.publish("syslog.WARNING", &msg);
}

void LCMSyslog::info(const std::string &text, const int64_t &epoch_usec){
    msg.epoch_usec = ( epoch_usec > 0 ? epoch_usec : epoch_usec_now() );
    msg.text = text;
    lcm.publish("syslog.INFO", &msg);
}

void LCMSyslog::debug(const std::string &text, const int64_t &epoch_usec){
    msg.epoch_usec = ( epoch_usec > 0 ? epoch_usec : epoch_usec_now() );
    msg.text = text;
    lcm.publish("syslog.DEBUG", &msg);
}

