#include <stdio.h>
#include <stdbool.h>
#include <string.h>

FILE *infile = stdin;   
FILE *outfile = stdout;

int main(int argc, char* argv[]){
    unsigned char password[] = "my_password1";

    bool debug_mode = true;
    for(int i=1; i < argc; i++){
        if(debug_mode){
            fprintf(stderr, "%s \n" , argv[i]);
        }



        if (strncmp(argv[i], "+D", 2) == 0 && strcmp(argv[i] + 2, (char*)password) == 0){
            debug_mode = true;
        }
        if(argv[i]=="-D"){
            debug_mode = false;
        }
    }

    for(int i=1; i < argc; i++){
        if(debug_mode){
            fprintf(stderr, "%s \n" , argv[i]);
        }
    }
}

char encode(char c){
    return c;
}