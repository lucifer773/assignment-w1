//tcp server workflow: socket creation-> binding the socket to the ip and port where it is should be listening to-->listening to that addresss and port--> accept the connection-->send or receive data


#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<unistd.h>
#include<errno.h>

int main(){
    char server_welcome[1000]="Hello from server";
    char client_msg[1000]={0};
    int valread;
    
    int ssock = socket(AF_INET,SOCK_STREAM,0);
   

   
    struct sockaddr_in server_address;
    server_address.sin_family=AF_INET;
    server_address.sin_port=htons(9001);
    server_address.sin_addr.s_addr=INADDR_ANY;

   
    bind(ssock,(struct sockaddr*)&server_address,sizeof(server_address) );

    listen(ssock,10);
    int client_socket; 
    client_socket=accept(ssock,NULL,NULL); 
  
    send(client_socket,server_welcome,sizeof(server_welcome),0);
    valread=read(client_socket,client_msg,1000);

    printf("Client's response: %s ret %d\n",client_msg, valread);

   
    close(ssock); 
    
    return 0;

}