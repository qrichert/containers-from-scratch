#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sched.h>

void run(int, char*[]);

// docker run <container> <command> <args>
// dockus run             <command> <args>
int main(int argc, char* argv[]) {
    if (argc >= 3 && strcmp(argv[1], "run") == 0) {
        run(argc - 2, &argv[2]);
    } else {
        fprintf(stderr, "Bad arguments.\n");
        return 2;
    }
    return 0;
}

void run(int argc, char* argv[]) {
    char* args[argc + 1];
    memcpy(args, argv, argc * sizeof(char*));
    args[argc] = NULL; // Args to `execvp()` must be NULL-terminated.

    unshare(
        CLONE_NEWUTS // Hostname.
        | CLONE_NEWPID // PID.
    );

    sethostname("dockus", strlen("dockus"));

    pid_t pid = fork();
    if (pid == 0) {
        execvp(args[0], args);
        fprintf(stderr, "'%s' not found.\n", args[0]);
    } else {
        waitpid(pid, NULL, 0);
    }
}
