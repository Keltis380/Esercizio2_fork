#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    for (int i = 0; i < 3; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            printf("Errore nella creazione del figlio.\n");
            return 1;
        }

        if (pid == 0) {
            // Codice del figlio
            printf("[Figlio] PID: %d\n", getpid());

            sleep(2);

            printf("[Figlio] PID %d terminato.\n", getpid());
            exit(0);
        }
    }

    // Codice eseguito solamente dal padre
    for (int i = 0; i < 3; i++) {
        wait(NULL);
    }

    printf("[Padre] Tutti e 3 i figli hanno terminato.\n");

    return 0;
}