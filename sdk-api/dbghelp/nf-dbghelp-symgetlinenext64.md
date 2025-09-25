# SymGetLineNext64 function

## Description

Retrieves the line information for the next source line.

## Parameters

### `hProcess` [in]

A handle to the process that was originally passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `Line` [in, out]

A pointer to an
[IMAGEHLP_LINE64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_line) structure that contains the line information.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**SymGetLineNext64** function requires that the
[IMAGEHLP_LINE64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_line) structure have valid data, presumably obtained from a call to the
[SymGetLineFromAddr64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetlinefromaddr) or
[SymGetLineFromName64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetlinefromname) function. This structure receives the line information for the next line in sequence.

This function returns a pointer to a buffer that may be reused by another function. Therefore, be sure to copy the data returned to another buffer immediately.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

To call the Unicode version of this function, define DBGHELP_TRANSLATE_TCHAR. **SymGetLineNextW64** is defined as follows in Dbghelp.h.

```cpp

BOOL
IMAGEAPI
SymGetLineNextW64(
    __in HANDLE hProcess,
    __inout PIMAGEHLP_LINEW64 Line

#ifdef DBGHELP_TRANSLATE_TCHAR
#define SymGetLineNext64  SymGetLineNextW64
#endif
```

This function supersedes the **SymGetLineNext** function. For more information, see
[Updated Platform Support](https://learn.microsoft.com/windows/desktop/Debug/updated-platform-support). **SymGetLineNext** is defined as follows in Dbghelp.h.

```cpp
#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define SymGetLineNext SymGetLineNext64
#else
BOOL
IMAGEAPI
SymGetLineNext(
    __in HANDLE hProcess,
    __inout PIMAGEHLP_LINE Line
    );

BOOL
IMAGEAPI
SymGetLineNextW(
    __in HANDLE hProcess,
    __inout PIMAGEHLP_LINEW Line
    );
#endif
```

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[IMAGEHLP_LINE64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_line)

[SymGetLineFromAddr64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetlinefromaddr)

[SymGetLineFromName64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetlinefromname)

[SymGetLinePrev64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetlineprev)

[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize)