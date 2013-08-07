inode-ctime
===========

Demo of altering inode ctime in-kernel.

The touch command can't alter the ctime of an inode. There are
methods such as altering the system clock or using debugfs that
allow the ctime to be altered, this kernel module is another way. 

This is a proof of concept rather than a finished tool! 
