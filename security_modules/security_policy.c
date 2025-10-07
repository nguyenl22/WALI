__attribute__((export_name("wali:pre:read")))
int wali_pre_read(long a1, long a2){
    return 0xdeadbeef;
}

__attribute__((export_name("wali:post:read")))
int wali_post_read(long a1, long a2, long a3){
    return 0xaaaabbbb;
}