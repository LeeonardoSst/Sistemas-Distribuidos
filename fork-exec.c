// fork-exec.c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork falhou");
        return 1;
    } else if (pid == 0) {
        // Processo filho substitui sua imagem por "ls -l"
        execlp("ls", "ls", "-l", NULL);
        perror("exec falhou"); // só roda se o exec falhar
    } else {
        printf("Pai: PID = %d, Filho PID = %d\n", getpid(), pid);
    }

    return 0;
}

