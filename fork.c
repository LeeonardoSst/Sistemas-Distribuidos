// fork.c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork falhou");
        return 1;
    } else if (pid == 0) {
        printf("Filho: PID = %d, PPID = %d\n", getpid(), getppid());
    } else {
        printf("Pai: PID = %d, Filho PID = %d\n", getpid(), pid);
    }

    return 0;
}
