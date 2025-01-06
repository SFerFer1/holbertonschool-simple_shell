Proyect: Simple shell for Holberton School Uruguay


Description
This project is a simplified version of a shell in C. It interpretes UNIX command lines and handle commands with arguments such as the PATH. Also we implement an exit command to exits the shell and a env command that prints the current enviroment.

Authors

Bruno Dos Santos
Santiago Fernandez

Function implemented 

1) main

Description: Serves as the program's entry point and implements the core functionality of the shell.

Input: User input from the terminal (commands and arguments).

Output: Executes the corresponding command or displays an error message if the command is invalid.

Process:
Displays the prompt ($ ).
Reads input using getline.
Parses the input using split_string.
Creates a child process with fork.
If child: Executes the command using execve.
If parent: Waits for the child to complete using wait.
Frees dynamically allocated memory before the next iteration.

2) split_string

Description: Splits a string into individual words (tokens) using spaces or tabs as delimiters.

Input: A string to be split.

Output: An array of strings (tokens).

Process:
Counts the number of words using count_strings.
Allocates memory for the array of strings.
Tokenizes the input string with strtok and stores each token in the array.
Returns the array of strings, or NULL if an error occurs.

3) count_strings

Description: Counts the number of words in a string separated by spaces or tabs.

Input: A string to analyze.

Output: The number of words (integer).

Process:
Duplicates the input string to avoid modifying the original.
Uses strtok to count tokens separated by spaces or tabs.
Frees the duplicated string and returns the count.

4) free_split_string

Description: Frees memory allocated for an array of strings and its elements.

Input: A dynamically allocated array of strings.

Output: Frees all allocated memory for the array and its contents.

Process:
Iterates through the array and frees each string.
Frees the array itself.

5) find-exec

Description: Finds the full path of the executable for a given command.

Input: A command string (e.g., ls, echo).

Output: The absolute path of the executable, or NULL if not found.

Process:
Parses the PATH environment variable for directories.
Checks if the command exists in each directory.
Returns the path if found or NULL if not.


Requirements:

Project Requirements
This project implements a simple shell in C. The following requirements and restrictions were adhered to during development:

General Requirements
All code is written in C and adheres to the ISO C90 standard.
The shell works on Linux systems and has been tested on Ubuntu 20.04 LTS.
No external libraries or additional standard library functions (other than explicitly allowed ones) are used.

Functional Requirements

Prompt Display:
The shell must display a prompt ($ ) when awaiting user input.

Command Execution:
The shell must support the execution of basic commands found in /bin, such as ls, pwd, and echo.

Input Parsing:
User input is parsed into tokens (words) to separate the command and its arguments.

Process Management:
The shell must create a child process to execute each command using fork.
The parent process must wait for the child to finish using wait.

Error Handling:
The shell must gracefully handle invalid commands and display appropriate error messages.

Environment Variables:
The shell must support environment variables, allowing the execution of commands in paths specified by the PATH variable.

Technical Restrictions

Allowed Functions:
Only the following system and standard library functions are permitted:
The following functions and system calls were allowed for use in this project:

String Manipulation
All functions from <string.h>

File and Directory Operations
access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
open (man 2 open)
opendir (man 3 opendir)
read (man 2 read)
readdir (man 3 readdir)
stat (__xstat) (man 2 stat)
lstat (__lxstat) (man 2 lstat)
fstat (__fxstat) (man 2 fstat)
write (man 2 write)

Process Management
execve (man 2 execve)
fork (man 2 fork)
getpid (man 2 getpid)
kill (man 2 kill)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
_exit (man 2 _exit)

Memory Management
malloc (man 3 malloc)
free (man 3 free)

Input/Output
fflush (man 3 fflush)
getline (man 3 getline)
isatty (man 3 isatty)
perror (man 3 perror)
printf (man 3 printf)
fprintf (man 3 fprintf)
vfprintf (man 3 vfprintf)
sprintf (man 3 sprintf)
putchar (man 3 putchar)

String Tokenization and Parsing
strtok (man 3 strtok)

Signal Handling
signal (man 2 signal)

Working Directory Management
getcwd (man 3 getcwd)

Custom Implementations:
Custom implementations replace certain standard library functions that are not allowed. For example, _strdup is used instead of strdup.

Memory Management:
All dynamically allocated memory must be freed to prevent memory leaks.

Code Standards:
The code must be well-documented with clear comments.
Modular functions are used to improve readability and maintainability.



CASOS DE PRUEBA

Diagrama de flujo del proyecto:
