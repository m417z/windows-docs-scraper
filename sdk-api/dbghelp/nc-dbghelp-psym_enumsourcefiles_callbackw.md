# PSYM_ENUMSOURCEFILES_CALLBACKW callback function

## Description

An application-defined callback function used with the
[SymEnumSourceFiles](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumsourcefiles) function.

The **PSYM_ENUMSOURCEFILES_CALLBACK** and **PSYM_ENUMSOURCEFILES_CALLBACKW** types define a pointer to this callback function.
**SymEnumSourceFilesProc** is a placeholder for the application-defined function name.

## Parameters

### `pSourceFile` [in]

A pointer to a
[SOURCEFILE](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-sourcefile) structure that provides information about the source file.

### `UserContext` [in, optional]

The user-defined value passed from the
[SymEnumSourceFiles](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumsourcefiles) function, or **NULL**. This parameter is typically used by an application to pass a pointer to a data structure that provides context information for the callback function.

## Return value

If the function returns **TRUE**, the enumeration will continue.

If the function returns **FALSE**, the enumeration will stop.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[SOURCEFILE](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-sourcefile)

[SymEnumSourceFiles](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumsourcefiles)