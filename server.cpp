#include <iostream>
#include <stdio.h>
#include <string.h>
#include <dirent.h> 



using namespace std;

int main()
{
	char commandline[21];
	char line[100];
	char command[10];
	char name[21];
	char name1[21];
	char password[21];
	char t_name[21];
	char t_password[21];
	bool enter=false;
	char *sp;
	FILE *file;
	file=fopen("12.txt","r");
	


	
	
	printf("HELLO WELCOME THE FETHI's SERVER \n ");
	while(1)
	{
		

	
	
    gets(commandline);
    printf("%s\n",commandline);
     //scanf("%20[^\n]",&commandline); //%20[^\n]
	sp=strtok(commandline," ");
	printf("%s\n",commandline);
	strcpy(command,sp);
	printf("%s\n",command);
	if(strcmp(command,"USER")==0)
	{
		sp=strtok(NULL," ");
		strcpy(name,sp);
		sp=strtok(NULL," ");
		strcpy(password,sp);
		
		while(fgets(line,100,file)!=NULL)
    	{
    		
    		sp=strtok(line,":");
    		strcpy(t_name,sp);
    		sp=strtok(NULL,"\n");
    		strcpy(t_password,sp);
    		
    		//printf("%s %s %s %s",name,password,t_name,t_password);
    		//&& strcmp(password,t_password)==0
    		//   strcmp(name,t_name)==0
    		
    		if(strcmp(password,t_password)==0 && strcmp(name,t_name)==0)
    		{
    			
    			char name1[200];
    			memset(&name1,'\0',sizeof(name1));
    			sprintf(name1,"200 USER %s to access. \n",name1);
    			send(fd,name1,200,0)
    			break;
    			
			}
			
    	
		}
		
		
			
								
	}
	else if(strcmp(command,"QUIT")==0)
	{
		printf("SERVER CLOSING");
	}
	else
	{
		
		printf("WRONG COMMAND\n");
	}
	if(enter)
	{
		 scanf("%s",&name1);
		 if(strcmp(name1,"LIST")==0)
		 {
		 DIR *d;
         struct dirent *dir;
         d = opendir(".");
         if (d) {
                  while ((dir = readdir(d)) != NULL) {
                  printf("%s\n", dir->d_name);
               }
                  closedir(d);
               }
		
	}
	
}
		
}
	
}


