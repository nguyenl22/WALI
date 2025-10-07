#include "stdbool.h"
#include "string.h"
#include "stdint.h"

char wali_post_buf[1024];
int64_t foo = 0xdeadbeef;

__attribute__((export_name("wali:post:SYS_open")))
int wali_post_open(char *a1, long a2, long a3){
  if (strncmp(a1, "/proc/self/mem", 1024) == 0) {
    return false;
  }
  return true;
}