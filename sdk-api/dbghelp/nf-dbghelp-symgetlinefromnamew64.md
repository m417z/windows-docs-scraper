# SymGetLineFromNameW64 function

## Description

Locates a source line for the specified module, file name, and line number.

## Parameters

### `hProcess` [in]

A handle to the process that was originally passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `ModuleName` [in, optional]

The name of the module in which a line is to be located.

### `FileName` [in, optional]

The name of the file in which a line is to be located. If the application has more than one source file with this name, be sure to specify a full path.

### `dwLineNumber` [in]

The line number to be located.

### `plDisplacement` [out]

The displacement in bytes from the beginning of the line, or zero.

### `Line` [in, out]

A pointer to an
[IMAGEHLP_LINE64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_line) structure.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The caller must allocate the *Line* buffer properly and fill in the required members of the
[IMAGEHLP_LINE64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_line) structure before calling
**SymGetLineFromName64**.

Before calling this function, ensure that the symbols are initialized correctly by first calling
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize),
[SymSetOptions](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsetoptions), and
[SymLoadModule64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symloadmodule).

This function returns a pointer to a buffer that may be reused by another function. Therefore, be sure to copy the data returned to another buffer immediately.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

To call the Unicode version of this function, define DBGHELP_TRANSLATE_TCHAR. **SymGetLineFromNameW64** is defined as follows in Dbghelp.h.

```cpp

BOOL
IMAGEAPI
SymGetLineFromNameW64(
    __in HANDLE hProcess,
    __in_opt PCWSTR ModuleName,
    __in_opt PCWSTR FileName,
    __in DWORD dwLineNumber,
    __out PLONG plDisplacement,
    __inout PIMAGEHLP_LINEW64 Line
    );

#ifdef DBGHELP_TRANSLATE_TCHAR
#define SymGetLineFromName64   SymGetLineFromNameW64
#endif
```

This function supersedes the **SymGetLineFromName** function. For more information, see
[Updated Platform Support](https://learn.microsoft.com/windows/desktop/Debug/updated-platform-support). **SymGetLineFromName** is defined as follows in Dbghelp.h.

```cpp
#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define SymGetLineFromName SymGetLineFromName64
#else
BOOL
IMAGEAPI
SymGetLineFromName(
    __in HANDLE hProcess,
    __in_opt PCSTR ModuleName,
    __in_opt PCSTR FileName,
    __in DWORD dwLineNumber,
    __out PLONG plDisplacement,
    __inout PIMAGEHLP_LINE Line
    );
#endif
```

#### Examples

For an example, see
[Retrieving Symbol Information by Name](https://learn.microsoft.com/windows/desktop/Debug/retrieving-symbol-information-by-name).

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[IMAGEHLP_LINE64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_line)

[SymGetLineFromAddr64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetlinefromaddr)

[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize)