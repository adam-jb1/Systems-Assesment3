# Assessment 3 | IPC with Pipes


In this assessment, you will: 

1. Implementing the **fork_and_exec** function in **ipc.c** file
3. Submit **only** the `ipc.c` file to the server 

## Resources

|name | resource |
|------|-------|
| submit server | [https://submit.cs.seas.gwu.edu/](https://submit.cs.seas.gwu.edu/) | 
| class textbook | [https://gwu-cs-sysprog.github.io/](https://gwu-cs-sysprog.github.io/) | 
||


# Coding Instructions

The **only** code you will be implementing for this assessment will be:

- the `fork_and_exec` function in the `ipc.c` file

The `ipc.h` file contains instructions on the function you need to complete.  


Here are the files and their descriptions:

|file|description|
|----|-----------|
|`ipc.h`|Contains details of the `fork_and_exec` function you need to implement.|
|`ipc.c`|This is where you write your code.|
|`tests`|A directory that contains all the tests.|
||


# Compiling your code 

To compile your code, run the following command 

```shell
make
```

# Running your code 

To execute your code, run the following command

```shell
make test
```

# Submission Instructions 

To submit your code, you need to: 

1. Find `ipc.c` file 
2. Upload **ONLY** the `ipc.c` file to the submission server (submit.cs.seas.gwu.edu)

## Important Details 

- Do **NOT** modify any other code/file than the one from aforementioned instructions
- Comment and Indent your code
- Validate if your code runs correctly before submitting 

# Grading Rubric

To grade your assignment, we will use the following file: 

- `ipc.c`

In our test harness, we'll use a slightly modified version of tests.

|score | phase |
|------|-------|
| `0`    | code does not compile or build | 
| `+20`  | code compiles | 
| `+10`  | well commented/indented code | 
| `+35`  | successful execution of `test_01` |
| `+35`  | successful execution of `test_02` |
| **100** | **Total score** |
||


**Note:**

- as mentioned in the [class policies](https://sibin.github.io/teaching/csci2410-gwu-systems_programming/current/index.html) **do not** cheat/copy code and **do not** use any AI/code generation/LLM tools
- if we detect any of this, your grade for this assessment will be `0` and you will be reported for an academic integrity violation!
- **all devices** must be put away and not accessed during the assessment

