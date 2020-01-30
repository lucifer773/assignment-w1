//tcp server workflow: socket creation-> binding the socket to the ip and port where it is should be listening to-->listening to that addresss and port--> accept the connection-->send or receive data


#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<unistd.h>
#include<errno.h>
#include<arpa/inet.h>

struct packet{
    char *msg;
    int mtu;
};
int main(){
    
    char client_msg[1000]={0};
    int valread;
    char buff[1024];
    
    long int packet_size;
    struct packet pkt;
   
    pkt.mtu=100;
    
    int ssock = socket(AF_INET,SOCK_STREAM,0);
   

   
    struct sockaddr_in server_address;
    server_address.sin_family=AF_INET;
    server_address.sin_port=htons(9001);
    server_address.sin_addr.s_addr=INADDR_ANY;

   
    bind(ssock,(struct sockaddr*)&server_address,sizeof(server_address) );

    listen(ssock,10);
    int client_socket; 
    client_socket=accept(ssock,NULL,NULL); 
  
   valread=read(client_socket,client_msg,1000);
   printf("Client's msg: %s\n",client_msg);
   
    send(client_socket,(void*)&pkt,sizeof(pkt),0);
    
   
    close(ssock); 
    
    return 0;

}