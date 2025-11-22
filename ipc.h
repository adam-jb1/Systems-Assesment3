#ifndef PERFORM_IPC_H
#define PERFORM_IPC_H


/*
    This function performs a fork followed by an exec and also returns the pid 
    of the child process.

    params:

        `exec_args`: Is a list of arguments for running a command via exec. 
                     The last element of the array will always be NULL.
                     For example, if we wanted to run the following command
                     via exec: 

                                cat file1.txt

                     The contents of exec_args would be: 

                                char* exec_args[] = {
                                    "cat",
                                    "file1.txt",
                                    NULL  
                                }


        `pipe_read`: the read end of the pipe for interprocess communication

        `pipe_write`: the write end of the pipe for interprocess communication


    return:

        The process ID of the child process. 


    In this function, you should do the following: 
        1. create a child process
        2. In the child process:
                - close the read end of the pipe 
                - redirect all stdout from child process to 
                  the write end of the pipe 
                - close the write end of the pipe 
                - call exec using exec_args
        3. In the parent process:
                - Return the pid of the child process.

    NOTE: The code for wait() is in the tests, you do NOT have to write the 
          code for wait()

*/
pid_t fork_and_exec(char** exec_args, int pipe_read, int pipe_write);

#endif