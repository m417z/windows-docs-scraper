# SymFromAddrW function

## Description

Retrieves symbol information for the specified address.

## Parameters

### `hProcess` [in]

A handle to a process. This handle must have been previously passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `Address` [in]

The address for which a symbol should be located. The address does not have to be on a symbol boundary. If the address comes after the beginning of a symbol and before the end of the symbol, the symbol is found.

### `Displacement` [out, optional]

The displacement from the beginning of the symbol, or zero.

### `Symbol` [in, out]

A pointer to a
[SYMBOL_INFO](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-symbol_info) structure that provides information about the symbol. The symbol name is variable in length; therefore this buffer must be large enough to hold the name stored at the end of the
**SYMBOL_INFO** structure. Be sure to set the **MaxNameLen** member to the number of bytes reserved for the name.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

To call the Unicode version of this function, define DBGHELP_TRANSLATE_TCHAR.

#### Examples

For an example, see
[Retrieving Symbol Information by Address](https://learn.microsoft.com/windows/desktop/Debug/retrieving-symbol-information-by-address).

> [!NOTE]
> The dbghelp.h header defines SymFromAddr as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[SYMBOL_INFO](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-symbol_info)