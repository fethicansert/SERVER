/*
  This code represent basic TCP Echo Server. It's used to teach how basic server  running.
For compile code : # gcc prog.name.c -o execfile
  -----------------------Copyright Devrim Seral---------------------------------
*/
/* C header files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <stdbool.h>
#include <dirent.h>
#include <sys/stat.h>
/* Socket API headers */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/* Definitions */
#define DEFAULT_BUFLEN 512
#define PORT 8080

int main()
{
int gul_counter=1;
bool usercommand=false;	
bool enter;
FILE *file;
char *sp;
char command[100];
char name[100];
char password[100];
char t_name[100];
char t_password[100];
char line[100];
char line2[100];
int size;
int server, client;
struct sockaddr_in local_addr;
struct sockaddr_in remote_addr;
int length,fd,rcnt,optval;
char recvbuf[DEFAULT_BUFLEN],bmsg[DEFAULT_BUFLEN];
int  recvbuflen = DEFAULT_BUFLEN;



/* Open socket descriptor */
if ( (server = socket( AF_INET, SOCK_STREAM, 0 )) < 0) {
    perror("Can't create socket!");
    return(1);
}

/* Fill local and remote address structure with zero */
memset( &local_addr, 0, sizeof(local_addr) );
memset( &remote_addr, 0, sizeof(remote_addr) );

/* Set values to local_addr structure */
local_addr.sin_family = AF_INET;
local_addr.sin_addr.s_addr = htonl(INADDR_ANY);
local_addr.sin_port = htons(PORT);

// set SO_REUSEADDR on a socket to true (1):
optval = 1;
setsockopt(server, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof optval);


if ( bind( server, (struct sockaddr *)&local_addr, sizeof(local_addr) ) < 0 )
{
    /* could not start server */
    perror("Bind problem!");
    return(1);
}

if ( listen( server, SOMAXCONN ) < 0 ) {
        perror("Listen");
        exit(1);
}

printf("First socket server now starting!\n");
printf("Wait for connection\n");

while(1) {  // main accept() loop
    length = sizeof remote_addr;
    if ((fd = accept(server, (struct sockaddr *)&remote_addr, \
          &length)) == -1) {
          perror("Accept Problem!");
          continue;
    }

    printf("Server: got connection from %s\n", \
            inet_ntoa(remote_addr.sin_addr));
    char welcome[200]="HELLO WELCOME THE GULLURİ SERVER\n";
    send(fd,welcome,200,0);
 
 

    // Receive until the peer shuts down the connection
    do {
        // Clear Receive buffer
        memset( &recvbuf, '\0', sizeof(recvbuf) );
        rcnt = recv(fd, recvbuf, recvbuflen, 0);
	sp=strtok(recvbuf," ");
	strcpy(command,sp);
	if(usercommand)
	{
		if(strcmp(command,"LIST\n")==0)
		{

			DIR *d;
			struct dirent *dir;
			d=opendir(".");
			if(d){
				while((dir=readdir(d)) != NULL){
					char files[300];
					memset(&files,'\0',sizeof(files));;
					struct stat st;
					stat(dir->d_name,&st);
					size=st.st_size;
			                sprintf(files,"%s %d \n",dir->d_name,size);
					
					send(fd,files,300,0);
				}
				closedir(d);
			
			
			}
			
		
		
		}else if(strcmp(command,"QUIT\n")==0)
		{
			char quit[30]="GOODBYE!!!\n";
			send(fd,quit,30,0);
			close(fd);
			break;
		
		
		}else if(strcmp(command,"DEL")==0)

		{
			sp=strtok(NULL,"\n");
			char delete[100];
			if(remove(sp)==0){
				memset(&delete,'\0',sizeof(delete));
				sprintf(delete,"200 File %s deleted \n",sp);
				send(fd,delete,100,0);

			}else{
				memset(&delete,'\0',sizeof(delete));
				sprintf(delete,"400 File %s is not on the sever.\n",sp);
				send(fd,delete,100,0);
			
			}
		
		
		
		}
	
	
	}
	else if(strcmp(command,"USER")==0)
	{      
	       	
		sp=strtok(NULL," ");
		strcpy(name,sp);
		sp=strtok(NULL,"\n");
		strcpy(password,sp);
		file=fopen("password.txt","r");
		enter=true;

		while(fgets(line,100,file)!=NULL)
		{

			sp=strtok(line,":");
			strcpy(t_name,sp);
			sp=strtok(NULL,"\n");
			strcpy(t_password,sp);
			
			if(strcmp(t_name,name)==0 && strcmp(t_password,password)==0)
			{       
				char name1[200];
				memset(&name1,'\0',sizeof(name1));
				sprintf(name1,"200 USER %s to access. \n",name);
				send(fd,name1,200,0);
				enter=false;
				usercommand=true;
				break;
			
			}
		
			
			
			}
		if(enter){
			char ermsg[200]="WRONG NAME OR PASSWORD\n";
			send(fd,ermsg,200,0);
			
		}
		
		
		         fclose(file);
		

		
		
	
	
          }else if(strcmp(command,"QUIT\n")==0)
	  {
		  char quit[100]="GOODBYE\n";
		  send(fd,quit,100,0);
		  close(fd);
		  break;
		  
	  
	  
	  
	  
	  }else if(strcmp(command,"\n")==0){
		  char gul[200];
		  memset(&gul,'\0',sizeof(gul));
		  sprintf(gul,"%d. GULLURİ\n",gul_counter);
		  send(fd,gul,200,0);
		  gul_counter++;
	  
	  }
 		
		
		
	    	 

        // Echo the buffer back to the sender
        
            
                
                
                
   
        
    } while (rcnt>0);

}

// Final Cleanup
close(server);

}
