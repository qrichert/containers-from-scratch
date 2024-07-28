#include <stdio.h>
#include <string.h>

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
    printf("running: '");
    for (int i = 0; i < argc; ++i) {
        printf("%s", argv[i]);
        if (i < argc - 1) {
            printf(" ");
        }
    }
    printf("'\n");
}
