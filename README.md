
# DirectoryAccessChecker

This program gets a directory path from user, checks it and blocks for other instances of itself.

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
