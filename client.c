//tcp client workflow : socket create--> connect--> recv-->close the socket


#include<stdio.h>
#include<stdlib.h>

#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<limits.h>
#include<netinet/in.h> 

int main(){
    
    int sock= socket(AF_INET,SOCK_STREAM,0); 
    int valread;
    char client_welcome[1000]="Hello from client";
    char server_msg[1000]={0};

    int recv_num=0;
    int i;
    int mtu=15;
    //int conv_num=htonl(send_num);



    struct sockaddr_in server_address;
    server_address.sin_family =AF_INET;
    server_address.sin_port = htons(9001);
    server_address.sin_addr.s_addr = INADDR_ANY; 
    

    int con_stats= connect(sock,(struct sockaddr *)&server_address, sizeof(server_address)); 
    if(con_stats==-1){
        printf("unsuccessful connection establishment");
    }
    
     
    //valread=read(sock,server_msg,1000);
    valread=read(sock,&recv_num,sizeof(recv_num));
    printf("Server's msg: %d",ntohl(recv_num));
    int mtu1[2];
    mtu1[0]=mtu;
    mtu1[1]=ntohl(recv_num);
    int pmtu=INT_MIN;
    //for(i=0;i<2;i++){
      //  printf("%d\t",mtu1[i]);
    //}

    if(mtu1[0]<mtu1[1]){
        pmtu=mtu1[0];

    }
    else{
        pmtu=mtu1[1];
    }
    printf("Path mtu is %d",pmtu);
    
    //printf("Server's response: %s\n",server_msg);
   // send(sock,client_welcome,sizeof(client_welcome),0);
   // write(sock,&conv_num,sizeof(conv_num));

  
    close(sock);




    return 0;
}
