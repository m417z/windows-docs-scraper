# PSYM_ENUMPROCESSES_CALLBACK callback function

## Description

An application-defined function used with the [SymEnumProcesses](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumprocesses) function.

The **PSYM_ENUMPROCESSES_CALLBACK** type defines a pointer to this callback function.
**SymEnumProcessesProc** is a placeholder for the application-defined function name.

## Parameters

### `hProcess` [in]

A handle to the process.

### `UserContext` [in]

The user-defined value passed from the
[SymEnumProcesses](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumprocesses) function, or **NULL**. This parameter is typically used by an application to pass a pointer to a data structure that provides context information for the callback function.

## Return value

If the function returns **TRUE**, the enumeration will continue.

If the function returns **FALSE**, the enumeration will stop.

## See also

[SymEnumProcesses](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumprocesses)