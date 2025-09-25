# SymEnumTypesByName function

## Description

Enumerates all user-defined types.

## Parameters

### `hProcess` [in]

A handle to a process. This handle must have been previously passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `BaseOfDll` [in]

The base address of the module.

### `mask` [in, optional]

A wildcard expression that indicates the names of the symbols to be enumerated. To specify a module name, use the !*mod* syntax.

### `EnumSymbolsCallback` [in]

A pointer to an
[SymEnumSymbolsProc](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-psym_enumeratesymbols_callback) callback function that receives the symbol information.

### `UserContext` [in]

A user-defined value to be passed to the callback function, or **NULL**. This parameter is typically used by an application to pass a pointer to a data structure that provides context information for the callback function.

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