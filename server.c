//tcp server workflow: socket creation-> binding the socket to the ip and port where it is should be listening to-->listening to that addresss and port--> accept the connection-->send or receive data


#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<unistd.h>
#include<errno.h>
#include<arpa/inet.h>

int main(){
    char server_welcome[1000]="Hello from server";
    char client_msg[1000]={0};
    int valread;


    int sendNum=100;
    int conv_num=htonl(sendNum);
    int recv_num=0;
    
    int ssock = socket(AF_INET,SOCK_STREAM,0);
   

   
    struct sockaddr_in server_address;
    server_address.sin_family=AF_INET;
    server_address.sin_port=htons(9001);
    server_address.sin_addr.s_addr=INADDR_ANY;

   
    bind(ssock,(struct sockaddr*)&server_address,sizeof(server_address) );

    listen(ssock,10);
    int client_socket; 
    client_socket=accept(ssock,NULL,NULL); 
  
    //send(client_socket,server_welcome,sizeof(server_welcome),0);
    write(client_socket,&conv_num,sizeof(conv_num));
   // valread=read(client_socket,client_msg,1000);
    valread=read(client_socket,&recv_num,sizeof(recv_num));
    printf("Client's msg :%d\n",ntohl(recv_num));

   
    close(ssock); 
    
    return 0;

}