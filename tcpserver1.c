//tcp server workflow: socket creation-> binding the socket to the ip and port where it is should be listening to-->listening to that addresss and port--> accept the connection-->send or receive data


#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>

int main(){
    char server_welcome[1000]="successfully connected to the server";
    //Creation of socket in server
    int ssock = socket(AF_INET,SOCK_STREAM,0);
   

    //define the server address
    struct sockaddr_in server_address;
    server_address.sin_family=AF_INET;
    server_address.sin_port=htons(9001);
    server_address.sin_addr.s_addr=INADDR_ANY;

    //bind the socket
    bind(ssock,(struct sockaddr*)&server_address,sizeof(server_address) );

    //listen for the connections
    listen(ssock,10);
    int client_socket; 
    client_socket=accept(ssock,NULL,NULL); 
    //send message to the client
    send(client_socket,server_welcome,sizeof(server_welcome),0);
    //close the socket
    close(ssock); 
    
    return 0;

}