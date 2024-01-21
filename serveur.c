#include "serv_cli_fifo.h"
#include "Handlers_serv.h"

int main()
{
	int count_client = 0;
	clearScreen();
	struct sigaction sa;
	struct sigaction sb;
	sa.sa_handler = handler_reveil;
	sb.sa_handler = fin_server;

	sigaction(SIGUSR1, &sa , NULL);
	sigaction(SIGINT, &sb , NULL);
	sigaction(SIGTERM, &sb , NULL);
	sigaction(SIGQUIT, &sb , NULL);

	srand(time(NULL)); 
 
	Question question; 
	Response reponse;	

	int client_to_server;
	int server_to_client;
	
	
	
	printf("\x1b[32mServer ON.\x1b[0m\n\n");
	while (1){
	
		mkfifo(FIFO_FILE_1, 0666);
		mkfifo(FIFO_FILE_2, 0666);
		
		client_to_server = open(FIFO_FILE_1, O_RDONLY);
		server_to_client = open(FIFO_FILE_2, O_WRONLY);
		
		read(client_to_server, &question, sizeof(Question));

		
        if (sizeof(question.number) == sizeof(int) && question.number > 0 && question.number <= NMAX) 
        {
            count_client++;
         
            printf("\nThe number received from the client number \x1b[1m%d\x1b[0m with the PID \x1b[1m%d\x1b[0m is \x1b[1m%d\x1b[0m.\n",count_client, question.client_pid, question.number);
            reponse.server_pid = getpid();
            
            for (int i = 0 ; i < question.number; i++){
            	reponse.list[i] = (rand() % NMAX)+ 1;
            }
            
            printf("Sending to the client with the PID \x1b[1m%d\x1b[0m...\n", question.client_pid );
            
            write(server_to_client, &reponse ,sizeof(Response));
            
            kill(question.client_pid, SIGUSR1);
            pause();
        }
        else{
        	printf("Not a valid question. Sorry we are closing the session.");
        }
        
        close(client_to_server);
        close(server_to_client);
        
        printf("___________________________________________________________________________________________");
        printf("\n/_____/_____/_____/_____/_____/_____/_____/_____/_____/_____/_____/_____/_____/_____/_____/\n");
        
        unlink(FIFO_FILE_1);
    	unlink(FIFO_FILE_2); 
    }

    return 0;
}
