# SymEnumSymbolsForAddr function

## Description

Enumerates the symbols for the specified address.

## Parameters

### `hProcess` [in]

A handle to a process. This handle must have been previously passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `Address` [in]

The address for which symbols are to be located. The address does not have to be on a symbol boundary. If the address comes after the beginning of a symbol and before the end of the symbol (the beginning of the symbol plus the symbol size), the function will find the symbol.

### `EnumSymbolsCallback` [in]

An application-defined callback function. This function is called for every symbol found at *Address*. For more information, see
[SymEnumSymbolsProc](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-psym_enumeratesymbols_callback).

### `UserContext` [in, optional]

Optional user-defined data. This value is passed to the callback function.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

To call the Unicode version of this function, define DBGHELP_TRANSLATE_TCHAR.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[SymEnumSymbolsProc](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-psym_enumeratesymbols_callback)