//tcp client workflow : socket create--> connect--> recv-->close the socket


#include<stdio.h>
#include<stdlib.h>
//for socket functionalities and API to create sockets
#include<sys/socket.h>
#include<sys/types.h>

#include<netinet/in.h> //has a structure which is used to connect to the remote server by using the address and port


/*struct client_packet{
    char msg[1000];
    int mtu;
};*/

int main(){
    //struct client_packet cobj,recv_obj;

     char client_welcome[1000] ="hello from client";
     char server_msg[1000]={0};
     
     //int valread;
    
    int sock= socket(AF_INET,SOCK_STREAM,0); 


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
    
    //valread=read(sock,server_msg,1000);
    recv(sock,&server_msg,sizeof(server_msg),0); //second param is address of the char array to which the server sending message is going to be stored.. 4th param is optional flag, which is set to 0
    
    //print the received data from the server
    printf("Server's response: %s\n",server_msg);

  //  send(sock,client_welcome,sizeof(client_welcome),0);
    


   

    

    
    //close the socket
    // close(sock); 




    return 0;
}



    