# SymEnumProcesses function

## Description

Enumerates each process that has called the [SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

## Parameters

### `EnumProcessesCallback` [in]

A [SymEnumProcessesProc](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-psym_enumprocesses_callback) callback function that receives the process information.

### `UserContext` [in]

A user-defined value that is passed to the callback function, or **NULL**. This parameter is typically used by an application to pass a pointer to a data structure that provides context for the callback function.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[SymEnumProcessesProc](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-psym_enumprocesses_callback)