#include <stdio.h>
#include <unistd.h>

__attribute__((export_name("wali:post:SYS_write")))
int wali_post_write(long a1, long a2, long a3){
    return a3 < 4096;
}