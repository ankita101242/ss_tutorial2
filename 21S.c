/*
============================================================================
Name : 21S.c
Author : Ankita Agrawal
Description : Write two programs so that both can communicate by FIFO -Use two way communications.
Date: 17 oct, 2023.
============================================================================
*/
nclude <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
        
	remove("myfifo_client");
        remove("myfifo_server");
	//create clientFIFO for sending data from client to server
	int ret = mknod("myfifo_client",S_IFIFO|0666,0);
	if(ret==-1)
	{
		perror("Error in client_fifo creation \n");
		return -1;
	}
	//create serverFIFO for sending data from server to client
	int ret1 = mknod("myfifo_server",S_IFIFO|0666,0);
	if(ret1==-1)
	{
		perror("Error in server_fifo creation\n");
		return -1;
	}
	/////////////////////////////////////////////////////////////////////////////

	//open clientFIFO for writing
	int fp_client = open("myfifo_client",O_WRONLY);
	if(fp_client==-1)
	{
		perror("OPEN CLIENTFIFO ERROR");
		return -1;
	}
	char msg[]="Hello client!! \n";
	//write to clientFIFO
	write(fp_client,msg,strlen(msg));
	printf("Message sent to client \n");
	close(fp_client);
	
	///////////////////////////////////////////////////////////////////////////////////////////////

	//open serverFIFO for reading
	int fp_server = open("myfifo_server",O_RDONLY);
	if(fp_server==-1)
	{
		perror("OPEN SERVERFIFO ERROR");
		return -1;
	}
	char readbuf[100];
	//read from serverFIFO
	read(fp_server,readbuf,sizeof(readbuf));

	close(fp_server);

	return 0;

}
