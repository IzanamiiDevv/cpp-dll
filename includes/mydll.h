#ifndef MYDLL_H
#define MYDLL_H

#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

extern "C" {
    DLL_EXPORT void hello();
}

#endif // MYDLL_H
