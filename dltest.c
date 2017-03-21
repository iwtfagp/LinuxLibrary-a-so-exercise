#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(){
    void *handle;
    void (*f)();
    char *error;

    /* 開啟之前所撰寫的 libmylib.so 程式庫 */
    handle = dlopen("./libmylib.so", RTLD_LAZY);
    if( !handle ) {
        fputs( dlerror(), stderr);
        exit(1);
    }

/* 取得 hello function 的 address */
    f = dlsym(handle, "hello");

    if(( error=dlerror())!=NULL) {
        fputs(error, stderr);
        exit(1);
    } 
/* 呼叫該 function */
    f();
    dlclose(handle);
}
