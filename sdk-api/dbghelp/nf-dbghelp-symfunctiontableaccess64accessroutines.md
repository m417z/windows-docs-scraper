# SymFunctionTableAccess64AccessRoutines function

## Description

 Finds a function table entry or frame pointer omission (FPO) record for an address.

Use [SymFunctionTableAccess64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symfunctiontableaccess) instead.

## Parameters

### `hProcess` [in]

A handle to the process that was originally passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `AddrBase` [in]

The base address for which function table information is required.

### `ReadMemoryRoutine` [in, optional]

Pointer to a read memory callback function.

### `GetModuleBaseRoutine` [in, optional]

Pointer to a get module base callback function.

## See also

[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize)