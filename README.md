# 🦊 What is Minitalk?

Minitalk is a simple program to learn the use of **UNIX signals**. \
The goal is to make two terminals to communicate with one another using **Process IDs** (PIDs), **signals**, and **binary encoding**.

### Overview:
- **Client:** Sends a string to the server by encoding each bit of the message as UNIX signals. **`SIGUSR1`** represents a binary 0, and **`SIGUSR2`** represents a binary 1. The **`kill()`** function is used to send these signals.
- **Server:** Waits for incoming signals using **`pause()`**. It decodes the signals back into a string and stores the message in a buffer. Once the full message is received, the server sends an acknowledgment signal back to the client, indicating successful reception.

# ⚒️ Compilation

1. Run `make` to compile the server and the client.
2. Run `make re` to recompile everything.
3. Run `./server` to execute the server.
4. Run `./client <PID> "messasge"` <ins>in another terminal!</ins>

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
| [Libft](https://github.com/flmarsou/1-Libft) authorized | Yes |
| Description | Write a program for two terminal to exchange using UNIX signals. |

# 📑 List of Functions

- [x] [`client`](https://github.com/flmarsou/3.2-minitalk/blob/main/src/client.c) - Sends signals to the server, waits for an acknowledgment, and returns.
- [x] [`server`](https://github.com/flmarsou/3.2-minitalk/blob/main/src/server.c) - Waits for signals, prints once fully received, and sends an acknowledgment.
