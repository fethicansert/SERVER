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
		printf("%s %s",name,password);	
		
		while(fgets(line,100,file)!=NULL)
    	{
    		
    		sp=strtok(line,":");
    		strcpy(t_name,sp);
    		sp=strtok(NULL," ");
    		strcpy(t_password,sp);
    		
    		
    		
    		
    
		}
		

	}
	else if(strcmp(command,"QUIT")==0)
	{
		printf("TRUE COMMAND");
	}
	
	

	
}

