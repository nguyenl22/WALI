#include <stdbool.h>
#include <signal.h>

static int count = 0;

__attribute__((export_name("wali:post:SYS_open")))
int wali_post_open(long a1, long a2, long a3){
    count += 1;
    //raise(SIGTRAP);
    if (count < 3) {
        return false;
    }
    return true;
}