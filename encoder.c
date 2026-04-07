#include <stdio.h>
#include <stdbool.h>
#include <string.h>

unsigned char password[] = "my_password1";
FILE *infile = NULL;
FILE *outfile = NULL;

char* key = "A"; // default (0) - no change
int key_index = 0;
bool is_addition = true; //default (+)

char encode(char c){
    char base;
    if(c >= 'a' && c<= 'z'){ //a-z
        base = 'a';
    }
    else if(c >= 'A' && c <= 'Z'){ //A-Z
        base ='A';
    }
    else{
        return c;
    }
    int shift = (key[key_index] - 'A');
    if(!is_addition){
        shift = -shift;
    }

    key_index++;
    if(key[key_index] == '\0')
        key_index = 0;
    return (c - base + shift + 26) % 26 + base;
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
        if(strncmp(argv[i], "+V", 2) == 0){
            is_addition = true;
            key = argv[i] + 2;
        }
        if(strncmp(argv[i], "-V", 2) == 0){
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

