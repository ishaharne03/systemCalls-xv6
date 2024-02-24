#include "types.h"
#include "stat.h"
#include "user.h"

int main(void){
    int pid = 0;
  
    set_proc_name(getpid(), "testprog:parent");
    
    pid = fork();
    if (pid == 0)
    {
        set_proc_name(getpid(), "testprog:child");
        exit();
    }
    else if (pid > 0)
    {
        sleep(1);
        print_proc_ancestors(pid);
        wait();
    }
    else
    {
        printf(1, "ERROR: fork() failed!\n");
    }
    
    exit();
}