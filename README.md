# SIMPLE SHELL

This is the second ALX team project where we try to recreate the Bash (Unix shell) using the knowledge we gained from the previous tasks.
## Screenshots

![App Screenshot](https://i.imgur.com/EltyYJj.png)
## WHAT IS SHELL?

In computing, a shell is a computer program that exposes an operating system's services to a human user or other programs. In general, operating system shells use either a command-line interface (CLI) or graphical user interface (GUI), depending on a computer's role and particular operation. It is named a shell because it is the outermost layer around the operating system.

### COMMAND-LINE SHELL

A command-line interface (CLI) is an operating system shell that uses alphanumeric characters typed on a keyboard to provide instructions and data to the operating system, interactively. For example, a teletypewriter can send codes representing keystrokes to a command interpreter program running on the computer; the command interpreter parses the sequence of keystrokes and responds with an error message if it cannot recognize the sequence of characters, or it may carry out some other program action such as loading an application program, listing files, logging in a user and many others. Operating systems such as UNIX have a large variety of shell programs with different commands, syntax and capabilities, with the POSIX shell being a baseline.

## TASKS WE HANDLED


- We display a prompt and wait for the user to type a command. A command line always ends with a new line.
- The prompt is displayed again each time a command has been executed.
- The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
- If an executable cannot be found, we print an error message and display the prompt again.
- the “end of file” condition (Ctrl+D) is handled
- command lines with arguments are handled
- the PATH is handled
- the exit built-in, that exits the shell, without arguments is handled
- the env built-in, that prints the current environment, is handled
- Usage of our own getline.

## Authors

- [Youssef Chibane](https://github.com/Youssef-Chibane) && [Mohammed Lagrini](https://github.com/Suigetsu)
