#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

void execpipe(char **words, char **words2){
 int pfds[2];
 int status;
  pid_t pid, wpid;
    pipe(pfds);
   
 if (fork()==0) {
       
	
	close(pfds[0]);     
        dup2(pfds[1], 1);
        close(pfds[1]);
        
        execvp(words[0], words);
	
    exit(EXIT_FAILURE);
    } 


     

else  {

      
 
        close(pfds[1]);     
        dup2(pfds[0], 0);
        close(pfds[0]);
        
        execvp(words2[0], words2);

}


   
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
        char **words2 = malloc(bufsize * sizeof(char*));
	char *word;
	char *word2;
	pid_t pid, wpid;
	int status;
        char *line;
	const char *i="|";
	char *buffer2;


	printf("$ ");
	fgets(buffer, 500 ,stdin);
        line=buffer;
 
    if (strstr(line,i) != NULL){ //an vrw sthn entoli pipe 
       if ((buffer2 = strrchr(line, '|')) != NULL){
            buffer2++;        
            buffer2++;
  }

	
	
  word = strtok(buffer,DELIM);
  while ( (strstr(word,i)) == NULL)  {
    words[position] = word;
    position++;

    if (position >= bufsize) {
      bufsize += BUFSIZE;
      words = realloc(words, bufsize * sizeof(char*));
      if (!words) {
        
        exit(EXIT_FAILURE);
      }
    }

    word = strtok(NULL,DELIM);
  }
  words[position] = NULL;



	
  word2 = strtok(buffer2,DELIM);
  while (word2!=NULL)  {
    words2[position2] = word2;
    position2++;

    if (position2 >= bufsize) {
      bufsize += BUFSIZE;
      words2 = realloc(words2, bufsize * sizeof(char*));
      if (!words2) {
        
        exit(EXIT_FAILURE);
      }

   }
    word2 = strtok(NULL,DELIM);
}  
  words2[position] = NULL;


 
   
 
    if (fork()==0) {
       
	

execpipe(words,words2); //kalw thn execpipe



}else  {


pid = wait(&status);

}
} else { //an den vrw pipe sthn entoli


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

       do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    
      
    }

}    
  }while (strcmp(buffer,ext) != 0);

  
  

  

  return 0;
	
}
