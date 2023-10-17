/*
============================================================================
Name : 20r.c
Author : Ankita Agrawal
Description : Write two programs so that both can communicate by FIFO -Use one way communication
Date: 17 oct, 2023.
============================================================================
*/
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
int main()
{
	int res,n;
	char buff[100];
	res=open("myfifo",O_RDONLY);
	read(res,&buff,sizeof(buff));
	printf("The text from fifo file: %s\n",buff);

}

