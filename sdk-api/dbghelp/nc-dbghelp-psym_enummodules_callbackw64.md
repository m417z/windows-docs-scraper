# PSYM_ENUMMODULES_CALLBACKW64 callback function

## Description

An application-defined callback function used with the
[SymEnumerateModules64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumeratemodules) function. It is called once for each enumerated module, and receives the module information.

The **PSYM_ENUMMODULES_CALLBACK64** and **PSYM_ENUMMODULES_CALLBACKW64** types define a pointer to this callback function.
**SymEnumerateModulesProc64** is a placeholder for the application-defined function name.

## Parameters

### `ModuleName` [in]

The name of the module.

### `BaseOfDll` [in]

The base address where the module is loaded into memory.

### `UserContext` [in, optional]

The user-defined value specified in
[SymEnumerateModules64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumeratemodules), or **NULL**. Typically, this parameter is used by an application to pass a pointer to a data structure that lets the callback function establish some type of context.

## Return value

If the return value is **TRUE**, the enumeration will continue.

If the return value is **FALSE**, the enumeration will stop.

## Remarks

The calling application is called once per module until all modules are enumerated, or until the enumeration callback function returns **FALSE**.

This callback function supersedes the *PSYM_ENUMMODULES_CALLBACK* callback function. *PSYM_ENUMMODULES_CALLBACK* is defined as follows in DbgHelp.h.

```cpp
#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define PSYM_ENUMMODULES_CALLBACK PSYM_ENUMMODULES_CALLBACK64
#else
typedef BOOL
(CALLBACK *PSYM_ENUMMODULES_CALLBACK)(
    __in PCSTR ModuleName,
    __in ULONG BaseOfDll,
    __in_opt PVOID UserContext
    );
#endif
```

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[SymEnumerateModules64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumeratemodules)