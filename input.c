#include "chippi.h"


//logic for taking in the user input from the terminal
//i think these can be easily done with shorter code using built in fucntion
//but wheres the fun in that right !!.......all to study C ....TT
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
