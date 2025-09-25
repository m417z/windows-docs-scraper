# SymGetSymFromName64 function

## Description

Locates a symbol for the specified name.

**Note** This function is provided only for compatibility. Applications should use
[SymFromName](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symfromname).

## Parameters

### `hProcess` [in]

A handle to the process that was originally passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `Name` [in]

The symbol name for which a symbol is to be located.

### `Symbol` [in, out]

A pointer to an
[IMAGEHLP_SYMBOL64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_symbol) structure.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**SymGetSymFromName64** function is used to locate a symbol for a specified name. The name can contain a module prefix that isolates the symbol search to a single module's symbol table.

The module prefix is in the form of "*module*!". The "!" character is the delimiter between the module name and the symbol name. If there is no module prefix, then the search is performed on each module's symbol table in a linear manner, beginning with the first module that is loaded.

Using the module prefix is preferable for two reasons. First, the symbol search occurs much faster. Second, when deferred symbol loading is turned on, the search causes symbols to be loaded for each module that is searched. When the symbol is found, the symbol information is copied into the *Symbol* buffer provided by the caller. The caller must allocate the *Symbol* buffer properly and fill in the required parameters in the
[IMAGEHLP_SYMBOL64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_symbol) structure before calling
**SymGetSymFromName64**.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

This function supersedes the **SymGetSymFromName** function. For more information, see
[Updated Platform Support](https://learn.microsoft.com/windows/desktop/Debug/updated-platform-support). **SymGetSymFromName** is defined as follows in Dbghelp.h.

```cpp
#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define SymGetSymFromName SymGetSymFromName64
#else
BOOL
IMAGEAPI
SymGetSymFromName(
    __in HANDLE hProcess,
    __in PCSTR Name,
    __inout PIMAGEHLP_SYMBOL Symbol
    );
#endif
```

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[IMAGEHLP_SYMBOL64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_symbol)

[SymFromName](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symfromname)

[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize)