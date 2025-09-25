# SymGetLinePrev function

## Description

Retrieves the line information for the previous source line.

## Parameters

### `hProcess` [in]

A handle to the process that was originally passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `Line` [in, out]

A pointer to an
[IMAGEHLP_LINE64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_line) structure.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**SymGetLinePrev64** function requires that the
[IMAGEHLP_LINE64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_line) structure have valid data, presumably obtained from a call to the
[SymGetLineFromAddr64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetlinefromaddr) or
[SymGetLineFromName64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetlinefromname) function. This structure is filled with the line information for the previous line in sequence.

This function returns a pointer to a buffer that may be reused by another function. Therefore, be sure to copy the data returned to another buffer immediately.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

To call the Unicode version of this function, define DBGHELP_TRANSLATE_TCHAR. **SymGetLinePrevW64** is defined as follows in DbgHelp.h.

```cpp
BOOL
IMAGEAPI
SymGetLinePrevW64(
    __in HANDLE hProcess,
    __inout PIMAGEHLP_LINEW64 Line
    );

#ifdef DBGHELP_TRANSLATE_TCHAR
#define SymGetLinePrev64    SymGetLinePrevW64
#endif
```

This function supersedes the **SymGetLinePrev** function. For more information, see
[Updated Platform Support](https://learn.microsoft.com/windows/desktop/Debug/updated-platform-support). **SymGetLinePrev** is defined as follows in DbgHelp.h.

```cpp
#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define SymGetLinePrev SymGetLinePrev64
#else
BOOL
IMAGEAPI
SymGetLinePrev(
    __in HANDLE hProcess,
    __inout PIMAGEHLP_LINE Line
    );

BOOL
IMAGEAPI
SymGetLinePrevW(
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

[SymGetLineNext64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetlinenext)

[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize)