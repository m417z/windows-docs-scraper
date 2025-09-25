# SymFindDebugInfoFileW function

## Description

Locates a .dbg file in the process search path.

## Parameters

### `hProcess` [in]

A handle to the process that was originally passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `FileName` [in]

The name of the .dbg file. You can use a partial path.

### `DebugFilePath` [out]

The fully qualified path of the .dbg file. This buffer must be at least MAX_PATH characters.

### `Callback` [in, optional]

An application-defined callback function that verifies whether the correct file was found or the function should continue its search. For more information, see
[FindDebugInfoFileProc](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-pfind_debug_file_callback).

This parameter can be **NULL**.

### `CallerData` [in, optional]

A user-defined value or **NULL**. This value is simply passed to the callback function. This parameter is typically used by an application to pass a pointer to a data structure that provides some context for the callback function.

## Return value

If the function succeeds, the return value is an open handle to the .dbg file.

If the function fails, the return value is **NULL**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function uses the search path set using the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) or [SymSetSearchPath](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsetsearchpath) function.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

To call the Unicode version of this function, define DBGHELP_TRANSLATE_TCHAR.

> [!NOTE]
> The dbghelp.h header defines SymFindDebugInfoFile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[FindDebugInfoFileProc](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-pfind_debug_file_callback)