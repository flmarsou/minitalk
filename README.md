# 🦊 What is Minitalk?

A little program to learn about **UNIX signals**. \
The goal is to make two terninal communicate with one another, using **PID** *(**P**rocess **Id**entifier)*, **signals**, **binary shifting**...

- Since signals can only send one information at a time, the client will deconstruct the string into bits, sending `SIGUSR1` for 0 and `SIGUSR2` for 1 with the `kill()` function.
- The server awaits indefinitely `pause()` information `signal()`, and translates back the binary into printable characters.
- Finally, the server will send back to the client how many information it received, terminating the client. 

# ⚒️ Compilation

1. Run `make` to compile the server and the client.
Run `make re` to recompile everything.
2. Run `./server` to execute the server.
3. Run `./client <PID> "messasge"` <ins>in another terminal!</ins>

# 🧼 Cleaning

1. Run `make clean` to remove every object files.
2. Run `make fclean` to remove every object files, including the executable.

# ✨ Summary

|     |     |
| --- | --- |
| Program name | client, server |
| Turn in files | Makefile, *.h, *.c |
| Makefile | NAME, all, clean, fclean, re |
| External functs. | write, [`ft_printf`](https://github.com/flmarsou/2.1-ft_printf), signal, sigemptyset, sigaddset, sigaction, kill, getpid, malloc, free, pause, sleep, usleep, exit |
| Libft authorized | Yes |
| Description | Write a program for two terminal to exchange using UNIX signals. |

# 📑 List of Functions

## Main Files
- [x] [`client`](https://github.com/flmarsou/3.2-minitalk/blob/main/src/client.c): \
Converts every characters of a string into bits, sending them individually through `SIGUSR1` and `SIGUSR2`. \

- [x] [`server`](https://github.com/flmarsou/3.2-minitalk/blob/main/src/server.c): \
Receives bits through `SIGUSR1` and `SIGUSR2`, translating it back to characters for printing.
