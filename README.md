
# DirectoryAccessChecker

This program gets a directory path from user, checks it and locks for other instances of itself.

## How to build DirectoryAccessChecker

Follow this instruction to clone the source code and build it:

```
git clone https://github.com/RodionShyshkin/DirectoryAccessChecker
cd DirectoryAccessChecker
mkdir -p cmake/build
cd cmake/build
cmake ../..
make
```

Program was successfully built. Well done! :)

## How to start using DirectoryAccessChecker

DirectoryAccessChecker uses a Server executable, so firstly you need to start it:

```
./Server
```

After that you can start using a program, all you need is to start its executable:

```
./DirectoryAccessChecker
```

That's it! Now you can use DirectoryAccessChecker.

## Available platforms

You can use DirectoryAccessChecker with any of MacOS/Linux/Windows platform due to 
the absence of system calls in the source code. Sounds good, right? :)

## Exit codes

Here is the list of possible values program can return and their meanings:

* Code 0 - Program was runned successfully without any errors;
* Code 1 - Entered path to a directory is not absolute;
* Code 2 - There are not any directory by entered path;
* Code 3 - There are no permission to write in directory;
* Code 4 - The directory is already locked by another program instance.
