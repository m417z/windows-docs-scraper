# SymEnumSourceFiles function

## Description

Enumerates all source files in a process.

## Parameters

### `hProcess` [in]

A handle to a process. This handle must have been previously passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `ModBase` [in]

The base address of the module. If this value is zero and *Mask* contains an exclamation point (!), the function looks across modules. If this value is zero and *Mask* does not contain an exclamation point, the function uses the scope established by the
[SymSetContext](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsetcontext) function.

### `Mask` [in, optional]

A wildcard expression that indicates the names of the source files to be enumerated. To specify a module name, use the !*mod* syntax.

If this parameter is **NULL**, the function will enumerate all files.

### `cbSrcFiles` [in]

Pointer to a
[SymEnumSourceFilesProc](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-psym_enumsourcefiles_callback) callback function that receives the source file information.

### `UserContext` [in, optional]

User-defined value that is passed to the callback function, or **NULL**. This parameter is typically used by an application to pass a pointer to a data structure that provides context for the callback function.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[SymEnumSourceFilesProc](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-psym_enumsourcefiles_callback)