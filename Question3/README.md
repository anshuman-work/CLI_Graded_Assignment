# Question 3 - Secure File Processing Using Linux System Calls

## Objective

Design a C program that uses Linux system calls to:

- Create a file.
- Write employee records.
- Update a specific record without rewriting the entire file.
- Retrieve records efficiently.
- Demonstrate the use of `open()`, `read()`, `write()`, `lseek()`, and `close()`.

---

## Commands Executed

### 1. Create the source file

```bash
nano employee_records.c
```

**Explanation:**
Created the C source file to implement the required file-processing utility using Linux system calls.

---

### 2. Display the source code

```bash
cat employee_records.c
```

**Explanation:**
Displayed the source code to verify that the program was saved correctly.

---

### 3. Compile the program

```bash
gcc employee_records.c -o employee_records
```

**Explanation:**
Compiled the C source file and generated an executable named `employee_records`.

---

### 4. Execute the program

```bash
./employee_records
```

**Explanation:**
Executed the program to create the employee file, write records, update a specific record, and display all employee records.

---

### 5. Verify generated files

```bash
ls -l
```

**Explanation:**
Confirmed that the executable, source file, and binary data file were created successfully.

---

### 6. Check the file type

```bash
file employee.dat
```

**Explanation:**
Verified that `employee.dat` is a binary data file containing employee records.

---

## Linux System Calls Used

### open()

Creates and opens the employee data file with read and write permissions.

### write()

Stores employee records into the file.

### lseek()

Moves the file pointer directly to the second employee record so that only that record is updated.

### read()

Retrieves employee records from the file for display.

### close()

Closes the file and releases system resources.

---

## How the Program Works

The program creates a binary file named `employee.dat` and writes three employee records into it.

It then uses `lseek()` to move directly to the second record and updates only that record without rewriting the entire file. Finally, it reads all records using `read()` and displays them on the screen.

---

## Sample Output

```
Employee records written successfully.
Second employee record updated.

Employee Records:

ID     : 101
Name   : Anshuman Gupta
Salary : 50000.00

ID     : 102
Name   : Rahul Sharma
Salary : 65000.00

ID     : 103
Name   : Shreya Gupta
Salary : 60000.00
```

---

## Screenshots

Include screenshots of:

- Creating the source file.
- Compiling the program.
- Running the program.
- Displaying the output.
- Verifying the generated files.

