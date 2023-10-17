/*
============================================================================
Name : 18.c
Author : Ankita Agrawal
Description :  Write a program to find out total number of directories on the pwd.
 execute ls -l | grep ^d | wc ? Use only dup2.
Date: 17 oct, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
int main() {
	int fd1[2], fd2[2];
	pipe(fd1);
	pipe(fd2);// This child will only be used for writing output of "ls -Rl" to pipe 1 write-end = STDOUT
	if (!fork()) {
		dup2(fd1[1], 1); // Write-end of pipe 1 = new STDOUT
		close(fd1[0]);
		close(fd2[0]);
		close(fd2[1]);
		execlp("ls", "ls", "-l", (char*) NULL);
	}
	else {
		if (!fork()) {
			dup2(fd2[1], 1);
			dup2(fd1[0], 0);
			close(fd1[1]);
			close(fd2[0]);
			execlp("grep", "grep", "^d", (char*) NULL);
		}
		else {
			dup2(fd2[0], 0);
			close(fd2[1]);
			close(fd1[0]);
			close(fd1[1]);
			execlp("wc", "wc", (char*) NULL);
		}
	}
	return 0;
}
