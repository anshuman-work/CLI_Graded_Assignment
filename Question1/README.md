# Question 1 - Duplicate Submission Detection and Backup

## Objective

Design a shell script to:

- Identify duplicate assignment submissions.
- Create a backup of unique submissions.
- Generate a report showing processed, duplicate, and backed-up files.
- Store all error messages separately.

---

## Commands Executed

### 1. Create the project folder

```bash
mkdir CLI_Graded_Assignment
```

**Explanation:**
Creates the main directory to store all assignment files.

---

### 2. Enter the project directory

```bash
cd CLI_Graded_Assignment
```

**Explanation:**
Moves into the project directory where all work is performed.

---

### 3. Create Question1 folder

```bash
mkdir Question1
```

**Explanation:**
Creates a dedicated folder for Question 1.

---

### 4. Create required folders

```bash
mkdir submissions backup screenshots
```

**Explanation:**
Creates separate directories for submissions, backup files, and screenshots.

---

### 5. Create sample submission files

```bash
echo "..." > submissions/filename.txt
```

**Explanation:**
Creates sample student assignment files for testing.

---

### 6. Create a duplicate file

```bash
cp submissions/Anshuman_Gupta_Assignment.txt submissions/Anshuman_Gupta_Assignment_Copy.txt
```

**Explanation:**
Creates a duplicate submission to test duplicate detection.

---

### 7. Make the script executable

```bash
chmod +x duplicate_backup.sh
```

**Explanation:**
Grants execute permission to the shell script.

---

### 8. Execute the script

```bash
./duplicate_backup.sh
```

**Explanation:**
Runs the script to detect duplicate submissions, back up unique files, and generate the report.

---

### 9. Display the report

```bash
cat duplicate_report.txt
```

**Explanation:**
Displays the generated report showing processed, duplicate, and backed-up files.

---

### 10. View the error log

```bash
cat error.log
```

**Explanation:**
Displays any errors generated during execution. The file remained empty because no errors occurred.

---

### 11. Display backup files

```bash
ls backup
```

**Explanation:**
Lists the files successfully backed up.

---

## Justification of Linux Commands

| Command | Purpose |
|----------|---------|
| mkdir | Creates directories |
| cd | Changes the current directory |
| echo | Creates sample files |
| cp | Copies unique files into the backup directory |
| sha256sum | Generates a unique hash to detect duplicate files |
| awk | Extracts only the hash value |
| basename | Displays only the filename without the path |
| cat | Displays file contents |
| chmod | Grants execute permission |
| ls | Lists directory contents |

---

## Redirection Operators

| Operator | Purpose |
|----------|---------|
| > | Creates or overwrites a file |
| >> | Appends data to a file |
| 2>> | Redirects error messages to a separate file |

---

## File Handling Techniques

- Reading files using a loop.
- Comparing file contents using SHA-256 hashes.
- Copying unique files using `cp`.
- Writing reports using output redirection.
- Logging errors separately.
- Using associative arrays to store processed file hashes.

---

## Output Summary

- Files Processed: 4
- Duplicate Files: 1
- Files Backed Up: 3

---

## Screenshots

Screenshots of all commands and outputs are available in the `screenshots` folder.
