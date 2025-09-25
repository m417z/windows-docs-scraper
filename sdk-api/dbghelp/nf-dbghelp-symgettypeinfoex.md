# SymGetTypeInfoEx function

## Description

Retrieves multiple pieces of type information.

## Parameters

### `hProcess` [in]

A handle to a process. This handle must have been previously passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `ModBase` [in]

The base address of the module.

### `Params` [in, out]

A pointer to an [IMAGEHLP_GET_TYPE_INFO_PARAMS](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_get_type_info_params) structure that specifies input and output information for the query.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[IMAGEHLP_GET_TYPE_INFO_PARAMS](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_get_type_info_params)

[SymGetTypeFromName](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgettypefromname)