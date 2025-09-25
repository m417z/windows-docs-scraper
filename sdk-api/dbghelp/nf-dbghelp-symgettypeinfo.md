# SymGetTypeInfo function

## Description

Retrieves type information for the specified type index. For larger queries, use the [SymGetTypeInfoEx](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgettypeinfoex) function.

## Parameters

### `hProcess` [in]

A handle to a process. This handle must have been previously passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `ModBase` [in]

The base address of the module.

### `TypeId` [in]

The type index. (A number of functions return a type index in the **TypeIndex** member of the
[SYMBOL_INFO](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-symbol_info) structure.)

### `GetType` [in]

The information type. This parameter can be one of more of the values from the [IMAGEHLP_SYMBOL_TYPE_INFO](https://learn.microsoft.com/windows/desktop/api/dbghelp/ne-dbghelp-imagehlp_symbol_type_info) enumeration type.

### `pInfo` [out]

The data. The format of the data depends on the value of the *GetType* parameter.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

For more details on the type information, see the documentation for the PDB format.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[IMAGEHLP_SYMBOL_TYPE_INFO](https://learn.microsoft.com/windows/desktop/api/dbghelp/ne-dbghelp-imagehlp_symbol_type_info)

[SymGetTypeFromName](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgettypefromname)

[SymGetTypeInfoEx](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgettypeinfoex)