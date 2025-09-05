#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void chippi(void);
char *read_input(void);
void chippi_hello(char *);
void chippi_bye(char *);

int main(void) {
	chippi();
	return EXIT_SUCCESS;
}


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


void chippi_hello(char *user_name) {

	//if no username set till now
	if (user_name[0] == '\0'){
		printf("Hi there .... What should i call u? (max 8 letters):");
		fgets(user_name,9 , stdin);	

		//check if '\n' is persent in username
		if (strchr(user_name,'\n')!= NULL){
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

void chippi_bye(char *user_name) {

	if (user_name[0] == '\0'){

		printf("Good Bye !\n");

	} else {

		printf("Good Bye %s !\n",user_name);
	}
}

char *read_input(void) {
	//to track the size mannually
	size_t capacity = 256;
	size_t current_capacity = capacity;

	char temp_buffer[capacity] = {};

	//sizeof(char) is 1, essentially same as providing the size directly
	char *buffer = malloc(capacity);
	//setup the raw memory for storing string
	buffer[0] = '\0';


	//fgets only read until the max size or '\n' or EOF
	//for the case with multiple lines, we do while loop
	//cuz '\n' might not be in the char of given size
	while(1){

		if(fgets(temp_buffer, sizeof(temp_buffer), stdin) == NULL) {

			//ideally input should be either '\n' or some value
			//therefore with NULL we return NULL
			return NULL;

		}
		


		//check if we need to increase memory before appending continuous data
		if(strlen(temp_buffer) + strlen(buffer) >= current_capacity){
			//true means we need to increase the memory size
			char *temp = realloc(buffer, current_capacity+capacity);
			if (temp == NULL){
				perror("Allocation failed\n");
				return NULL;
			}

			//also note the change mannually since reallocation succeeded
			current_capacity += capacity;

			//update the pointer old pointer with new larger sized memory pointer
			buffer = temp;
		}

		//safely append the rest of the user data to older data
		strcat(buffer, temp_buffer);


		//now we check if the latest data we added have '\n'
		//if yes it means we stop fgets loop here and return value
		//after changing the '\n' to '\0'
		if (strchr(buffer,'\n') != NULL){
			//find and replace the '\n' position with '\0'
			size_t pos = strcspn(buffer, "\n");
			buffer[pos] = '\0';	
			return buffer;
		}
	}
}





