# Question 2 - Process Creation and Management using fork()

## Objective

Design a C program that:

- Creates child processes using `fork()`.
- Monitors their execution.
- Prevents zombie processes.
- Terminates an unresponsive child process using signals.

---

## Commands Executed

### 1. Create the source file

```bash
nano process_monitor.c
```

**Explanation:**
Created the C source file and wrote the program to demonstrate process creation and management.

---

### 2. Display the source code

```bash
cat process_monitor.c
```

**Explanation:**
Displayed the complete source code to verify that the program was saved correctly.

---

### 3. Compile the program

```bash
gcc process_monitor.c -o process_monitor
```

**Explanation:**
Compiled the C program using GCC and generated an executable file named `process_monitor`.

---

### 4. Verify the executable

```bash
ls
```

**Explanation:**
Confirmed that both the source file and executable were successfully created.

---

### 5. Execute the program

```bash
./process_monitor
```

**Explanation:**
Executed the program to create child processes, monitor their execution, terminate the unresponsive child process, and clean up all child processes.

---

## System Calls Used

### `fork()`

Creates a new child process. Each child executes independently of the parent.

### `waitpid()`

Allows the parent process to wait for child processes to finish, preventing zombie processes.

### `kill()`

Sends the `SIGTERM` signal to terminate the unresponsive child process gracefully.

### `sleep()`

Simulates normal execution time and an unresponsive child process.

---

## How Process Creation, Waiting and Signal Handling Work Together

The parent process creates multiple child processes using `fork()`. One child intentionally runs longer to simulate an unresponsive process.

The parent monitors the child processes, terminates the unresponsive child using `SIGTERM`, and waits for all child processes using `waitpid()`. This prevents zombie processes and ensures that system resources are released properly.

---

## Sample Output

```
Parent Process ID: xxxxx

Child 1 created...
Child 2 created...
Child 3 created...

Parent is monitoring child processes...

Child 3 is unresponsive...

Child 1 completed.
Child 2 completed.

Terminating unresponsive child process...

No zombie processes remain.
```

*(The Process IDs (PIDs) may differ each time the program is executed.)*

---

## Screenshots

Include screenshots of:

- Creating the source file.
- Compiling the program.
- Executing the program.
- Output displayed in the terminal.
