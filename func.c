#include "head.c"

int checkFilePath(char *path){
	FILE *f;
	if(fopen(path, "r")){
		return 1;
	}else{
		return 0;
	}
}

char** getArgsSemRedirect(char** args, char** args_sem_redirect, int size, int*args_sem_redirect_size){
	
	for (int i = 0; i < size; ++i){
		if( !strcmp(args[i], "=>") || !strcmp(args[i], "<=") ){
			*args_sem_redirect_size = i;
		}
	}

	args_sem_redirect = (char**)malloc( *args_sem_redirect_size * sizeof(char*) );
	for (int i = 0; i < *args_sem_redirect_size; ++i){
		args_sem_redirect[i] = (char*)malloc( 1024 * sizeof(char) );
	}

	for (int i = 0; i < *args_sem_redirect_size; ++i){
		strcpy(args_sem_redirect[i], args[i]);
	}

	return args_sem_redirect;
}

int checkRedirect(char **args, int size){

	for (int i = 0; i < size; ++i){
		if( !strcmp(args[i], ">") || !strcmp(args[i], "<") ){
			
			return 1;
		}
	}
	return 0;
	
}

char **getRedirect(char **args, int size, int* redirectSize){

	char** redirect;
	for (int i = 0; i < size; ++i){
		if( !strcmp(args[i], "=>") || !strcmp(args[i], "<=") ){
			*redirectSize = *redirectSize + 1;
		}
	}
	if(*redirectSize > 0){
		*redirectSize = 2 * (*redirectSize); 
		int j = 0;
		redirect = (char**)malloc((*redirectSize) * sizeof(char*) );
		for (int i = 0; i < (*redirectSize); ++i){
			redirect[i] = (char*)malloc( 1024 * sizeof(char) );
		}
		for (int i = 0; i < size; ++i){
			if( !strcmp(args[i], "=>") || !strcmp(args[i], "<=") ){
				

				strcpy(redirect[j], args[i]);
				j++;
				strcpy(redirect[j], args[i+1]);
				j++;
			}
		}

		return redirect;	
	}else{
		return NULL;
	}
}

char** getArgs(char** args, char* entrada, int* size){
	
	char *copia = (char*)malloc(strlen(entrada)* sizeof(char));
	strcpy(copia, entrada);

	char *token;
   
	/* get the first token */
	token = strtok(copia, " ");

	/* walk through other tokens */
	*size = 0;
	while( token != NULL ) {
	  token = strtok(NULL, " ");
	  *size = *size + 1;
	}
  	args = (char**)malloc((*size) * sizeof(char*));
	for(int j = 0; j < *size; j++){
		args[j] = (char*)malloc(1024 * sizeof(char));
	}
	token = strtok(entrada, " ");
	int i = 0;
	while( token != NULL ) {
	  strcpy(args[i], token);
	  token = strtok(NULL, " ");
	  i++;
	}

	return args;

}

void imprime(char* s){
	printf("%s\n", s);
}