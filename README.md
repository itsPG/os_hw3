## A quick start guide (for those who have no time).

### Step 1: clone this repo (~10MB)
	git clone https://github.com/itsPG/os_hw3.git

### Step 2: build those example codes
	cd os_hw3
	make

### Step 3: read the [assigment](https://github.com/itsPG/os_hw3#assignment) and checkout sample_video branch to see a sample_video

#### Install VLC (if you don't have a player)
	sudo rpm -ivh http://download1.rpmfusion.org/free/fedora/rpmfusion-free-release-stable.noarch.rpm
	sudo yum install vlc

#### For Fedora 17
	git checkout sample_video
	vlc os_hw3_sample.m4v

vlc should be replaced with your player's name.

#### For Mac
	git checkout sample_video
	open os_hw3_sample.m4v

### Step 4: Implement your program. 

See the [grading policy](https://github.com/itsPG/os_hw3#grade-) and choose what you want to do.

### Step 5: Upload your homework to [e3](http://dcpc.nctu.edu.tw).

Make sure your homework has [those files](https://github.com/itsPG/os_hw3#submission).

---

---

# HW #3. Process Concept

# Overview

In this homework, you will understand what a process is and know how to communicate with processes. You will also learn some useful linux programming skills in this homework.

There are many example codes in this instruction, which demonstrate many useful skills that can help you pass messages from one process to another process. After that, you will be asked to implement a simple shell. (You may notice that those example codes provides all you need. You just have to rearrange them with some basic C/C++ programming language knowledge.)

## About this homework

If you found any error in this homework or you have any problem about this homework, feel free to tell TAs on the E3. This instruction will be updated immediately if there's any error in this documentation and/or example codes.

The newest files can always be found from [github](https://github.com/itsPG/os_hw3). You may want to download the auto compressed zip file from [here](https://github.com/itsPG/os_hw3/zipball/master) or just clone this repo by `git clone https://github.com/itsPG/os_hw3.git`. Use `make` to build all of those example codes.

There's a [sample video](https://github.com/itsPG/os_hw3/blob/sample_video/os_hw3_sample.m4v) showing how the finished homework would be (This is just a sample, feel free to add any feature or change the appearance to what you like). 

There's a [sample terminal record](http://shelr.tv/records/508850ad966080163f00002b) if you don't want to download a big file. (However, this record can not show how does your program active with others terminal.)




---

# Instruction

## A. Observe the runtime process info

`/proc` is a special virtual directory. you can observe the information of a running process by looking at those directories and files under this folder.

In this part, we will show how to list those running process and extract information from `/proc`.

If you want to know more about this special virtual directory. You may look up [Kernel documentation](http://www.kernel.org/doc/Documentation/filesystems/proc.txt) for more information.

### Step 1

Open your terminal and something we want to observe. In this example, you may open Firefox, which is installed as a default application in Fedora.

### Step 2 

Type `ps aux` or `ps fax` in terminal. ps is a built-in program help us to list all running processes.
You may look and/or download source code from [proceps homepage](http://procps.sourceforge.net)

### Step 3

Type `ps fax | grep firefox` to find the pid of running Firefox.


### Step 4

Type `cd /proc/$(PID of Firefox)`. List this folder by type `ls`.


## B. Memory layout of a process

A typical memory representation of C program consists 5 sections.


>Higher Memory address

>* Stack
>* Heap
>* Uninitialized data
>* Initialized data
>* Text

>Lower memory address


You can read more information from [here](http://www.geeksforgeeks.org/archives/14268)

### Step 1

Type `sudo cat /proc/$(PID of a running process)/maps`.

---

## C. Linux Programming

In this part, I will list some basic and/or useful skill that will help you do this homework.

This is TA's personal suggestion, if you are familiar with Linux Programming, you may skip this part.


### Programming Language

Basic C knowledge is required.

You can also use C++ in this homework.


### Editor

vim is recommended.

However, gedit works fine, and I use [sublime text](http://www.sublimetext.com/) to finish this homework.

### makefile

A simple makefile could save you so much time.

### git / svn

A good CVS (Concurrent Versions System) could help you track your program and help you recover your code from a failed modifying. I use [gitlab](http://gitlabhq.com/) for personal CVS and [github](https://github.com/) for public CVS. However, YOU SHOULD DO YOUR HOMEWORK INDIVIDUALLY. Any plagiarizing will be punished.


---

## D. Fork and File Descriptor

### Fork

Fork() creates a new process by duplicating the calling process.
We call the old process "parent", and the new process "child".

Basically, we can think the behavior of fork is just like "it creates a copy process of itself, except some information will be changed." If you want to know what EXACTLY fork() do, you may want to check [fork specification](http://pubs.opengroup.org/onlinepubs/9699919799/functions/fork.html) for more detail.

Fork() returns

> : -1, if fork() failed.

> : 0, if fork() succeeded and this is a child process.

> : child's pid, if fork() succeeded and this is a parent process. 

### Fork example 1


### Fork example 2



### File Descriptor

File Descriptor provides a interface that we can manipulate file. When a new process is initialized, there are 3 default File Descriptors will be opened: stdin(0), stdout(1), and stderr(2). In Linux kernel, every process will have a unique File Descriptor Table, which denotes those opened File Descriptors.

Some useful functions are listed below:

[open()](http://linux.die.net/man/2/open)

> Given a pathname for a file, open() returns a file descriptor, a small, nonnegative integer for use in subsequent system calls (read(2), write(2), lseek(2), fcntl(2), etc.). The file descriptor returned by a successful call will be the lowest-numbered file descriptor not currently open for the process.

[close()](http://linux.die.net/man/2/close) 

> close() closes a file descriptor, so that it no longer refers to any file and may be reused. Any record locks (see fcntl(2)) held on the file it was associated with, and owned by the process, are removed (regardless of the file descriptor that was used to obtain the lock).

[read()](http://linux.die.net/man/2/read)

> read() attempts to read up to count bytes from file descriptor fd into the buffer starting at buf.If count is zero, read() returns zero and has no other results. If count is greater than SSIZE_MAX, the result is unspecified.

[write()](http://linux.die.net/man/2/write)

> write() writes up to count bytes from the buffer pointed buf to the file referred to by the file descriptor fd.

[dup()](http://linux.die.net/man/2/dup)

> dup() uses the lowest-numbered unused descriptor for the new descriptor.dup2() makes newfd be the copy of oldfd, closing newfd first if necessary.

[fcntl()](http://linux.die.net/man/2/fcntl)

> fcntl() performs one of the operations described below on the open file descriptor fd. The operation is determined by cmd.

### File Descriptor example 1

### File Descriptor example 2

---

## E. Inter-process communication

Inter-process communication (IPC) is a set of methods for the exchange of data among multiple threads in one or more processes.

You can look up [wikipedia:IPC](http://en.wikipedia.org/wiki/Inter-process_communication) for more information.

In this homework, we will cover 

* Signal
* Pipe
* FIFO
* Shared memory
* Message queue

## Signal

Signal, also known as software interrupt, is a way to communicate with process. For example, when you press `Ctrl+C`, a SIGQUIT is sent to quit the process which is running. You can use `kill -l` to list all available signal.

When process receive a signal, it can ignore it, do the default action (for example: quit), or do the registered handle function. 

Linux (usually) doesn't allow user to create new signal type, but it reserves two signal: SIGUSR1, SIGUSR2 for IPC use. The default action of SIGUSR1 and SIGUSR2 is "ignore".

Some useful functions are listed below:

[raise()](http://linux.die.net/man/3/raise)

> The raise() function sends a signal to the calling process or thread

[kill()](http://linux.die.net/man/2/kill)

> The kill() system call can be used to send any signal to any process group or process.

[signal()](http://linux.die.net/man/2/signal)

> The signal() sets the disposition of the signal signum to handler, which is either SIG_IGN, SIG_DFL, or the address of a programmer-defined function (a "signal handler")

## Pipe

Pipe is a useful way to send data from one process to another process through file descriptor, however, it can only communicate between processes those have the same parent. Let's see how it work:

	int main()
	{
		int f[2];
		pipe(f);
		return 0;
	}

When you call `pipe(f)`, linux kernel will create a new pipe, and give f[0] and f[1] the file descriptor representing to this new pipe respectively. Whenever you `write()` something to f[1], you could read those written data through f[0].

If `read()` can not read data from f[0], process will be blocked here and waiting for `write()` instead of returning 0 immediately, unless the pipe f[1] has been closed. If you `fork()` a process, the pipes created before `fork()` would be forked too. Therefore, when you want to close a forked piped, you need to close it in parent and child respectively. The detail of manipulate a pipe is very important, and it will be shown in example.

## Pipe example 1

## Pipe example 2

## Pipe example 3

## FIFO

The behavior of FIFO is similar to pipe. However, FIFO can pass data between different processes, which pipe can't. To use FIFO, you need to use [mkfifo()](http://linux.die.net/man/3/mkfifo) to create a FIFO file. Then, we can pass data between processes by using the same FIFO file.

## FIFO example 1

## FIFO example 2

## Shared memory

Shared memory maps the same memory page to different processes. To use shared memory, we use [shm_get()]() to create a shared memory block. Then, we can use [shm_at()]() to attach to a memory block, or use [shm_dt()]() to detach a memory block.

We can use command `ipcs -a` to list all shared memory blocks that we are using now. Those shared memory will be alive until we reboot. We can use command `ipcrm` to remove a shared memory block or use [shm_ctl()]() to manage shared memory.

## Shared memory example 1

## Shared memory example 2

## Shared memory example 3

---

# Assignment

In this homework, you will implement a very simple shell called **Y-SHELL**.

## Your Y-SHELL can:

* Detects user's Ctrl+C, then print "Bye Bye~" and exit. (Hint. Ctrl+C is SIGINT.)
* Executes programs. For example: `ls`
* Executes programs with arguments. For example: `ls -l -a`
* Pipes data from one command to another command. For example : `ls -l -a | grep .txt | grep rwx` (There would be at most three command. i.e. `A | B | C`)
* Redirects all messages from stderr to a FIFO. For example: if you type `ls | grep`, there would be an error message like " Try `grep --help' for more information.". You need to redirect this message to FIFO. (So we can check this message by another program.)
* Clipboard: cut commands' output to shared memory from a pipe by command '^', and paste the content of clipboard to pipe by command '>'. For example: User A may use `ls | ^` to send the result of `ls` to a shared clipboard. Then User B may use `>` to show the content of clipboard or use '> | grep c' to receive the content of clipboard and send it to `grep c` command.


Your shell should run programs by [exec family function](http://pubs.opengroup.org/onlinepubs/009604499/functions/exec.html). 

## Bonus:

* Pipes data from one command to another command with most 100 commands (99 | ).


## For simplification :

* The length of command is less than 3000. For example: The length of `ls | grep .txt` is 14.
* Every command would exist and execute successfully. You don't need to worry about segmentation fault happen.
* You may assume all inputs are leagal. There's exactly one " " char between every command, pipe, and argument. For example: the test data won't be `ls|grep c`, `ls -l|grep c`, `ls || grep c` ,nor `ls   |    grep c`.
* You may create your FIFO in your installing script. And use a fixed FIFO name if you need to.
* You just need to dup a "O_WRONLY | O_NONBLOCK" FIFO to stderr. If you successfully dup FIFO to stderr, the stderr outputted by commands will disappear. If you dup a nonblock FIFO to stderr and this FIFO is not ready yet, the stderr may appear. That is fine for this homework. => i.e. In this homework, we don't care stderr disappear or not.
* Clipboard command: `^` will only appear at the end of line. `>` will only appear at the start of line. For example: `ls | ^`, `> | grep c`.
* Clipboard command: `^`(cut commands' output to clipboard) won't be a single command. (but `>`(paste) will).
* You don't need to handle synchronization problem. Therefore, you may assume shared memory won't be written at the same time.

## For testing your shell :

I wrote a program that may help you test your shell. This program reads data from stdin and writes modified data to stdout until end of input. The source file is named as "line_number.cpp". 

#### 1. add line number

For example: `ls | ./line_number`

#### 2. add color

For example: `ls | ./line_number -C`

#### 3. delayed output

For example: `ls | ./line_number -D`

When testing your shell, the input may be like this: `ls | grep .c | ./line_number -C -D`. 

### sample input commands

There are some sample input commands listed below:

	ls
	ls -l -a
	ls | grep .c
	ls | grep .c | ./line_number -C -D
	ls | grep | ./line_number -C -D
	ls | ^
	>
	> | grep c


## Grade :

### Basic:

* 25% A guide and scripts (or makefiles) help me compile and run your program.
* 25% A simple report tell me how do you implement your shell, what is the most difficult part of this homework, how many time you spend on this homework, and anything else you want to say.
* 10% Your program can detect Ctrl+C.
* 10% Your program can execute program with argument by exec family function.
* 10% Your program can execute most 3 commands and connect them using pipe.
* 10% Your program can redirect stderr msg.
* 10% Your program can use clipboard command.

### Extra:
* +10% if your program can deal with most 100 commands.
* + 5% if your shell has only one executable file.
* -8%~80% if your code is (very similar to / exactly the same as) any others' code. 

## Gently reminding

Although this homework can be finished very quickly (There are only **150** lines in my [final code](http://i.imgur.com/dcefR.png).), you may spend lots of time testing and dealing with pipes. Make sure you reserve enough time for this homework if this is your first time coping with pipes.

# Submission

Please submit the homework assignment in zip or rar file format on the E3. Including

* A guide help me compile and run your program in pdf, txt, html, or markdown format.
* A simple report (100~500 words is recommended) in pdf, txt, html, or markdown format.
* Your source codes.
* Some script and/or makefile help me compile and run your porgram (if needed).

Late submission will be penalized.

Please start your work early on.