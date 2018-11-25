#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

  



void execpipes(char*** piped_commands, int no_of_pipes_left){


int status;
pid_t wpid;

    
    if (no_of_pipes_left < 0)
    {
     return;   
    }

 
    int fds[2];
    pipe(fds);
    int pid = fork();
    if (pid == 0)
    {
        
        close(1);
        dup(fds[1]);
        close(fds[0]);
        execpipes(piped_commands, no_of_pipes_left - 1);
        close(fds[1]);
        execvp(piped_commands[no_of_pipes_left - 1][0], piped_commands[no_of_pipes_left - 1]);

 
    }
    else if (pid > 0)
    {


       do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    
        if (no_of_pipes_left > 0)
        {
            close(0);
            dup(fds[0]);
        }
        close(fds[1]);
        wait(NULL);
        close(fds[0]);
        execvp(piped_commands[no_of_pipes_left][0], piped_commands[no_of_pipes_left]);
      
    }


do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));


    
} 

int main(int argc, char **argv)
{
 


 

  char buffer[500];
  char buffer2[500];
  char ext[10];
  char cd[5];
  strcpy(ext,"exit");
  strcpy(cd,"cd");
  
  

   do{

	
	#define BUFSIZE 64
	#define BUFSIZE2 64
	#define DELIM " \t\r\n\a" 
	int bufsize = BUFSIZE, position = 0,position2 = 0;
	int bufsize2 = BUFSIZE2; 
     char **words = malloc(bufsize * sizeof(char*));
     
	char *word;
	
	pid_t pid, wpid;
	int status;
      char *line;
	const char *i="|";
	char *buffer2;
 	char*** piped_commands = (char*** )malloc(5 * sizeof(char**));
	int k = 0;
	int o,j=0;


	printf("$ ");
	fgets(buffer, 500 ,stdin);
        line=buffer;
 
    if (strstr(line,i) != NULL){ //an vrw sthn entoli pipe 
  
     

  word = strtok(buffer, DELIM);
  while (word != NULL) {
    words[position] = word;
    position++;

    if (position >= bufsize) {
      bufsize += BUFSIZE;
      words = realloc(words, bufsize * sizeof(char*));
      if (!words) {
        
        exit(EXIT_FAILURE);
      }
    }

    word = strtok(NULL, DELIM);
  }
  if(position==0){
    words[position] ="no character";

	  
 }else words[position] = NULL;

    
  


    piped_commands[k] = (char** ) malloc(20 * sizeof(char*));
 
    for (o = 0; words[o] != NULL; o++) 
    {
        if (strcmp(words[o], "|") == 0)
        {
            k++;
            j=0;
            piped_commands[k] = (char** ) malloc(20 * sizeof(char*));
        }
        else
        {
            piped_commands[k][j] = (char* )malloc(100 *sizeof(char));
            strcpy(piped_commands[k][j], words[o]);
            j++;
        }
    }


int nofpcom = k;

    if (fork()==0) {
       
	

execpipes(piped_commands,nofpcom); //kalw thn execpipe
pid = wait(&status);
     

}else  {


pid = wait(&status);

}



} else { //an den vrw pipe sthn entoli


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
    // Error forking
    
  } else {
    // Parent process


 if (strcmp(words[0],cd) == 0){
  
    

   if(words[1]==NULL){
	chdir(getenv("HOME"));
  
   } else chdir(words[1]);
}

       do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    
      
    }

}    
  }while (strcmp(buffer,ext) != 0);

  
  

  

  return 0;
	
}
