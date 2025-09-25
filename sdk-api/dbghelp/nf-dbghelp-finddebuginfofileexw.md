# FindDebugInfoFileExW function

## Description

Locates the specified
[debug (.dbg) file](https://learn.microsoft.com/windows/desktop/Debug/symbol-files).

## Parameters

### `FileName` [in]

The name of the .dbg file to locate. You can use a partial path.

### `SymbolPath` [in]

The path where symbol files are located. This can be multiple paths separated by semicolons. To retrieve the symbol path, use the
[SymGetSearchPath](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetsearchpath) function.

### `DebugFilePath` [out]

A pointer to a buffer that receives the full path of the .dbg file.

### `Callback` [in, optional]

An application-defined callback function that verifies whether the correct file was found or the function should continue its search. For more information, see
[FindDebugInfoFileProc](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-pfind_debug_file_callback).

This parameter may be **NULL**.

### `CallerData` [in, optional]

Optional user-defined data to pass to the callback function.

## Return value

If the function succeeds, the return value is an open handle to the .dbg file.

If the function fails, the return value is **NULL**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**FindDebugInfoFileEx** function is used to locate a .dbg file. This function is provided so the search can be conducted in several different directories through a single function call. The *SymbolPath* parameter can contain multiple paths, with each separated by a semicolon (;). When multiple paths are specified, the function searches each specified directory for the file. When the file is located, the search stops. Thus, be sure to specify *SymbolPath* with the paths in the correct order.

If the file name specified does not include a .dbg extension,
**FindDebugInfoFileEx** searches for the file in the following sequence:

1. *SymbolPath*\Symbols\*ext*\*filename*.dbg
2. *SymbolPath*\*ext*\*filename*.dbg
3. *SymbolPath*\*filename*.dbg
4. *FileNamePath*\*filename*.dbg

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

To call the Unicode version of this function, define DBGHELP_TRANSLATE_TCHAR.

> [!NOTE]
> The dbghelp.h header defines FindDebugInfoFileEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[FindDebugInfoFileProc](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-pfind_debug_file_callback)

[SymGetSearchPath](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetsearchpath)