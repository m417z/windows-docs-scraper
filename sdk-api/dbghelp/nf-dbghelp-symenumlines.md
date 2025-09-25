# SymEnumLines function

## Description

Enumerates all lines in the specified module.

## Parameters

### `hProcess` [in]

A handle to a process. This handle must have been previously passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `Base` [in]

The base address of the module.

### `Obj` [in, optional]

The name of an .obj file within the module. The scope of the enumeration is limited to this file. If this parameter is **NULL** or an empty string, all .obj files are searched.

### `File` [in, optional]

A wildcard expression that indicates the names of the source files to be searched. If this parameter is **NULL** or an empty string, all files are searched.

### `EnumLinesCallback` [in]

A
[SymEnumLinesProc](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-psym_enumlines_callback) callback function that receives the line information.

### `UserContext` [in, optional]

A user-defined value that is passed to the callback function, or **NULL**. This parameter is typically used by an application to pass a pointer to a data structure that provides context for the callback function.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function is supported for PDB information only. If you have COFF information, try using one of the **SymGetLineXXX** functions.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

To call the Unicode version of this function, define DBGHELP_TRANSLATE_TCHAR.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[SymEnumLinesProc](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-psym_enumeratesymbols_callback)