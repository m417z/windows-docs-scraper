# SearchTreeForFileW function

## Description

Searches a directory tree for a specified file.

## Parameters

### `RootPath` [in]

The path where the function should begin searching for the file.

### `InputPathName` [in]

The file for which the function will search. You can use a partial path.

### `OutputPathBuffer` [out]

A pointer to a buffer that receives the full path to the file that is found. This string is not modified if the return value is **FALSE**.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The function searches for the file specified by the *InputPathName* parameter beginning at the path specified in the *RootPath* parameter. The maximum path depth that is allowed in the *RootPath* is 32 directories. When the function finds the file in the directory tree, it places the full path to the file in the buffer specified by the *OutputPathBuffer* parameter. The underlying file system specifies the order of the subdirectory search.

The search can be canceled if you register a
[SymRegisterCallbackProc64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-psymbol_registered_callback) callback function. For every directory searched,
**SearchTreeForFile** calls this callback function with CBA_DEFERRED_SYMBOL_LOAD_CANCEL. If the callback function returns **TRUE**,
**SearchTreeForFile** cancels the search.

This function triggers one CBA_DEFERRED_SYMBOL_LOAD_CANCEL event per directory searched. This allows the caller to cancel the search.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

To call the Unicode version of this function, define DBGHELP_TRANSLATE_TCHAR.

> [!NOTE]
> The dbghelp.h header defines SearchTreeForFile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)