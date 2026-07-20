# Question 5 - Recovery Mechanisms in vi Editor

## Objective

Evaluate the recovery mechanisms available in the **vi** editor when a system crashes before a file is saved. Recommend the most reliable recovery strategy with proper justification.

---

## Recovery Mechanisms in vi

### 1. Swap Files

- vi automatically creates a swap file while editing.
- If the editor or system crashes, the swap file stores unsaved changes.
- The file can usually be recovered using:

```bash
vi -r filename
```

---

### 2. Undo History

- The undo feature allows recently made changes to be reversed.
- It is useful only while the editing session is still active.
- After a crash, the undo history is generally unavailable.

---

### 3. Registers

- Registers temporarily store deleted or copied text.
- They help recover small pieces of text during an editing session.
- Registers cannot recover an entire file after a crash.

---

### 4. Backup Files

- Backup files store a previously saved version of the file.
- They protect against accidental modifications.
- However, they do not contain the latest unsaved changes.

---

### 5. Auto-Recovery

- vi automatically detects swap files after an unexpected shutdown.
- It prompts the user to recover the file during the next editing session.
- This mechanism restores most unsaved work.

---

## Most Reliable Recovery Strategy

The most reliable recovery strategy is to use **swap files together with vi's auto-recovery feature**.

When the system crashes, the swap file preserves unsaved changes. Opening the file with `vi -r filename` or accepting the recovery prompt restores the editing session with minimal data loss.

Regularly saving the file using `:w` further reduces the possibility of losing important work.

---

## Justification

- Swap files preserve unsaved changes automatically.
- Auto-recovery simplifies the restoration process.
- Backup files provide an additional copy of previously saved data.
- Undo history and registers are useful only during an active editing session.
- Combining swap files, auto-recovery, and frequent saving provides the safest recovery strategy.

---

## Conclusion

Among all available recovery mechanisms, **swap files combined with vi auto-recovery** offer the most effective solution because they automatically preserve unsaved work and allow recovery after unexpected system failures.
