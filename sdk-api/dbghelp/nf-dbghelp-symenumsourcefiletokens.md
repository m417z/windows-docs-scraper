# SymEnumSourceFileTokens function

## Description

Enumerates all individual entries in a module's [source server](https://learn.microsoft.com/windows/desktop/Debug/source-server-and-source-indexing) data, if available.

## Parameters

### `hProcess` [in]

A handle to a process. This handle must have been previously passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `Base` [in]

The base address of the module.

### `Callback` [in]

A
[SymEnumSourceFileTokensProc](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-penumsourcefiletokenscallback) callback function that receives the symbol information.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Some modules have PDB files with [source server](https://learn.microsoft.com/windows/desktop/Debug/source-server-and-source-indexing) information detailing the version control information for each of the source files used to create each individual module. An application can use this function to enumerate the data for every source file that was "source indexed".

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[Source Server](https://learn.microsoft.com/windows/desktop/Debug/source-server-and-source-indexing)

[SymEnumSourceFileTokensProc](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-penumsourcefiletokenscallback)