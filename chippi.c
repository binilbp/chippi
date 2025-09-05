#include "chippi.h"


//basic chippi functioning logic -> a loop checking when to exit or to 
//read the user input data and output the relevant data if any
void chippi(void) {

	//welcome statement with seashell unicode
	printf("Welcome to chippi \U0001F41A\n");
	printf("A simple shell to have fun with ;) type \"hello\" for starters\n\n");

	//used to store username for chippi_hello function
	char user_name[9] = {0};
	//used to store the user input data
	char *user_input = NULL;
	
	//starting the shell loop to take input commands from the user
	while(1){
	
		printf("> ");
		user_input = read_input();

		if (user_input == NULL) {
			//if use Ctrl + D, it is registered as NULL
			//program termination
			chippi_bye(user_name);
			exit(0);

		} else if (strcmp(user_input, "exit") == 0) {
			//zero means both equal, user typed exit
			//program termination
			chippi_bye(user_name);
			exit(0);

		} else if (strcmp(user_input, "hello") == 0) {

			chippi_hello(user_name);

		} else {

			printf("%s\n", user_input);
		}
	}

	//cant forget to free malloc memory unless i want memory leak
	if(user_input != NULL){
		free(user_input);
	}

}
