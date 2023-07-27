#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int i;
    pid_t pid = getpid();
    pid_t ppid = getppid();

    printf("The parent process ID is %d\n", ppid);
    printf("The process ID is %d"\n, pid);

}