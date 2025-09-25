# FindDebugInfoFile function

## Description

Locates a
[debug (.dbg) file](https://learn.microsoft.com/windows/desktop/Debug/symbol-files).

To provide a callback function to verify the symbol file located, use the
[FindDebugInfoFileEx](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-finddebuginfofileex) function.

## Parameters

### `FileName` [in]

The name of the .dbg file that is desired. You can use a partial path.

### `SymbolPath` [in]

The path where symbol files are located. This can be multiple paths separated by semicolons. To retrieve the symbol path, use the
[SymGetSearchPath](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetsearchpath) function.

### `DebugFilePath` [out]

A pointer to a buffer that receives the full path of the .dbg file.

## Return value

If the function succeeds, the return value is an open handle to the .dbg file.

If the function fails, the return value is **NULL**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**FindDebugInfoFile** function is used to locate a .dbg file. This function is provided so the search can be conducted in several different directories through a single function call. The *SymbolPath* parameter can contain multiple paths, with each separated by a semicolon (;). When multiple paths are specified, the function searches each directory for the file. Subdirectories are not searched. When the file is located, the search stops. Thus, be sure to specify *SymbolPath* with the paths in the correct order.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[FindDebugInfoFileEx](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-finddebuginfofileex)

[SymGetSearchPath](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetsearchpath)