# Simple Shell - C Programming low level🏁
__________________________________________________________________________________

this project is a ***simple Shell***, It is a program that functions as a command interface to users in which they can access the kernel as a command interpreter.

# Use the Shell

Clone the repository **holbertonschool-simple_shell** 

`git clone https://github.com/alejandrodgz/holbertonschool-simple_shell.git`

Change to the directory **holbertonschool-simple_shell**

`cd /holbertonschool-simple_shell`

After this, you need to create the executable file compiling the code, for this is the ***Makefile*** file, compile and execute the the shell at the same time.

`$ make -f Makefile`

and now you're in the **Simple Shell**

Note: if you want to exit from the Shell use the next command:
`$ exit`
______________________________________________________________________________________
# Usage

The shell has two modes: The **interactive mode** in which the shell takes the commands from the STDIN (Standar Input) executes them and gets ready to read another comand line inside the shell until you exit from it

This is an example where you can use the ls -la command for listing files in the current directories in table format with aditional information

`$ ls -la`
`drwxr-xr-x  6 jehp jehp  4096 Aug 18 22:02 .`
`drwxr-xr-x 10 jehp jehp  4096 Aug  9 20:10 ..`
`drwxr-xr-x  2 jehp jehp  4096 Aug 16 16:31 alejosource`
`-rw-r--r--  1 jehp jehp  1402 Aug 18 13:28 _atoi.c`
`drwxr-xr-x  2 jehp jehp  4096 Aug 16 14:27 backupcode`
`-rw-r--r--  1 jehp jehp  1454 Aug 18 13:28 builts_in_com.c`
`-rw-r--r--  1 jehp jehp  2525 Aug 18 13:28 enviroment.c`
`-rw-r--r--  1 jehp jehp  1160 Aug 16 16:01 Error_hand.c`
`drwxr-xr-x  8 jehp jehp  4096 Aug 18 17:07 .git`
`-rwxr-xr-x  1 jehp jehp 22792 Aug 18 17:04 hsh`
`-rw-r--r--  1 jehp jehp   154 Aug 16 12:55 Makefile`
`-rw-r--r--  1 jehp jehp  2251 Aug 18 13:28 man_1_simpleShell`
`-rw-r--r--  1 jehp jehp  1868 Aug 18 13:28 man_1_simpleShell~`
`-rw-r--r--  1 jehp jehp   554 Aug 18 13:28 prints.c`
`-rw-r--r--  1 jehp jehp  1697 Aug 18 17:02 prompt.c`
`-rw-r--r--  1 jehp jehp    12 Aug 16 12:52 README.md`
`-rw-r--r--  1 jehp jehp  2040 Aug 18 16:38 Shell_executable.c`
`-rw-r--r--  1 jehp jehp  1775 Aug 18 16:55 shell.h`
`-rw-r--r--  1 jehp jehp  2150 Aug 16 14:27 strings.c`
`-rw-r--r--  1 jehp jehp  1128 Aug 16 14:27 token.c`
`-rw-r--r--  1 jehp jehp  1219 Aug 16 14:28 token_string.c`
`drwxr-xr-x  2 jehp jehp  4096 Aug 18 22:03 .vscode`
`$ `


Another and last mode is the **non-interactive** and say that you can the **Simple Shell** outsite from the executable
`echo 'ls -la' | ./hsh`
 `drwxr-xr-x  6 jehp jehp  4096 Aug 18 22:02 .`
`drwxr-xr-x 10 jehp jehp  4096 Aug  9 20:10 ..`
`drwxr-xr-x  2 jehp jehp  4096 Aug 16 16:31 alejosource`
`drwxr-xr-x  2 jehp jehp  4096 Aug 16 14:27 backupcode`
`-rw-r--r--  1 jehp jehp  1454 Aug 18 13:28 builts_in_com.c`
`-rw-r--r--  1 jehp jehp  2525 Aug 18 13:28 enviroment.c`
`-rw-r--r--  1 jehp jehp  1160 Aug 16 16:01 Error_hand.c`
`drwxr-xr-x  8 jehp jehp  4096 Aug 18 17:07 .git`
`-rwxr-xr-x  1 jehp jehp 22792 Aug 18 17:04 hsh`
`-rw-r--r--  1 jehp jehp   154 Aug 16 12:55 Makefile`
`-rw-r--r--  1 jehp jehp  2251 Aug 18 13:28 man_1_simpleShell`
`-rw-r--r--  1 jehp jehp  1868 Aug 18 13:28 man_1_simpleShell~`
`-rw-r--r--  1 jehp jehp   554 Aug 18 13:28 prints.c`
`-rw-r--r--  1 jehp jehp  1697 Aug 18 17:02 prompt.c`
`-rw-r--r--  1 jehp jehp    12 Aug 16 12:52 README.md`
`-rw-r--r--  1 jehp jehp  2040 Aug 18 16:38 Shell_executable.c`
`-rw-r--r--  1 jehp jehp  1775 Aug 18 16:55 shell.h`
`-rw-r--r--  1 jehp jehp  2150 Aug 16 14:27 strings.c`
`-rw-r--r--  1 jehp jehp  1128 Aug 16 14:27 token.c`
`-rw-r--r--  1 jehp jehp  1219 Aug 16 14:28 token_string.c`
`drwxr-xr-x  2 jehp jehp  4096 Aug 18 22:03 .vscode`
`$ `
_____________________________________________________________________________________
# The Algorithm of prompt's proccess and executable's proccess

![Algorithm](file:///home/jehp/Downloads/SIMPLE_SHELL.png)

# Manual

In the directory there is a file with a manual page, you can run it like this:

`$ man ./man_1_simpleShell`

Now you can see the manual Shell.
______________________________________________________________________________________

# File Descriptions

-------------------------------------------------------------------------------------
| FILE |                          DESCRIPTION                                        |
|

