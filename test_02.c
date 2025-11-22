#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <assert.h>

#include "ipc.h"

char* exec_args[] = { "cat", "tests/file2.txt", NULL };

int main() {

    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(1);
    }

    pid_t child_pid = fork_and_exec(exec_args, pipefd[0], pipefd[1]);
    close(pipefd[1]);

    FILE* f = fopen("tests/file2.txt", "rb");
    if (!f) { perror("fopen"); exit(1); }

    char pipe_buf[256], file_buf[256];
    ssize_t n_pipe;
    size_t n_file;

    int i = 0;

    while ((n_pipe = read(pipefd[0], pipe_buf, sizeof(pipe_buf))) > 0) {
        i++;
        n_file = fread(file_buf, 1, n_pipe, f);
        assert(n_file == (size_t)n_pipe);

        if (memcmp(pipe_buf, file_buf, n_pipe) != 0) {
            fprintf(stderr, "TEST 02 - FAILURE\n");
            return -1;
        }
    }

    if ( i == 0 ) {
        fprintf(stderr, "TEST 02 - FAILURE\n");
        return -1;
    }

    close(pipefd[0]);
    fclose(f);

    int status;
    waitpid(child_pid, &status, 0);  // ensure child termination

    printf("TEST 02 - SUCCESSFUL\n");
    return 0;

}