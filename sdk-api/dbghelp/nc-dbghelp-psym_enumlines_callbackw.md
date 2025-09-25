# PSYM_ENUMLINES_CALLBACKW callback function

## Description

An application-defined callback function used with the
[SymEnumLines](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumlines) and [SymEnumSourceLines](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumsourcelines) functions.

The **PSYM_ENUMLINES_CALLBACK** and **PSYM_ENUMLINES_CALLBACKW** types define a pointer to this callback function.
**SymEnumLinesProc** is a placeholder for the application-defined function name.

## Parameters

### `LineInfo` [in]

A pointer to a
[SRCCODEINFO](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-srccodeinfo) structure that provides information about the line.

### `UserContext` [in]

The user-defined value passed from the
[SymEnumLines](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumlines) function, or **NULL**. This parameter is typically used by an application to pass a pointer to a data structure that provides context information for the callback function.

## Return value

If the function returns **TRUE**, the enumeration will continue.

If the function returns **FALSE**, the enumeration will stop.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[SymEnumLines](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumlines)

[SymEnumSourceLines](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumsourcelines)