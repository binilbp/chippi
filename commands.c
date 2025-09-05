#include "chippi.h"


//this file contains special functions that can be called using special keyword
//or runs on certain actions.
//These functions are to make the "chippi experience"
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
