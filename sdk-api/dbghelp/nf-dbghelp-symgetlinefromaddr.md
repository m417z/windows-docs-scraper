# SymGetLineFromAddr function

## Description

Locates the source line for the specified address.

## Parameters

### `hProcess` [in]

A handle to the process that was originally passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `dwAddr` [in]

The address for which a line should be located. It is not necessary for the address to be on a line
boundary. If the address appears after the beginning of a line and before the end of the line, the line is
found.

### `pdwDisplacement` [out]

The displacement in bytes from the beginning of the line, or zero.

### `Line` [out]

A pointer to an [IMAGEHLP_LINE64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_line)
structure.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error
information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The caller must allocate the *Line* buffer properly and fill in the required members
of the [IMAGEHLP_LINE64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_line) structure before
calling **SymGetLineFromAddr64**.

This function returns a pointer to a buffer that may be reused by another function. Therefore, be sure to copy
the data returned to another buffer immediately.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to
this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize
all concurrent calls from more than one thread to this function.

To call the Unicode version of this function, define **DBGHELP_TRANSLATE_TCHAR**.
**SymGetLineFromAddrW64** is defined as follows in
Dbghelp.h.

```cpp
BOOL
IMAGEAPI
SymGetLineFromAddrW64(
    _In_ HANDLE hProcess,
    _In_ DWORD64 dwAddr,
    _Out_ PDWORD pdwDisplacement,
    _Out_ PIMAGEHLP_LINEW64 Line
    );

#ifdef DBGHELP_TRANSLATE_TCHAR
 #define SymGetLineFromAddr64   SymGetLineFromAddrW64
#endif
```

This function supersedes the **SymGetLineFromAddr** function. For more information, see
[Updated Platform Support](https://learn.microsoft.com/windows/desktop/Debug/updated-platform-support). **SymGetLineFromAddr** is defined as follows in Dbghelp.h.

```cpp
#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define SymGetLineFromAddr SymGetLineFromAddr64
#define SymGetLineFromAddrW SymGetLineFromAddrW64
#else
BOOL
IMAGEAPI
SymGetLineFromAddr(
    _In_ HANDLE hProcess,
    _In_ DWORD dwAddr,
    _Out_ PDWORD pdwDisplacement,
    _Out_ PIMAGEHLP_LINE Line
    );

BOOL
IMAGEAPI
SymGetLineFromAddrW(
    _In_ HANDLE hProcess,
    _In_ DWORD dwAddr,
    _Out_ PDWORD pdwDisplacement,
    _Out_ PIMAGEHLP_LINEW Line
    );
#endif
```

#### Examples

For an example, see
[Retrieving Symbol Information by Address](https://learn.microsoft.com/windows/desktop/Debug/retrieving-symbol-information-by-address).

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[IMAGEHLP_LINE64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_line)

[SymGetLineFromName64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetlinefromname)

[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize)