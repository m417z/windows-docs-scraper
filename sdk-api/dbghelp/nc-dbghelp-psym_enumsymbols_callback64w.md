# PSYM_ENUMSYMBOLS_CALLBACK64W callback function

## Description

An application-defined callback function used with the
[SymEnumerateSymbols64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumeratesymbols) function. It is called once for each enumerated symbol, and receives the symbol information.

The **PSYM_ENUMSYMBOLS_CALLBACK64** and **PSYM_ENUMSYMBOLS_CALLBACK64W** types define a pointer to this callback function.
**SymEnumerateSymbolsProc64** is a placeholder for the application-defined function name.

**Note** This function is provided only for compatibility. Applications should use
[SymEnumSymbols](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumsymbols).

## Parameters

### `SymbolName` [in]

The name of the symbol. The name can be undecorated if the SYMOPT_UNDNAME option is used with the
[SymSetOptions](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsetoptions) function.

### `SymbolAddress` [in]

The virtual address for the beginning of the symbol.

### `SymbolSize` [in]

The size of the symbol, in bytes. The size is calculated and is actually a best-guess value. In some cases, the value can be zero.

### `UserContext` [in, optional]

The user-defined value specified in
[SymEnumerateSymbols64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumeratesymbols), or **NULL**. Typically, this parameter is used by an application to pass a pointer to a data structure that lets the callback function establish some type of context.

## Return value

If the function returns **TRUE**, the enumeration will continue.

If the function returns **FALSE**, the enumeration will stop.

## Remarks

The calling application is called once per symbol until all the symbols are enumerated or until the enumeration callback function returns **FALSE**.

This callback function supersedes the *PSYM_ENUMSYMBOLS_CALLBACK* callback function. *PSYM_ENUMSYMBOLS_CALLBACK* is defined as follows in Dbghelp.h.

```cpp
#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define PSYM_ENUMSYMBOLS_CALLBACK PSYM_ENUMSYMBOLS_CALLBACK64
#define PSYM_ENUMSYMBOLS_CALLBACKW PSYM_ENUMSYMBOLS_CALLBACK64W
#else
typedef BOOL
(CALLBACK *PSYM_ENUMSYMBOLS_CALLBACK)(
    __in PCSTR SymbolName,
    __in ULONG SymbolAddress,
    __in ULONG SymbolSize,
    __in_opt PVOID UserContext
    );

typedef BOOL
(CALLBACK *PSYM_ENUMSYMBOLS_CALLBACKW)(
    __in PCWSTR SymbolName,
    __in ULONG SymbolAddress,
    __in ULONG SymbolSize,
    __in_opt PVOID UserContext
    );
#endif
```

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[SymEnumSymbols](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumsymbols)

[SymEnumerateSymbols64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumeratesymbols)