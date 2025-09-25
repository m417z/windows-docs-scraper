# GetModuleFileNameA function

## Description

Retrieves the fully qualified path for the file that contains the specified module. The module must have been loaded by the current process.

To locate the file for a module that was loaded by another process, use the
[GetModuleFileNameEx](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getmodulefilenameexa) function.

## Parameters

### `hModule` [in, optional]

A handle to the loaded module whose path is being requested. If this parameter is **NULL**,
**GetModuleFileName** retrieves the path of the executable file of the current process.

The **GetModuleFileName** function does not retrieve the path for modules that were loaded using the **LOAD_LIBRARY_AS_DATAFILE** flag. For more information, see [LoadLibraryEx](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibraryexa).

### `lpFilename` [out]

A pointer to a buffer that receives the fully qualified path of the module. If the length of the path is less than the size that the *nSize* parameter specifies, the function succeeds and the path is returned as a null-terminated string.

If the length of the path equals or exceeds the value specified by *nSize*, the function succeeds and the string is truncated to *nSize* characters (including the terminating null character).

**Windows XP:** The string is truncated to *nSize* characters and is not null-terminated.

The string returned will use the same format that was specified when the module was loaded. Therefore, the path can be a long or short file name, and can use the prefix `\\?\`. For more information, see
[Naming a File](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file).

### `nSize` [in]

The size of the *lpFilename* buffer, in **TCHARs**.

## Return value

If the function succeeds, the return value is the length of the string that is copied to the buffer, in characters, not including the terminating null character. If the buffer is too small to hold the module name, the string is truncated to *nSize* characters including the terminating null character, the function returns *nSize*, and the function sets the last error to **ERROR_INSUFFICIENT_BUFFER**.

**Windows XP:** If the buffer is too small to hold the module name, the function returns *nSize*. The last error code remains **ERROR_SUCCESS**. If *nSize* is zero, the return value is zero and the last error code is **ERROR_SUCCESS**.

If the function fails, the return value is 0 (zero). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If a DLL is loaded in two processes, its file name in one process may differ in case from its file name in the other process.

The global variable `_pgmptr` is automatically initialized to the full path of the executable file, and can be used to retrieve the full path name of an executable file.

#### Examples

For an example, see
[Installing a Service](https://learn.microsoft.com/windows/desktop/Services/installing-a-service).

> [!NOTE]
> The libloaderapi.h header defines GetModuleFileName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Dynamic-Link Library Functions](https://learn.microsoft.com/windows/desktop/Dlls/dynamic-link-library-functions)

[GetModuleFileNameEx](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getmodulefilenameexa)

[GetModuleHandle](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulehandlea)

[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya)

[LoadLibraryEx](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibraryexa)