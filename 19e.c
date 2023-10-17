/*
============================================================================
Name : 19e.c
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
#include<fcntl.h>
#include<sys/stat.h>
int main(void){
	int f = mkfifo("myfifo", 0666);
	if(f<0){
		perror("Failed:");
	}
	else
		printf("File Created.\n");
	close(f);
}
