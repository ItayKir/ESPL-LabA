#include <stdio.h>
#include <stdbool.h>
#include <string.h>

unsigned char password[] = "my_password1";
FILE *infile = NULL;
FILE *outfile = NULL;

char* key = "A"; // default (0) - no change
bool is_addition = true; //default (+)

char encode(char c, int key_index, bool is_addition){
    if(c < 'a' || c > 'Z'){ // not a letter a-z or A-Z
        return c;
    }

    char base;
    if(c < 'A'){ //a-z
        base = 'a';
    }
    else{ //A-Z
        base ='A';
    }
    int shift = (key[key_index] - base);
    key_index++;
    if(key[key_index] == '\0')
        key_index = 0;
    return (c + shift)%26 + base;
}



int main(int argc, char* argv[]){
    infile = stdin;
    outfile = stdout;
    int c;

    bool debug_mode = true;
    for(int i=1; i < argc; i++){
        // debug printing
        if(debug_mode){
            fprintf(stderr, "%s \n" , argv[i]);
        }

        // encoding word
        if(trncmp(argv[i], "+V", 2) == 0){
            is_addition = true;
            key = argv[i] + 2;
        }
        if(trncmp(argv[i], "-V", 2) == 0){
            is_addition = false;
            key = argv[i] + 2;
        }

        // debug flag changes
        if (strncmp(argv[i], "+D", 2) == 0 && strcmp(argv[i] + 2, (char*)password) == 0){
            debug_mode = true;
        }
        if(strcmp(argv[i],"-D")==0){
            debug_mode = false;
        }
    }
    int key_index = 0;
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

