#include <stdio.h>
#include <stdbool.h>
#include <string.h>

    unsigned char password[] = "my_password1";
    FILE *infile = NULL;
    FILE *outfile = NULL;

char encode(char c){
    return c;
}


int main(int argc, char* argv[]){
    infile = stdin;
    outfile = stdout;
    int c;

    bool debug_mode = true;
    for(int i=1; i < argc; i++){
        if(debug_mode){
            fprintf(stderr, "%s \n" , argv[i]);
        }
        if (strncmp(argv[i], "+D", 2) == 0 && strcmp(argv[i] + 2, (char*)password) == 0){
            debug_mode = true;
        }
        if(strcmp(argv[i],"-D")==0){
            debug_mode = false;
        }
    }

    while (true){
        c = fgetc(infile);
        if(feof(infile)){
            break;
        }
        c = encode(c);
        fputc(c, outfile);
    }
    fclose(outfile);
}

