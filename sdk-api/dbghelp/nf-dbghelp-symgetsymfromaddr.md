# SymGetSymFromAddr function

## Description

Locates the symbol for the specified address.

**Note** This function is provided only for compatibility. Applications should use
[SymFromAddr](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symfromaddr).

## Parameters

### `hProcess` [in]

A handle to the process that was originally passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `dwAddr` [in]

The address for which a symbol is to be located. The address does not have to be on a symbol boundary. If the address comes after the beginning of a symbol and before the end of the symbol (the beginning of the symbol plus the symbol size), the symbol is found.

### `pdwDisplacement` [out, optional]

The displacement from the beginning of the symbol, or zero.

### `Symbol` [in, out]

A pointer to an
[IMAGEHLP_SYMBOL64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_symbol) structure.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**SymGetSymFromAddr64** function locates the symbol for a specified address. The modules are searched for the one the address belongs to. When the module is found, its symbol table is searched for a match. When the symbol is found, the symbol information is copied into the *Symbol* buffer provided by the caller. The caller must allocate the *Symbol* buffer properly and fill in the required parameters in the
[IMAGEHLP_SYMBOL64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_symbol) structure before calling
**SymGetSymFromAddr64**.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

This function supersedes the **SymGetSymFromAddr** function. For more information, see
[Updated Platform Support](https://learn.microsoft.com/windows/desktop/Debug/updated-platform-support). **SymGetSymFromAddr** is defined as follows in Dbghelp.h.

```cpp
#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define SymGetSymFromAddr SymGetSymFromAddr64
#else
BOOL
IMAGEAPI
SymGetSymFromAddr(
    __in HANDLE hProcess,
    __in DWORD dwAddr,
    __out_opt PDWORD pdwDisplacement,
    __inout PIMAGEHLP_SYMBOL Symbol
    );
#endif
```

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[IMAGEHLP_SYMBOL64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_symbol)

[SymFromAddr](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symfromaddr)

[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize)