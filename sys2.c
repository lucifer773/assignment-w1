//tcp server workflow: socket creation-> binding the socket to the ip and port where it is should be listening to-->listening to that addresss and port--> accept the connection-->send or receive data


#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>

/*struct serv_packet{
    char msg[1000];
    int mtu;
};*/

int main(){
    //struct serv_packet sobj,recv_obj;
    //obj1.msg="hello from server";
    //obj1.mtu=1234;
   // int client_mtu=0;
    int valread;
    char server_welcome[1000]="Hello from Server";
    char client_msg[1000]={0};
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
    //valread=read(client_socket,client_msg,1000);
    // recv(ssock,&client_msg,sizeof(client_msg),0);



    

    
    //recv(ssock,&client_mtu,sizeof(client_mtu),0);
    printf("The client's response: %s\n",client_msg);
    //close the socket
    // close(ssock); 
    
    return 0;

}