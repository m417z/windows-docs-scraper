# FindExecutableImage function

## Description

Locates an executable file.

To specify a callback function, use the
[FindExecutableImageEx](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-findexecutableimageex) function.

## Parameters

### `FileName` [in]

The name of the symbol file to be located. This parameter can be a partial path.

### `SymbolPath` [in]

The path where symbol files are located. This can be multiple paths separated by semicolons. To retrieve the symbol path, use the
[SymGetSearchPath](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetsearchpath) function.

### `ImageFilePath` [out]

A pointer to a buffer that receives the full path of the executable file.

## Return value

If the function succeeds, the return value is an open handle to the executable file.

If the function fails, the return value is **NULL**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**FindExecutableImage** function is provided so executable files can be located in several different directories through a single function call. The *SymbolPath* parameter can contain multiple paths, with each separated by a semicolon (;). When multiple paths are specified, the function searches each directory tree for the executable file. When the file is located, the search stops. Thus, be sure to specify *SymbolPath* with the paths in the correct order.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[FindExecutableImageEx](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-findexecutableimageex)

[SymGetSearchPath](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetsearchpath)