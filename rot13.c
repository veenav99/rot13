#include <stdio.h>
#include <string.h>
#include <ctype.h>

void cipher( char *message ){
    for( int k = 0; message[ k ]; k++ ){  // stops when End of line character
        if(isalpha(message[k])){
            if( message[ k ] >= 'A' && message[ k ] <= 'Z' ){
                message[ k ] = ( message[ k ] - 'A' + 13) % 26 + 'A';
            } else if (message[ k ] >= 'a' && message[ k ] <= 'z') {
                message[ k ] = ( message[ k ] - 'a' + 13 ) % 26 + 'a';
            }
        }else if(message[k] == ' ' || message[k] == '.' || message[k] == '!' || message[k] == '?' || message[k] == ','){
            message[k] = message[k];
        }else{
            continue;
        }

    }
}

int main(int argc, char *argv[]) {
    int i = 0;
    for(i = 1; i < argc; i++){
        cipher(argv[i]); 
        printf("%s\n",argv[i] );
    }

    return 0;
}