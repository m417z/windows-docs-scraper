# SymGetSourceFileFromToken function

## Description

Retrieves the source file associated with the specified token from the source server.

## Parameters

### `hProcess` [in]

A handle to a process. This handle must have been previously passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `Token` [in]

A pointer to the token.

### `Params` [in, optional]

This parameter is unused.

### `FilePath` [out]

A pointer to a
buffer that receives the fully qualified path of the source file.

### `Size` [in]

The size of the *FilePath* buffer, in characters.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

To call the Unicode version of this function, define DBGHELP_TRANSLATE_TCHAR.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[Source Server](https://learn.microsoft.com/windows/desktop/Debug/source-server-and-source-indexing)