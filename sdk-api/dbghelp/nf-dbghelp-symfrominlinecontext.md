# SymFromInlineContext function

## Description

Retrieves symbol information for the specified address and inline context.

## Parameters

### `hProcess` [in]

A handle to a process. This handle must have been previously passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `Address` [in]

The address for which a symbol should be located. The address does not have to be on a symbol boundary. If
the address comes after the beginning of a symbol and before the end of the symbol, the symbol is found.

### `InlineContext` [in]

The inline context for which a symbol should be located.

### `Displacement` [out, optional]

The displacement from the beginning of the symbol, or zero.

### `Symbol` [in, out]

A pointer to a [SYMBOL_INFO](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-symbol_info) structure that
provides information about the symbol. The symbol name is variable in length; therefore this buffer must be
large enough to hold the name stored at the end of the
**SYMBOL_INFO** structure. Be sure to set the
**MaxNameLen** member to the number of bytes reserved for the name.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error
information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).