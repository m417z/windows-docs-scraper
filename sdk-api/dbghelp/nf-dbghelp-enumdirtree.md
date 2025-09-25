# EnumDirTree function

## Description

Enumerates all occurrences of the specified file in the specified directory tree.

## Parameters

### `hProcess` [in, optional]

A handle to a process. This handle must have been previously passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `RootPath` [in]

The path where the function should begin searching for the file.

### `InputPathName` [in]

The name of the file to be found. You can specify a partial path.

### `OutputPathBuffer` [out, optional]

A pointer to a buffer that receives the full path of the file. If the function fails or does not find a matching file, this buffer will still contain the last full path that was found.

This parameter is optional and can be **NULL**.

### `cb` [in, optional]

An application-defined callback function, or **NULL**. For more information, see
[EnumDirTreeProc](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-penumdirtree_callback).

### `data` [in, optional]

The user-defined data or **NULL**. This value is passed to the callback function.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The search can be canceled if you register a
[SymRegisterCallbackProc64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-psymbol_registered_callback) callback function. For every file operation,
*EnumDirTree* calls this callback function with CBA_DEFERRED_SYMBOL_LOAD_CANCEL. If the callback function returns **TRUE**,
*EnumDirTree* cancels the search.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

To call the Unicode version of this function, define DBGHELP_TRANSLATE_TCHAR.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[EnumDirTreeProc](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-penumdirtree_callback)