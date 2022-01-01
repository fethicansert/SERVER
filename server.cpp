#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;

int main()
{
	
	
	char commandline[21];
	char line[100];
	char command[10];
	char name[21];
	char password[21];
	char t_name[21];
	char t_password[21];
	char *sp;
	FILE *file;
	file=fopen("12.txt","r");
	printf("Enter Command : ");
    scanf("%20[^\n]",&commandline);
	sp=strtok(commandline," ");
	strcpy(command,sp);
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
    		sp=strtok(NULL,"\t");
    		strcpy(t_password,sp);
    		
    		
    		if(strcmp(name,t_name)==0 && strcmp(password,t_password))
    		{
		
    			
    			printf("200  User %s  has grated to access",name);
    			break;
			}
    		
    		
    
		}
		

	}
	else if(strcmp(command,"QUIT")==0)
	{
		printf("TRUE COMMAND");
	}
	
	

	
}

