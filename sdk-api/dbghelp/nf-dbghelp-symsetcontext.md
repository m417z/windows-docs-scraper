# SymSetContext function

## Description

Sets context information used by the
[SymEnumSymbols](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumsymbols) function. This function only works with
PDB symbols.

## Parameters

### `hProcess` [in]

A handle to a process. This handle must have been previously passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `StackFrame` [in]

A pointer to an [IMAGEHLP_STACK_FRAME](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_stack_frame)
structure that contains frame information.

### `Context` [in, optional]

This parameter is ignored.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error
information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If you call **SymSetContext** to set the context to its
current value, the function fails but [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)
returns **ERROR_SUCCESS**.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to
this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize
all concurrent calls from more than one thread to this function.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[IMAGEHLP_STACK_FRAME](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_stack_frame)

[SymEnumSymbols](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumsymbols)