# SymGetSearchPath function

## Description

Retrieves the symbol search path for the specified process.

## Parameters

### `hProcess` [in]

A handle to the process that was originally passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `SearchPath` [out]

A pointer to the buffer that receives the symbol search path.

### `SearchPathLength` [in]

The size of the *SearchPath* buffer, in characters.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**SymGetSearchPath** function copies the symbol search path for the specified process into the *SearchPath* buffer. If the function fails, the contents of the buffer are undefined.

To specify a symbol search path for the process, use the
[SymSetSearchPath](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsetsearchpath) function.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

To call the Unicode version of this function, define DBGHELP_TRANSLATE_TCHAR.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize)

[SymSetSearchPath](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsetsearchpath)