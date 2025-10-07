#include <stdio.h>
#include <unistd.h>

__attribute__((export_name("wali:post:SYS_lseek")))
int wali_post_lseek(long a1, long a2, long a3){
    return a1 == 1;
}