/*
============================================================================
Name : 20w.c
Author : Ankita Agrawal
Description : Write two programs so that both can communicate by FIFO -Use one way communication
Date: 17 oct, 2023.
============================================================================
*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/stat.h>
int main(){
	int res,n;
	char buff[100];
	res=open("myfifo",O_WRONLY);
	printf("Enter the text: ");
        scanf("%[^\n]",buff);
	write(res,&buff,sizeof(buff));
}
