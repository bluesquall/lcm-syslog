#!/usr/bin/env python

import os
import time

import lcm

import process_management

class LCMSyslog:

    def __init__(self, process, lio=lcm.LCM()):
        self.lio = lio
        self.msg = process_management.syslog_t()
        self.msg.process = process

    def log(self, text, level='DEBUG', timestamp=None):
        if timestamp is None:
            self.msg.timestamp = int(time.time() * 1e6)
        else:
            self.msg.timestamp = timestamp
        self.msg.text = text
        self.lio.publish('syslog.{0}'.format(level), self.msg.encode())

    def critical(self, text, timestamp=None):
        self.log(text, 'CRITICAL', timestamp)

    def fault(self, text, timestamp=None):
        self.log(text, 'FAULT', timestamp)

    def error(self, text, timestamp=None):
        self.log(text, 'ERROR', timestamp)

    def important(self, text, timestamp=None):
        self.log(text, 'IMPORTANT', timestamp)

    def warning(self, text, timestamp=None):
        self.log(text, 'WARNING', timestamp)

    def info(self, text, timestamp=None):
        self.log(text, 'INFO', timestamp)

    def debug(self, text, timestamp=None):
        self.log(text, 'DEBUG', timestamp)


if __name__ == '__main__': # run a test
    process = process_management.process_t()
    process.name = 'lcm-syslog.py'
    process.id = os.getpid()
    print('PID: {0}'.format(process.id))
    log = LCMSyslog(process)
    for i in range(10):
        log.critical('This is syslog entry {0} at the CRITICAL level.'.format(i))
        log.fault('This is syslog entry {0} at the FAULT level.'.format(i))
        log.error('This is syslog entry {0} at the ERROR level.'.format(i))
        log.important('This is syslog entry {0} at the IMPORTANT level.'.format(i))
        log.warning('This is syslog entry {0} at the WARNING level.'.format(i))
        log.info('This is syslog entry {0} at the INFO level.'.format(i))
        log.debug('This is syslog entry {0} at the DEBUG level.'.format(i))
        time.sleep(1)
