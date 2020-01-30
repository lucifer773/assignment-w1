//tcp client workflow : socket create--> connect--> recv-->close the socket


#include<stdio.h>
#include<stdlib.h>

#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<limits.h>
#include<netinet/in.h> 

struct packet{
    char *msg;
    int mtu;
};

int main(){
    
    int sock= socket(AF_INET,SOCK_STREAM,0); 
    int valread;
    char client_welcome[1000]="Hello from client.Send me the MTU";
    char server_msg[1000]={0};
    char *r_msg;
    int r_mtu=0;

    
    int i;
    int mtuC=15;
    
    char buff[1024];
    struct packet pkt;


    struct sockaddr_in server_address;
    server_address.sin_family =AF_INET;
    server_address.sin_port = htons(9001);
    server_address.sin_addr.s_addr = INADDR_ANY; 
    

    int con_stats= connect(sock,(struct sockaddr *)&server_address, sizeof(server_address)); 
    if(con_stats==-1){
        printf("unsuccessful connection establishment");
    }
    send(sock,client_welcome,sizeof(client_welcome),0);
    if(recv(sock,(struct packet *)&pkt,2048,0)<0){
        printf("Error in receivinng packet");
    }else{
        
        printf("MTU value of Server is %d",pkt.mtu);

    }


     
    
    int mtu1[2];
    mtu1[0]=mtuC;
    mtu1[1]=pkt.mtu;
    
    int pmtu=INT_MIN;
    

    if(mtu1[0]<mtu1[1]){
        pmtu=mtu1[0];

    }
    else{
        pmtu=mtu1[1];
    }
    printf("Path mtu is %d",pmtu);
    
   
  
    close(sock);




    return 0;
}