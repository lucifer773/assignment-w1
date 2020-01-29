//tcp client workflow : socket create--> connect--> recv-->close the socket


#include<stdio.h>
#include<stdlib.h>
//for socket functionalities and API to create sockets
#include<sys/socket.h>
#include<sys/types.h>

#include<netinet/in.h> //has a structure which is used to connect to the remote server by using the address and port

int main(){
    //creation of socket 
    int sock= socket(AF_INET,SOCK_STREAM,0); 
    int valread;

    //specify the address to which this socket to be connected

    struct sockaddr_in server_address;
    server_address.sin_family =AF_INET;
    server_address.sin_port = htons(9001);
    server_address.sin_addr.s_addr = INADDR_ANY; 
    //server_address.sin_addr.s_addr= inet_addr("127.0.0.1");

    int con_stats= connect(sock,(struct sockaddr *)&server_address, sizeof(server_address)); 
    if(con_stats==-1){
        printf("unsuccessful connection establishment");
    }
    //receive data from the server
    char server_msg[1000]={0};
    //recv(sock,&server_msg,sizeof(server_msg),0);  
    valread=read(sock,server_msg,1000);
    //print the received data from the server
    printf("Server's response: %s\n",server_msg);
    
    //close the socket
    close(sock);




    return 0;
}
