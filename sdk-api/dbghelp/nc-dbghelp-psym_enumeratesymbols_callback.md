# PSYM_ENUMERATESYMBOLS_CALLBACK callback function

## Description

An application-defined callback function used with the
[SymEnumSymbols](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumsymbols),
[SymEnumTypes](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumtypes), and
[SymEnumTypesByName](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumtypesbyname) functions.

The **PSYM_ENUMERATESYMBOLS_CALLBACK** and
**PSYM_ENUMERATESYMBOLS_CALLBACKW** types define a pointer to this callback function.
**SymEnumSymbolsProc** is a placeholder for the
application-defined function name.

## Parameters

### `pSymInfo` [in]

A pointer to a [SYMBOL_INFO](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-symbol_info) structure that
provides information about the symbol.

### `SymbolSize` [in]

The size of the symbol, in bytes. The size is calculated and is actually a guess. In some cases, this value
can be zero.

### `UserContext` [in, optional]

The user-defined value passed from the
[SymEnumSymbols](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumsymbols) or
[SymEnumTypes](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumtypes) function, or
**NULL**. This parameter is typically used by an application to pass a pointer to a data
structure that provides context information for the callback function.

## Return value

If the function returns **TRUE**, the enumeration will continue.

If the function returns **FALSE**, the enumeration will stop.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[SYMBOL_INFO](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-symbol_info)

[SymEnumSymbols](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumsymbols)

[SymEnumTypes](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumtypes)

[SymEnumTypesByName](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumtypesbyname)