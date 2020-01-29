//tcp client workflow : socket create--> connect--> recv-->close the socket


#include<stdio.h>
#include<stdlib.h>

#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>

#include<netinet/in.h> 

int main(){
    
    int sock= socket(AF_INET,SOCK_STREAM,0); 
    int valread;
    char client_welcome[1000]="Hello from client";
    char server_msg[1000]={0};



    struct sockaddr_in server_address;
    server_address.sin_family =AF_INET;
    server_address.sin_port = htons(9001);
    server_address.sin_addr.s_addr = INADDR_ANY; 
    

    int con_stats= connect(sock,(struct sockaddr *)&server_address, sizeof(server_address)); 
    if(con_stats==-1){
        printf("unsuccessful connection establishment");
    }
    
     
    valread=read(sock,server_msg,1000);
    
    printf("Server's response: %s\n",server_msg);
    send(sock,client_welcome,sizeof(client_welcome),0);
    
  
    close(sock);




    return 0;
}
