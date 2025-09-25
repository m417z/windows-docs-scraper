# SymFromIndex function

## Description

Retrieves symbol information for the specified index.

## Parameters

### `hProcess` [in]

A handle to a process. This handle must have been previously passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `BaseOfDll` [in]

The base address of the module.

### `Index` [in]

A unique value for the symbol.

### `Symbol` [in, out]

A pointer to a
[SYMBOL_INFO](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-symbol_info) structure that provides information about the symbol.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[SYMBOL_INFO](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-symbol_info)