# C++ dll

A Basic Program on using C++ Dynamic Link Library
this is a basic refferece for using dll on c++

## Explenation

### DLL Temp

Here is the code for the dll name it into mydll.cpp

```cpp
#include "./includes/mydll.h"
#include <iostream>

void hello() {
    std::cout << "Hello from the DLL!" << std::endl;
}

```

### DLL Header

Here is the code for the dll header file and name it into mydll.h

```h
#ifndef MYDLL_H
#define MYDLL_H

#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

extern "C" {
    //Put all the function here
    DLL_EXPORT void hello();
}

#endif

```

### Compiler Command

## compile dll
```bat
g++ -shared -o mydll.dll mydll.cpp -Wl,--out-implib,libmydll.a
```

This command does the following:

- -shared tells the compiler to create a shared library.

- -o mydll.dll specifies the output file name.

- -Wl,--out-implib,libmydll.a creates an import library libmydll.a which is necessary for linking against the DLL in another project.

### compile program
```bat
g++ -o myprog main.cpp -L . -l mydll
```

This command does the following:

- -L . tells the compiler to look for libraries code the argument "." is telling the compiler to search in the current directory.

- -l mydll tells the compiler to link against libmydll.a (the import library).