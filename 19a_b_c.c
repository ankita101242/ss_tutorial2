
=======================================================================================================
Name : 19a_b_c.c
Author : Ankita Agrawal
Description : Create a FIFO file by
	      a. mknod command
	      b. mkfifo command
	      c. use strace command to find out, which command (mknod or mkfifo) is better.
Date: 17 Oct 2023
======================================================================================================

a) 
Run in terminal:
mknod myfifo p (p is for pipe)

b)
mkfifo fifo

c)
strace mknod  myfifo
strace mkfifo fifo

