# 🖥️ Operating Systems Lab — B.Tech CSE

<div align="center">

![OS Lab](https://img.shields.io/badge/Subject-Operating%20Systems%20Lab-blue?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C-orange?style=for-the-badge&logo=c)
![Platform](https://img.shields.io/badge/Platform-Linux%20%2F%20Unix-green?style=for-the-badge&logo=linux)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen?style=for-the-badge)

</div>

---

> 📚 This repository contains all **Operating Systems Lab programs** (EXP-2 to EXP-12) implemented in **C**, as part of the B.Tech CSE curriculum. Topics include UNIX system calls, CPU scheduling, synchronization, memory management, and file allocation.

---

## 👨‍💻 About

| Detail | Info |
|--------|------|
| 📖 Subject | Operating Systems Lab |
| 💻 Language | C |
| 🛠️ Compiler | GCC |
| 🐧 Platform | Linux / Ubuntu / WSL |
| 🎓 Course | B.Tech – Computer Science & Engineering |

---

## 📁 Repository Structure

```
OS-Lab/
├── EXP-2/        → UNIX System Calls
├── EXP-3/        → Simulate UNIX Commands (cp, ls, grep)
├── EXP-4/        → CPU Scheduling Algorithms
├── EXP-5/        → Port Control (Semaphore & Monitor)
├── EXP-6/        → Concurrent Threads using pthreads
├── EXP-7/        → Producer-Consumer Problem
├── EXP-8/        → Memory Allocation (First/Best/Worst Fit)
├── EXP-9/        → Page Replacement Algorithms
├── EXP-10/       → Paging Simulation
├── EXP-11/       → Banker's Algorithm
└── EXP-12/       → File Allocation Strategies
```

---

## 🗂️ Experiment Index

### EXP-2 — UNIX System Calls
> `fork` `exec` `getpid` `exit` `wait` `close` `stat` `opendir` `readdir`

| File | Description |
|------|-------------|
| `a_fork_exec.c` | Creates child process using `fork()`, runs `ls -l` via `exec()` |
| `b_exit.c` | Demonstrates `exit()` with status code |
| `c_wait.c` | Parent waits for child using `wait()` |
| `d_close.c` | Opens a file, writes to it, closes using `close()` |
| `e_stat.c` | Gets file size and last modified time using `stat()` |
| `f_opendir_readdir.c` | Lists directory contents using `opendir()` and `readdir()` |

---

### EXP-3 — Simulate UNIX Commands
> Custom C implementations of shell commands

| File | Command Simulated |
|------|------------------|
| `a_cp.c` | `cp` — Copy file using `read()` / `write()` |
| `b_ls.c` | `ls` — List directory entries |
| `c_grep.c` | `grep` — Search for pattern in a file using `strstr()` |

---

### EXP-4 — CPU Scheduling Algorithms
> All programs display: Waiting Time, Turnaround Time, and their averages

| File | Algorithm |
|------|-----------|
| `a_fcfs.c` | First Come First Serve (FCFS) |
| `b_sjf.c` | Shortest Job First (SJF) |
| `c_priority.c` | Priority Scheduling |
| `d_round_robin.c` | Round Robin with Time Quantum |

---

### EXP-5 — Control Number of Open Ports
> Limits concurrent port access to `MAX_PORTS = 3` using synchronization

| File | Method |
|------|--------|
| `a_semaphore.c` | Uses `sem_wait()` / `sem_post()` |
| `b_monitor.c` | Uses `pthread_mutex_t` + `pthread_cond_t` |

---

### EXP-6 — Concurrent Thread Execution

| File | Description |
|------|-------------|
| `a_pthreads.c` | Creates 5 threads using `pthread_create()`, waits with `pthread_join()` |

---

### EXP-7 — Producer-Consumer Problem

| File | Description |
|------|-------------|
| `a_producer_consumer.c` | Solved using semaphores (`empty`, `full`) + mutex for buffer protection |

> Buffer Size: **5** &nbsp;|&nbsp; Producer: **10 items** &nbsp;|&nbsp; Consumer: **10 items**

---

### EXP-8 — Memory Allocation (Fixed Partition)

| File | Strategy | Description |
|------|----------|-------------|
| `a_first_fit.c` | First Fit | Allocates the first partition large enough |
| `b_worst_fit.c` | Worst Fit | Allocates the largest available partition |
| `c_best_fit.c` | Best Fit | Allocates the smallest sufficient partition |

---

### EXP-9 — Page Replacement Algorithms

| File | Algorithm | Replaces... |
|------|-----------|-------------|
| `a_fifo.c` | FIFO | The oldest page in memory |
| `b_lru.c` | LRU | The least recently used page |
| `c_optimal.c` | Optimal | The page not needed for the longest future duration |

> Input: number of frames + reference string → Output: **page fault count**

---

### EXP-10 — Paging Simulation

| File | Description |
|------|-------------|
| `a_paging.c` | Translates logical addresses to physical addresses using a page table |

```
Physical Address = Frame Number × Page Size + Offset
```

---

### EXP-11 — Banker's Algorithm (Deadlock Avoidance)

| File | Description |
|------|-------------|
| `a_bankers.c` | Finds safe execution sequence; determines if system is in safe/unsafe state |

**Matrices used:**

| Matrix | Meaning |
|--------|---------|
| `Allocation` | Resources currently held by each process |
| `Max` | Maximum resources a process may ever need |
| `Need` | `Max − Allocation` |
| `Available` | Currently free resources in the system |

---

### EXP-12 — File Allocation Strategies

| File | Strategy | How it Works |
|------|----------|-------------|
| `a_sequential.c` | Sequential | Contiguous blocks are allocated one after another |
| `b_indexed.c` | Indexed | An index block holds pointers to all data blocks |
| `c_linked.c` | Linked | Each block contains a pointer to the next block |

---

## ⚙️ How to Compile & Run

```bash
# Navigate to the experiment folder
cd EXP-4

# Compile a regular C program
gcc a_fcfs.c -o fcfs

# Compile programs that use threads or semaphores (EXP-5, 6, 7)
gcc a_semaphore.c -o semaphore -lpthread

# Run the program
./fcfs
```

---

## 📚 Quick Reference

```
EXP-2  →  fork / exec / wait / stat / opendir
EXP-3  →  cp / ls / grep  (custom C)
EXP-4  →  FCFS / SJF / Priority / Round Robin
EXP-5  →  Semaphore / Monitor  (Port Control)
EXP-6  →  pthreads  (Concurrent Execution)
EXP-7  →  Producer-Consumer  (Semaphores)
EXP-8  →  First Fit / Best Fit / Worst Fit
EXP-9  →  FIFO / LRU / Optimal  (Page Replacement)
EXP-10 →  Paging  (Logical → Physical Address)
EXP-11 →  Banker's Algorithm  (Safe Sequence)
EXP-12 →  Sequential / Indexed / Linked  (File Allocation)
```

---

## 🧰 Libraries Used

```c
#include <stdio.h>        // Standard I/O
#include <stdlib.h>       // Memory allocation, exit()
#include <unistd.h>       // UNIX system calls (fork, exec, etc.)
#include <pthread.h>      // POSIX Threads
#include <semaphore.h>    // Semaphores
#include <dirent.h>       // Directory operations
#include <fcntl.h>        // File control
#include <sys/stat.h>     // File status (stat)
#include <sys/wait.h>     // wait()
#include <string.h>       // String operations (strstr, etc.)
```

---

## ⚠️ Notes for Linux Users

- Programs using `conio.h` (`getch()`) are **Windows-only** — replace with `getchar()` on Linux
- Always compile thread programs with the **`-lpthread`** flag
- For `EXP-2` programs like `stat()` and `close()`, make sure `example.txt` exists in the same directory
- Tested on **Ubuntu 22.04 / WSL2** with **GCC**

---

<div align="center">

⭐ *Star this repo if it helped you prepare for your lab exams!*

</div>
