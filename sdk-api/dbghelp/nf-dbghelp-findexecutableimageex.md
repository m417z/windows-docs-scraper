# FindExecutableImageEx function

## Description

Locates the specified executable file.

## Parameters

### `FileName` [in]

The name of the symbol file to be located. This parameter can be a partial path.

### `SymbolPath` [in]

The path where symbol files are located. This string can contain multiple paths separated by semicolons. To retrieve the symbol path, use the
[SymGetSearchPath](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetsearchpath) function.

### `ImageFilePath` [out]

A pointer to a buffer that receives the full path of the executable file.

### `Callback` [in, optional]

An application-defined callback function that verifies whether the correct executable file was found, or whether the function should continue its search. For more information, see
[FindExecutableImageProc](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-pfind_exe_file_callback).

This parameter can be **NULL**.

### `CallerData` [in, optional]

Optional user-defined data for the callback function. This parameter can be **NULL**.

## Return value

If the function succeeds, the return value is an open handle to the executable file.

If the function fails, the return value is **NULL**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**FindExecutableImageEx** function is provided so executable files can be found in several different directories by using a single function call. If the *SymbolPath* parameter contains multiple paths, the function searches each specified directory tree for the executable file. When the file is found, the search stops. Thus, be sure to specify *SymbolPath* with the paths in the correct order.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

To call the Unicode version of this function, define DBGHELP_TRANSLATE_TCHAR.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[FindExecutableImageProc](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-pfind_exe_file_callback)

[SymGetSearchPath](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetsearchpath)