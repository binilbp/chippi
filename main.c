#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void chippi(void);
char *read_input(void);
void chippi_hello(char *);

int main(void) {
	chippi();
	return EXIT_SUCCESS;
}


void chippi(void) {

	//welcome statement with seashell unicode
	printf("Welcome to chippi \U0001F41A\n");
	printf("A simple shell to have fun with ;) type \"hello\" for starters\n");

	//used to store username for chippi_hello function
	char user_name[9] = {0};

	
	//starting the shell loop to take input commands from the user
	while(1){
	
		printf("> ");
		char *user_input = read_input();

		if (user_input == NULL) {
			//if use Ctrl + D, it is registered as NULL
			//program termination
			exit(0);

		} else if (strcmp(user_input, "exit") == 0) {
			//zero means both equal, user typed exit
			//program termination
			exit(0);

		} else if (strcmp(user_input, "hello") == 0) {

			chippi_hello(user_name);

		} else {

			printf("%s\n", user_input);
		}
	}
}


void chippi_hello(char *user_name) {

	//if no username set till now
	if (user_name[0] == '\0'){
		printf("Hi there .... What should i call u?\n");
		printf("Please enter what i should call u [max 8char]: ");
		fgets(user_name, sizeof(user_name), stdin);	

		//check if '\n' is persent in username
		if (strchr(user_name,'\n')){
			//find '\n' and replace it with '\0'
			user_name[strcspn(user_name, "\n")] = '\0';
		} else {
			//add '\0' at the last of the array
			user_name[9] = '\0';	
		}
		printf("Hi there %s\n",user_name);

	} else {
		printf("Hi there %s\n",user_name);
	}
}


char *read_input(void) {
	size_t capacity = 256;
	char temp_buffer[capacity] = {};

	//sizeof(char) is 1, essentially same as providing the size directly
	char *buffer = malloc(capacity);


	if(fgets(buffer, sizeof(temp_buffer), stdin) == NULL) {

		return NULL;

	} else {
		
		//find and replace the '\n' position with '\0'
		size_t pos = strcspn(buffer, "\n");
		buffer[pos] = '\0';	
		return buffer;
	}
}





