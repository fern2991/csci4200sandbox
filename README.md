
# CSCI 4200 Computer Architecture

This will be the area to use in lab to write, compile, and run code to explore and reinforce
concepts taught in class.

## GCC Compiler Cheat Sheet (Basic C Programs)

A quick guide on how to turn your C source code into a program you can actually run.

---

### The 2-Step Workflow

To run a C program in Linux, you always do two things: **Compile** it, then **Run** it.

#### 1. Compile the Code
* **`gcc filename.c`**
  * *What it does:* Compiles your C file. If it succeeds, it creates a default runnable file named `a.out`.
* **`gcc filename.c -o program_name`**
  * *What it does:* Compiles your file and names the output whatever you put after the `-o` flag (e.g., `gcc main.c -o myprogram`).
  * *Tip:* **Always** use `-o` so you don't overwrite `a.out` every time!

#### 2. Run the Program
* **`./a.out`**
  * *What it does:* Runs the default output file. 
* **`./program_name`**
  * *What it does:* Runs your custom-named program.
  * *Note:* The `./` tells Linux to look for the program inside your *current* folder.

---

### Catching Mistakes Early (Highly Recommended)

* **`gcc -Wall filename.c -o program_name`**
  * *What it does:* Enables **W**arn **all**. This forces `gcc` to print warnings for risky code that might crash later, even if it is technically valid C syntax.
  * *Tip:* Always use `-Wall` to find bugs before running their code!

---

### Reading GCC Errors

When `gcc` prints text after you try to compile, don't panic! Read it like a map:

> **`main.c:5:10: error: expected ';' before 'return'`**

* **`main.c`** = The file with the mistake.
* **`5`** = The line number where `gcc` got confused.
* **`10`** = The character character column on that line.
* **`error:...`** = Exactly what went wrong.

---

### Pro-Tips for Students

* **No news is good news:** If you type `gcc main.c` and the terminal just gives you a blank line, **it worked perfectly!** Linux only talks to you during compilation if there is a warning or an error.
* **Stuck in a loop?** If your program runs and gets stuck in an infinite loop, press **`Ctrl + C`** in your terminal to forcefully stop it.

---

## Basic Linux Command Cheat Sheet

A quick reference guide for essential Linux commands.

---

### Navigating Directories

* **`pwd`** — Print Working Directory
  * *What it does:* Shows the exact folder you are currently inside.
* **`ls`** — List Files
  * *What it does:* Shows a list of all files and folders in your current directory.
  * *Tip:* Use `ls -l` to see extra details like file size and permissions.
* **`cd [folder_name]`** — Change Directory
  * *What it does:* Moves you into a specific folder.
  * *Tip:* Type `cd ..` to go backward up one folder level.

---

### Managing Files & Folders

* **`mkdir [folder_name]`** — Make Directory
  * *What it does:* Creates a brand new, empty folder.
* **`touch [file_name]`** — Create File
  * *What it does:* Creates a blank, empty file (e.g., `touch notes.txt`).
* **`cp [source] [destination]`** — Copy
  * *What it does:* Duplicates a file or folder to a new location.
* **`mv [source] [destination]`** — Move or Rename
  * *What it does:* Moves a file to a new folder, or changes its name.
* **`rm [file_name]`** — Remove
  * *What it does:* Deletes a file permanently.
  * *Warning:* Linux does not have a trash bin. Deleted files are gone instantly!
