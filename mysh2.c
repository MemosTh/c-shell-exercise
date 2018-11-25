#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>





int main(int argc, char **argv)
{
 


 

  char buffer[500];
  char ext[10];
  char cd[5];
  strcpy(ext,"exit");
  strcpy(cd,"cd");
  
  

   do{
	#define BUFSIZE 64
	#define DELIM " " " \t\r\n\a" 
	int bufsize = BUFSIZE, position = 0;
	char **words = malloc(bufsize * sizeof(char*));
	char *word;
	pid_t pid, wpid;
	int status;
	


	printf("$ ");
	fgets(buffer, 500 ,stdin);

	word = strtok(buffer,DELIM);

	while (word != NULL) {
	    words[position] = word;
	    position++;

	    if (position >= bufsize) {
	      bufsize += BUFSIZE;
	      words = realloc(words, bufsize * sizeof(char*));
	      if (!words) {
	        fprintf(stderr, " allocation error\n");
	        exit(EXIT_FAILURE);
	      }
	    }

	    word = strtok(NULL, DELIM);
	  }
if(position==0){
    words[position] ="no character";

	  
 }else words[position] = NULL;
 
  
  pid = fork();
  
 
  if (pid == 0) {
     
    execvp(words[0], words);
      
    
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    
    
  } else {
   


 if (strcmp(words[0],cd) == 0){

   if(words[1]==NULL){
	chdir(getenv("HOME"));
  
   } else chdir(words[1]);
      
    
   
}

     pid = wait(&status);

    
      
    }

    
  }while (strcmp(buffer,ext) != 0);

  
  

  

  return 0;
	
}
