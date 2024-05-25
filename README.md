# C++ dll

A Basic Program on using C++ Dynamic Link Library
this is a basic refferece for using dll on c++

## Explenation

### DLL Temp

```cpp
#include "./includes/mydll.h"
#include <iostream>

void hello() {
    std::cout << "Hello from the DLL!" << std::endl;
}

```

### DLL Header

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

#endif // MYDLL_H

```

### Compiler Command

## compile dll
```bat
g++ -shared -o mydll.dll mydll.cpp -Wl,--out-implib,libmydll.a
```

### compile program
```bat
g++ -o myprog main.cpp -L . -l mydll
```