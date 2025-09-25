# SymSetHomeDirectoryW function

## Description

Sets the home directory used by Dbghelp.

## Parameters

### `hProcess` [in]

A handle to a process. This handle must have been previously passed to the [SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `dir` [in, optional]

The home directory. This directory must be writable, otherwise the home directory is the common application directory specified with [CSIDL_COMMON_APPDATA](https://learn.microsoft.com/windows/win32/shell/csidl). If this parameter is **NULL**, the function uses the default directory.

## Return value

If the function succeeds, the return value is a pointer to the *dir* parameter.

If the function fails, the return value is **NULL**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The default home directory is the directory in which Dbghelp.dll resides. Dbghelp uses this directory as a basis for other directories, such as the default downstream store directory (the sym subdirectory of the home directory).

The home directory used for the default symbol store and the source server cache location is stored in the DBGHELP_HOMEDIR environment variable.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

To call the Unicode version of this function, define DBGHELP_TRANSLATE_TCHAR.

> [!NOTE]
> The dbghelp.h header defines SymSetHomeDirectory as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[SymGetHomeDirectory](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgethomedirectory)