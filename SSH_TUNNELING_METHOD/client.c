#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
int main()
{
	int c_sock;
	char buf[512],other[512];
	c_sock=socket(AF_INET,SOCK_STREAM,0);
	if(c_sock < 0)
		printf("Error in opening socket\n");
	struct sockaddr_in client;
	memset(&client,0,sizeof(client));
	client.sin_family=AF_INET;
	client.sin_port=htons(9009);
	client.sin_addr.s_addr= INADDR_ANY;
	if(connect(c_sock,(struct sockaddr*)&client,sizeof(client))== -1)
	{
		printf("Connection error\n");
		exit(1);
	}
	printf("Hey! Client online.\n");
	recv(c_sock,buf,sizeof(buf),0);
	printf("%s\n",buf);
	printf("Enter 'end' to exit the conversation\n\n");
	while(1)
	{
		printf("Enter message to server : ");
		gets(buf);
		send(c_sock,buf,sizeof(buf),0);
		if(strcmp(buf,"end")==0)
			break;
		bzero(&buf, sizeof(buf));
		recv(c_sock,other,sizeof(other),0);
		printf("Reply from server : %s \n",other );
	}
	close(c_sock);
	return 0;
}

