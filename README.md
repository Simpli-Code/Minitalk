# Minitalk
The purpose of this project is to code a small data exchange program using UNIX signals.

We must create a communication program in the form of a client and a server.

• The server must be started at first. After its launch, it has to print its PID.

• The client takes two parameters:

• The server PID and

• The string to send.

• The client must send the string passed as a parameter to the server.

• Once the string has been received, the server must print it.

• The server has to display the string pretty quickly. Quickly means that if you think
it takes too long, then it is probably too long.

• The server should be able to receive strings from several clients in a row without
needing to restart.

• The communication between your client and your server has to be done only using
UNIX signals.

• We can only use these two signals: SIGUSR1 and SIGUSR2.

# 🛠️ Usage
Requirements

This program is written in C language for Linux distributions and thus needs the clang compiler and some standard C libraries to run.

Compiling the program

```
$ make
```

Execute first the server! The server will print it's PID and wait's for client's message 

```
$ ./server
```

Execute client (client needs server's PID) and a "string" you want to send to the server

```
$ ./client 2114751 "hello world"
```

# 📑 Index

@root

📁 inc: contains the program's headers.

📁 src: contains the source code of the program.

Makefile - contains instructions for compiling the program and testing it.
