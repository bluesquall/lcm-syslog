// syslog.cpp
//

#include "syslog.hpp"

Syslog::Syslog(const process_management::process_t &process){
    msg.process = process;
}

Syslog::~Syslog(){}

void Syslog::critical(const std::string &text, const int64_t &timestamp){
    msg.timestamp = ( timestamp > 0 ? timestamp : utime() );
    msg.text = text;
    lcm.publish("syslog.CRITICAL", &msg);
}

void Syslog::fault(const std::string &text, const int64_t &timestamp){
    msg.timestamp = ( timestamp > 0 ? timestamp : utime() );
    msg.text = text;
    lcm.publish("syslog.FAULT", &msg);
}

void Syslog::error(const std::string &text, const int64_t &timestamp){
    msg.timestamp = ( timestamp > 0 ? timestamp : utime() );
    msg.text = text;
    lcm.publish("syslog.ERROR", &msg);
}

void Syslog::important(const std::string &text, const int64_t &timestamp){
    msg.timestamp = ( timestamp > 0 ? timestamp : utime() );
    msg.text = text;
    lcm.publish("syslog.IMPORTANT", &msg);
}

void Syslog::warning(const std::string &text, const int64_t &timestamp){
    msg.timestamp = ( timestamp > 0 ? timestamp : utime() );
    msg.text = text;
    lcm.publish("syslog.WARNING", &msg);
}

void Syslog::info(const std::string &text, const int64_t &timestamp){
    msg.timestamp = ( timestamp > 0 ? timestamp : utime() );
    msg.text = text;
    lcm.publish("syslog.INFO", &msg);
}

void Syslog::debug(const std::string &text, const int64_t &timestamp){
    msg.timestamp = ( timestamp > 0 ? timestamp : utime() );
    msg.text = text;
    lcm.publish("syslog.DEBUG", &msg);
}

