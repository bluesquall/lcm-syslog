#!/usr/bin/env python

import os
import time

try:
    import lcm
except ImportError as e:
    print('Could not import LCM')
    print('If you are working in a venv, try cloning upstream and then:\n')
    print('\tpip install -e ~/path/to/lcm/lcm-python\n')
    raise e

import process_management

class LCMSyslog:

    def __init__(self, process, lio=lcm.LCM()):
        self.lio = lio
        self.msg = process_management.syslog_t()
        self.msg.process = process

    def log(self, text, level='DEBUG', epoch_usec=None):
        if epoch_usec is None:
            self.msg.epoch_usec = int(time.time() * 1e6)
        else:
            self.msg.epoch_usec = epoch_usec
        self.msg.text = text
        self.lio.publish('syslog.{0}'.format(level), self.msg.encode())

    def critical(self, text, epoch_usec=None):
        self.log(text, 'CRITICAL', epoch_usec)

    def fault(self, text, epoch_usec=None):
        self.log(text, 'FAULT', epoch_usec)

    def error(self, text, epoch_usec=None):
        self.log(text, 'ERROR', epoch_usec)

    def important(self, text, epoch_usec=None):
        self.log(text, 'IMPORTANT', epoch_usec)

    def warning(self, text, epoch_usec=None):
        self.log(text, 'WARNING', epoch_usec)

    def info(self, text, epoch_usec=None):
        self.log(text, 'INFO', epoch_usec)

    def debug(self, text, epoch_usec=None):
        self.log(text, 'DEBUG', epoch_usec)


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
