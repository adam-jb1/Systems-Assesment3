#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

pid_t fork_and_exec(char** exec_args, int pipe_read, int pipe_write) {                        

    pid_t pid = fork();

    if (pid == 0) {
        close(pipe_read);
        
        //- redirect all stdout from child process to the write end of the pipe
        dup2(pipe_write, STDOUT_FILENO);

        close(pipe_write);

        execvp(exec_args[0], exec_args);
    }
    // don't forget to return the pid of the child 
}
