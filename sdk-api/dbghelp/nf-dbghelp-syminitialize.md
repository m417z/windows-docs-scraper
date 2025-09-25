# SymInitialize function

## Description

Initializes the symbol handler for a process.

## Parameters

### `hProcess` [in]

A handle that identifies the caller. This value should be unique and nonzero, but need not be a process handle. However, if you do use a process handle, be sure to use the correct handle. If the application is a debugger, use the process handle for the process being debugged. Do not use the handle returned by [GetCurrentProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentprocess). The handle used must be unique to avoid sharing a session with another component, and using [GetCurrentProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentprocess) can have unexpected results when multiple components are attempting to use dbghelp to inspect the current process. Using [GetCurrentProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentprocess) when debugging another process will also cause functions like [SymLoadModuleEx](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symloadmoduleex) to have unexpected results.

This parameter cannot be **NULL**.

### `UserSearchPath` [in, optional]

The path, or series of paths separated by a semicolon (;), that is used to search for symbol files. If this parameter is **NULL**, the library attempts to form a symbol path from the following sources:

* The current working directory of the application
* The _NT_SYMBOL_PATH environment variable
* The _NT_ALTERNATE_SYMBOL_PATH environment variable

Note that the search path can also be set using the [SymSetSearchPath](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsetsearchpath) function.

### `fInvadeProcess` [in]

If this value is **TRUE**, enumerates the loaded modules for the process and effectively calls the
[SymLoadModule64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symloadmodule) function for each module.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**SymInitialize** function is used to initialize the symbol handler for a process. In the context of the symbol handler, a process is a convenient object to use when collecting symbol information. Usually, symbol handlers are used by debuggers and other tools that need to load symbols for a process being debugged.

The handle passed to
**SymInitialize** must be the same value passed to all other symbol handler functions called by the process. It is the handle that the functions use to identify the caller and locate the correct symbol information. When you have finished using the symbol information, call the
[SymCleanup](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symcleanup) function to deallocate all resources associated with the process for which symbols are loaded.

The search for symbols files is performed recursively for all paths specified in the *UserSearchPath* parameter. Therefore, if you specify the root directory in a search, the whole drive is searched, which can take significant time. Note that the directory that contains the executable file for the process is not automatically part of the search path. To include this directory in the search path, call the
[GetModuleFileNameEx](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getmodulefilenameexa) function, then add the path returned to *UserSearchPath*.

A process that calls **SymInitialize** should not call it again unless it calls [SymCleanup](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symcleanup) first. If the call to **SymInitialize** set *fInvadeProcess* to **TRUE** and you simply need to reload the module list, use the [SymRefreshModuleList](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symrefreshmodulelist) function.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, call
**SymInitialize** only when your process starts and
[SymCleanup](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symcleanup) only when your process ends. It is not necessary for each thread in the process to call these functions.

To call the Unicode version of this function, define DBGHELP_TRANSLATE_TCHAR.

#### Examples

For an example, see
[Initializing the Symbol Handler](https://learn.microsoft.com/windows/desktop/Debug/initializing-the-symbol-handler).

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[GetModuleFileNameEx](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getmodulefilenameexa)

[SymCleanup](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symcleanup)

[SymEnumProcesses](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumprocesses)

[SymLoadModule64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symloadmodule)

[SymRefreshModuleList](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symrefreshmodulelist)

[SymSetSearchPath](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsetsearchpath)