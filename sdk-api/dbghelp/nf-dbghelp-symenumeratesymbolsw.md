# SymEnumerateSymbolsW function

## Description

Enumerates all the symbols for a specified module.

**Note** This function is provided only for compatibility. Applications should use
[SymEnumSymbols](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumsymbols), which is faster and more powerful.

## Parameters

### `hProcess` [in]

A handle to the process. This handle must have been previously passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `BaseOfDll` [in]

The base address of the module for which symbols are to be enumerated.

### `EnumSymbolsCallback` [in]

The callback function that receives the symbol information. For more information, see
[SymEnumerateSymbolsProc64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-psym_enumsymbols_callback).

### `UserContext` [in, optional]

A user-defined value or **NULL**. This value is passed to the callback function. Typically, this parameter is used by an application to pass a pointer to a data structure that enables the callback function establish some type of context.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**SymEnumerateSymbols64** function enumerates all the symbols for the specified module. The module information is located by the *BaseOfDll* parameter. The callback function is called once per symbol and is passed the information for each symbol.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

The Unicode version of this function, **SymEnumerateSymbolsW64** is defined as follows in Dbghelp.h.

```cpp

BOOL
IMAGEAPI
SymEnumerateSymbolsW64(
    __in HANDLE hProcess,
    __in ULONG64 BaseOfDll,
    __in PSYM_ENUMSYMBOLS_CALLBACK64W EnumSymbolsCallback,
    __in_opt PVOID UserContext
    );
```

This function supersedes the **SymEnumerateSymbols** function. For more information, see
[Updated Platform Support](https://learn.microsoft.com/windows/desktop/Debug/updated-platform-support). **SymEnumerateSymbols** is defined as follows in Dbghelp.h.

```cpp
#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define SymEnumerateSymbols SymEnumerateSymbols64
#define SymEnumerateSymbolsW SymEnumerateSymbolsW64
#else
BOOL
IMAGEAPI
SymEnumerateSymbols(
    __in HANDLE hProcess,
    __in ULONG BaseOfDll,
    __in PSYM_ENUMSYMBOLS_CALLBACK EnumSymbolsCallback,
    __in_opt PVOID UserContext
    );

BOOL
IMAGEAPI
SymEnumerateSymbolsW(
    __in HANDLE hProcess,
    __in ULONG BaseOfDll,
    __in PSYM_ENUMSYMBOLS_CALLBACKW EnumSymbolsCallback,
    __in_opt PVOID UserContext
    );
#endif
```

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[SymEnumSymbols](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumsymbols)

[SymEnumerateSymbolsProc64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-psym_enumsymbols_callback)

[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize)