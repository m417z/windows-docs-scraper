# SymSrvGetSupplementW function

## Description

Retrieves the specified file from the supplement for a symbol store.

## Parameters

### `hProcess` [in]

A handle to a process. This handle must have been previously passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `SymPath` [in, optional]

The symbol path. The function uses only the symbol stores described in standard syntax for symbol stores. All other paths are ignored. If this parameter is **NULL**, the function uses the symbol path set using the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) or [SymSetSearchPath](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsetsearchpath) function.

### `Node` [in]

The symbol file associated with the supplemental file.

### `File` [in]

The name of the file.

## Return value

If the function succeeds, the return value is the fully qualified path for the supplemental file.

If the function fails, the return value is **NULL**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

For more information on supplemental files, see [SymSrvStoreSupplement](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsrvstoresupplement).

This function returns a pointer to a buffer that may be reused by another function. Therefore, be sure to copy the data returned to another buffer immediately.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

To call the Unicode version of this function, define DBGHELP_TRANSLATE_TCHAR.

> [!NOTE]
> The dbghelp.h header defines SymSrvGetSupplement as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[SymSrvStoreSupplement](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsrvstoresupplement)