# SIMPLE SHELL

![](https://cdn.educba.com/academy/wp-content/uploads/2020/01/Bash-Shell-in-Linux.jpg)

## Description

The shell is a program that receives computer commands given by a user from his keyboard and sends them to the operating system, which will then execute them.

In the early days of computing, the shell was the only user interface available on a Unix-like system such as Linux. Nowadays and with the arrival of the mouse, all computers use graphical user interfaces (GUI) such as macOS or Windows 10, in addition to command line interfaces (CLI) such as the shell.
Here we have coded a simple shell that was asked in the holberton school curriculum.

## Requirements
### General

* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`
* All your files should end with a new line
* Your shell should not have any memory leaks
* No more than 5 functions per file

### About the Shell

* Display a prompt and wait for the user to type a command. A command line always ends with a new line.
* The prompt is displayed again each time a command has been executed.
* The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
* The command lines are made only of one word. No arguments will be passed to programs.
* If an executable cannot be found, print an error message and display the prompt again.
* Handle errors.
* You have to handle the “end of file” condition (`Ctrl+D`)
* Handle command lines with arguments
* Handle the `PATH`
* `fork` must not be called if the command doesn’t exist
* Implement the `exit` built-in, that exits the shell
* Usage: `exit`
* You don’t have to handle any argument to the built-in `exit`
* Implement the `env` **built-in**, that prints the current environment

## Flowchart

![Image](https://cdn.discordapp.com/attachments/1130060424310689853/1143911653738553416/diagram-simple-shell.jpg)

## File Usage

| Name File | Description |
| -------- | -------- |
| AUTHORS | Contains authors' names and github links. |
| emptyLine.c | Contains functions to determine if a string consists only of whitespace characters. |
| executeCMD.c | Provides a function to execute a command and wait for it to finish. |
| findPathInShell.c | Defines a function to find the full path of a command within the shell's PATH directories. |
| LICENSE | Contains MIT license for present files. |
| man_1_simple_shell.1 | User's manual. |
| README.md | File containing information about other files in the same directory. |
| shell.c | Implements a basic shell program with functions to print the prompt, tokenize input, handle "cd" commands, and execute external commands. The main function runs the shell's main loop. |
| shell.h | Header file with function declarations and includes needed for the shell program. |


## Compilation

You can compile your program using the following command.

`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

## Usage

Run the compiled shell by executing the following command :

`./hsh`

## How hsh works?

Initialization: When you run the program, the operating system loads the program into memory and starts executing the main function in the shell.c file.

Main loop: The program enters an infinite loop, indicated by while (1), where it waits for user input.

Display prompt: If the input comes from a terminal (checked with isatty(0)), the program displays the prompt ($ ), indicating that the user can enter a command.

Reading input: The program uses getline to read the user's input line. The input is stored in inputLine.

Command processing:

If the input is "exit", the program terminates by freeing memory and exiting the loop.
If the input is "env", the program calls the _env function to display environment variables.
If the input is not empty, the program uses splitStringByDelimiter to split the command and arguments, then uses findPathInShell to find the full path to the command. It then executes the command using executeCMD, which creates a child process to execute the command.
Result display: If the command has been executed successfully, the output status is updated and displayed. Otherwise, an error is displayed.

Continuous loop: The program continues to wait for further input from the user until the user enters "exit" or otherwise closes the program.

End of execution: When the user enters "exit" or closes the program, the main loop ends and the program terminates. Dynamically allocated memory is automatically freed by the operating system.

## Man Page

To display the manpage, please use the following command:

`man ./man_1_simple_shell.1`

## Check Memory Leaks

You can check memory leaks using the following command :

`valgrind ./hsh`
```bash
valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt \
         ./hsh
```

## Testing the programm

### Interactive mode

```bash
$ ls
AUTHORS         compareStrings.c     _env_.c     findPathInShell_.c
LICENSE         hsh     man_1_simple_shell.1     shell.c
README.md         splitStringByDelimiter.c     stringLenght.c     _calloc.c
emptyLine.c         executeCMD.c     _getenv.c     shell.h
stringCopy.c         stringsConcatenate.c
$
```
```bash
$ /bin/pwd
/Users/Documents/holbertonschool-simple_shell
$ exit
$
```
```bash
$ program
Error: No such file or directory
$
```
### Non Interactive mode

```bash
$ echo “env” | ./hsh
SHELL=/bin/bash
COLORTERM=truecolor
TERM_PROGRAM_VERSION=1.81.1
HOSTNAME=ba2226d54265
SSH_AUTH_SOCK=/tmp/vscode-ssh-auth-2db65e60-5366-4937-909a-04ae692aa2e9.sock
REMOTE_CONTAINERS_IPC=/tmp/vscode-remote-containers-ipc-2db65e60-5366-4937-909a-04ae692aa2e9.sock
PWD=/workspaces/Holberton_training/sans-commentaire
VSCODE_GIT_ASKPASS_NODE=/vscode/vscode-server/bin/linux-x64/6c3e3dba23e8fadc360aed75ce363ba185c49794/node
HOME=/home/vscode
LANG=en_US.UTF-8
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.webp=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:
REMOTE_CONTAINERS=true
GIT_ASKPASS=/vscode/vscode-server/bin/linux-x64/6c3e3dba23e8fadc360aed75ce363ba185c49794/extensions/git/dist/askpass.sh
VSCODE_GIT_ASKPASS_EXTRA_ARGS=
LESSCLOSE=/usr/bin/lesspipe %s %s
TERM=xterm-256color
REMOTE_CONTAINERS_SOCKETS=["/tmp/vscode-ssh-auth-2db65e60-5366-4937-909a-04ae692aa2e9.sock"]
LESSOPEN=| /usr/bin/lesspipe %s
USER=vscode
VSCODE_GIT_IPC_HANDLE=/tmp/vscode-git-6e2e50da64.sock
SHLVL=1
GIT_EDITOR=code --wait
PROMPT_DIRTRIM=4
VSCODE_GIT_ASKPASS_MAIN=/vscode/vscode-server/bin/linux-x64/6c3e3dba23e8fadc360aed75ce363ba185c49794/extensions/git/dist/askpass-main.js
BROWSER=/vscode/vscode-server/bin/linux-x64/6c3e3dba23e8fadc360aed75ce363ba185c49794/bin/helpers/browser.sh
PATH=/vscode/vscode-server/bin/linux-x64/6c3e3dba23e8fadc360aed75ce363ba185c49794/bin/remote-cli:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/home/vscode/.local/bin
OLDPWD=/workspaces/Holberton_training
TERM_PROGRAM=vscode
VSCODE_IPC_HOOK_CLI=/tmp/vscode-ipc-087659a5-f8a5-40df-a3f5-0cbaeb8d7115.sock
_=./hsh
$
```

## Bugs

We have currently problems on STDOUT outputs. Problems with memory management (allocation and freeing). And also PATH issues.

## Authors
#### TARTAR MICKAEL
- Github: [mickaeltartar](https://github.com/mickaeltartar)

#### BOUDIER CHRISTOPHE
- Github: [BIDcolonel](https://github.com/BIDcolonel)

## License

You can refer to the LICENSE file, it contains the following :

« Copyright © August 2023, Tartar Mickaël and Boudier Christophe.
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

The Software is provided “as is”, without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose and noninfringement. In no event shall the authors or copyright holders be liable for any claim, damages or other liability, whether in an action of contract, tort or otherwise, arising from, out of or in connection with the software or the use or other dealings in the Software.»
