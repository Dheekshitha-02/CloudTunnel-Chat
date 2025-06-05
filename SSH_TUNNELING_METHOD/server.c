#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
int main()
{
	int s_sock,c_sock;
	char buf[200]="Connecting people:\n>>>Sathwika\n>>>Harini\n>>>Tejashree\n>>>Kavya\n>>>Dheekshitha\n>>>Sanjana\n";	
	char other[512],buf1[512]="\0";	
	s_sock=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in server,client;
	memset(&server,0,sizeof(server));
	memset(&client,0,sizeof(client));
	server.sin_family = AF_INET;
	server.sin_port = htons(9009);
	server.sin_addr.s_addr = INADDR_ANY;
	if(bind(s_sock,(struct sockaddr*)&server , sizeof(server)) ==-1)
	{
		printf("Error in bind\n");
		exit(1);
	}
	printf("Server running, presence of client online is requested!\n\n");
	socklen_t add;
	add = sizeof(client);
	listen(s_sock,100);
	c_sock=accept(s_sock, (struct sockaddr*)&client, &add);
	send(c_sock,buf,sizeof(buf),0);
	while(1)
	{
		recv(c_sock,buf1,sizeof(buf1),0);
		printf("Reply from client : %s \n",buf1);
		printf("Enter message to client : ");
		gets(other);
		if(strcmp(other,"end")==0)
		{
	 		break;
		}
		send(c_sock,other,sizeof(other),0);
		bzero(&other, sizeof(other));
	}
	close(s_sock);
	return 0;
}


