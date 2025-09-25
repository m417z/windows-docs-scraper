# SymSetScopeFromIndex function

## Description

Sets the local scope to the symbol that matches the specified index.

## Parameters

### `hProcess` [in]

A handle to a process. This handle must have been previously passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `BaseOfDll` [in]

The base address of the module.

### `Index` [in]

The unique value for the symbol.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error
information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[SymGetScope](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetscope)

[SymSetScopeFromAddr](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsetscopefromaddr)