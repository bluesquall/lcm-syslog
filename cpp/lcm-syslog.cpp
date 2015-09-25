// lcm-syslog.cpp
//

#include "lcm-syslog.hpp"

LCMSyslog::LCMSyslog(const process_management::process_t &process){
    msg.process = process;
}

LCMSyslog::~LCMSyslog(){}

/*
void LCMSyslog::log(const std::string &text, const int64_t &timestamp, const Level level){
    msg.timestamp = ( timestamp > 0 ? timestamp : epoch_usec() );
    msg.text = text;
    lcm.publish("syslog.{level}", &msg);
}
*/

void LCMSyslog::critical(const std::string &text, const int64_t &timestamp){
    msg.timestamp = ( timestamp > 0 ? timestamp : epoch_usec() );
    msg.text = text;
    lcm.publish("syslog.CRITICAL", &msg);
}

void LCMSyslog::fault(const std::string &text, const int64_t &timestamp){
    msg.timestamp = ( timestamp > 0 ? timestamp : epoch_usec() );
    msg.text = text;
    lcm.publish("syslog.FAULT", &msg);
}

void LCMSyslog::error(const std::string &text, const int64_t &timestamp){
    msg.timestamp = ( timestamp > 0 ? timestamp : epoch_usec() );
    msg.text = text;
    lcm.publish("syslog.ERROR", &msg);
}

void LCMSyslog::important(const std::string &text, const int64_t &timestamp){
    msg.timestamp = ( timestamp > 0 ? timestamp : epoch_usec() );
    msg.text = text;
    lcm.publish("syslog.IMPORTANT", &msg);
}

void LCMSyslog::warning(const std::string &text, const int64_t &timestamp){
    msg.timestamp = ( timestamp > 0 ? timestamp : epoch_usec() );
    msg.text = text;
    lcm.publish("syslog.WARNING", &msg);
}

void LCMSyslog::info(const std::string &text, const int64_t &timestamp){
    msg.timestamp = ( timestamp > 0 ? timestamp : epoch_usec() );
    msg.text = text;
    lcm.publish("syslog.INFO", &msg);
}

void LCMSyslog::debug(const std::string &text, const int64_t &timestamp){
    msg.timestamp = ( timestamp > 0 ? timestamp : epoch_usec() );
    msg.text = text;
    lcm.publish("syslog.DEBUG", &msg);
}

