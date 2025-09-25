# SymGetSymPrev64 function

## Description

Retrieves the symbol information for the previous symbol.

**Note** This function is provided only for compatibility. Applications should use
[SymPrev](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symprev).

## Parameters

### `hProcess` [in]

A handle to the process that was originally passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `Symbol` [in, out]

A pointer to an
[IMAGEHLP_SYMBOL64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_symbol) structure.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**SymGetSymPrev64** function requires the [IMAGEHLP_SYMBOL64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_symbol) structure to have valid data, presumably obtained from a call to the
[SymGetSymFromAddr64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetsymfromaddr) or
[SymGetSymFromName64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetsymfromname) function. This structure is filled in with the symbol information for the previous symbol in sequence by virtual address.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

To call the Unicode version of this function, define DBGHELP_TRANSLATE_TCHAR. **SymGetSymPrevW64** is defined as follows in DbgHelp.h.

```cpp
BOOL
IMAGEAPI
SymGetSymPrevW64(
    __in HANDLE hProcess,
    __inout PIMAGEHLP_SYMBOLW64 Symbol
    );
```

This function supersedes the **SymGetSymPrev** function. For more information, see
[Updated Platform Support](https://learn.microsoft.com/windows/desktop/Debug/updated-platform-support). **SymGetSymPrev** is defined as follows in Dbghelp.h.

```cpp
#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define SymGetSymPrev SymGetSymPrev64
#define SymGetSymPrevW SymGetSymPrevW64
#else
BOOL
IMAGEAPI
SymGetSymPrev(
    __in HANDLE hProcess,
    __inout PIMAGEHLP_SYMBOL Symbol
    );

BOOL
IMAGEAPI
SymGetSymPrevW(
    __in HANDLE hProcess,
    __inout PIMAGEHLP_SYMBOLW Symbol
    );
#endif
```

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[IMAGEHLP_SYMBOL64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_symbol)

[SymGetSymFromAddr64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetsymfromaddr)

[SymGetSymFromName64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetsymfromname)

[SymGetSymNext64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetsymnext)

[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize)