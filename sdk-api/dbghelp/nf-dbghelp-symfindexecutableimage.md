# SymFindExecutableImage function

## Description

Locates an executable file in the process search path.

## Parameters

### `hProcess` [in]

A handle to the process that was originally passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `FileName` [in]

The name of the executable file. You can use a partial path.

### `ImageFilePath` [out]

The fully qualified path of the executable file. This buffer must be at least MAX_PATH characters.

### `Callback` [in]

An application-defined callback function that verifies whether the correct executable file was found, or whether the function should continue its search. For more information, see
[FindExecutableImageProc](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-pfind_exe_file_callback).

This parameter can be **NULL**.

### `CallerData` [in]

A user-defined value or **NULL**. This value is simply passed to the callback function. This parameter is typically used by an application to pass a pointer to a data structure that provides some context for the callback function.

## Return value

If the function succeeds, the return value is an open handle to the executable file.

If the function fails, the return value is **NULL**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function uses the search path set using the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) or [SymSetSearchPath](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsetsearchpath) function.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

To call the Unicode version of this function, define DBGHELP_TRANSLATE_TCHAR.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[FindExecutableImageProc](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-pfind_exe_file_callback)