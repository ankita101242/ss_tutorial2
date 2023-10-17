/*
============================================================================
Name : 19d.c
Author : Ankita Agrawal
Description : Create a FIFO file by
 a. mknod command
 b. mkfifo command
 c. use strace command to find out, which command (mknod or mkfifo) is better.
 c. mknod system call
 d. mkfifo library function
Date: 17 oct, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
int main(void){
	int f = mknod("FIFO", S_IFIFO, 0);
	if(f<0){
		perror("Failed");
	}
	close(f);
}
