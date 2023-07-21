# Tiny-Shell

Recreated a Linux shell enabled with basic commands, namely:

- ls
- pwd
- echo
- exit

using C.

## Preview

Here is a video depicting the usage:

https://github.com/arsh-tripathi/Tiny-Shell/assets/110033985/008dc929-09b6-48d0-8950-5214ccbffe57

## Requirements

To build from source you will require a C compiler such as gcc.
A shell.exe file can be requested via mail, just ask at arsht2004@gmail.com

## Installation and Compilation
First, clone the repository on our environment. Then you can compile the files using any of these methods:

1. Using the Makefile

This will also require make to be installed on your system
To make it using the Make file, install the Makefile and preserve the structure of the repository then run
```
make
```

and to clean the build run
```
make clean
```

2. Make.sh Script

You can also check out my Make.sh script which requires a bash interpreter to compile the project.

Simply install the script and place it in the folder and run the commands
```
chmod a+x make
./make ./ shell
```
And it will create the executable in a bin folder and run it.


## Usage

To start the shell simply run the executable in the terminal using the command
```
./shell.exe STARTING_PATH
```
where the starting path is the path you want to run the commands at.
If not specified, it will run at C:\\Users

### Commands

There are a few commands available:

1. echo: Used to write following words on to the terminal
```
echo words to write
```
2. pwd: Used to echo the current directory
```
pwd
```
3. ls: Used to list the files and directories in the current directory
```
// To simply list the files and directories
ls
// List hidden directories/files
ls -a
// List on seperate lines
ls -l
// Combination
ls -al
```
4. exit: Used to close the program
```
exit
```

For any suggestions kindly create an issue in this repository, or mail them to me at: arsht2004@gmail.com
