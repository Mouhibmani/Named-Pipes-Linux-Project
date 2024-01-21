#include "serv_cli_fifo.h"
#include "Handlers_cli.h"

int main()
{

	struct sigaction sa;
	sa.sa_handler = hand_reveil;
	sigaction(SIGUSR1, &sa , NULL);

	clearScreen();
   
	int client_to_server;
	int server_to_client;	
    
	srand(time(NULL));
     	
	Question question;
	Response reponse;
	
	question.client_pid =  getpid();
	question.number = (rand() % NMAX) + 1;
  
	printf("I'm sending the question \x1b[1m%d\x1b[0m to the server.\n", question.number);
	client_to_server = open(FIFO_FILE_1, O_WRONLY);
	server_to_client = open(FIFO_FILE_2, O_RDONLY);
  
	if(write(client_to_server, &question, sizeof(Question)) < 0){
		perror("An error during the write (client)");
		exit(-1);
	}
  
	if(read(server_to_client, &reponse, sizeof(Response)) < 0){
		perror("An error during the write (client)");
		exit(-1);
	}
  
	if(reponse.list [0] !=0){
	  	kill(reponse.server_pid, SIGUSR1);
	  	printf("The response is a list that consists of \x1b[1m%d\x1b[0m random numbers.\n\n", question.number);
		for (int i = 0; i < question.number; i++) 
		{
	        	printf("%d || ", reponse.list[i]);
	        }
		   	printf("\n");
	} else {
		printf("The server didn't send the list.\n");
	}
		
	close(client_to_server);
	close(server_to_client);

	return 0;
}
