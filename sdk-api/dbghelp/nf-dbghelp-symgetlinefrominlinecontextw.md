## Description

Locates the source line for the specified inline context.

## Parameters

### `hProcess` [in]

A handle to the process that was originally passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `dwAddr` [in]

The address for which a line should be located. It is not necessary for the address to be on a line
boundary. If the address appears after the beginning of a line and before the end of the line, the line is
found.

### `InlineContext` [in]

The inline context.

### `qwModuleBaseAddress` [in, optional]

The base address of the module.

### `pdwDisplacement` [out]

The displacement in bytes from the beginning of the line, or zero.

### `Line` [out]

A pointer to an [IMAGEHLP_LINE64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_line)
structure.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error
information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The caller must allocate the *Line* buffer properly and fill in the required members
of the [IMAGEHLP_LINE64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_line) structure before
calling **SymGetLineFromInlineContext**.

This function returns a pointer to a buffer that may be reused by another function. Therefore, be sure to copy
the data returned to another buffer immediately.

All DbgHelp functions, such as this one, are single
threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or
memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this
function.

To call the Unicode version of this function, define **DBGHELP_TRANSLATE_TCHAR**.
**SymGetLineFromInlineContext** is defined as
follows in Dbghelp.h.

``` syntax
BOOL
IMAGEAPI
SymGetLineFromInlineContextW(
    _In_ HANDLE hProcess,
    _In_ DWORD64 dwAddr,
    _In_ ULONG InlineContext,
    _In_opt_ DWORD64 qwModuleBaseAddress,
    _Out_ PDWORD pdwDisplacement,
    _Out_ PIMAGEHLP_LINEW64 Line
    );

#ifdef DBGHELP_TRANSLATE_TCHAR
 #define SymGetLineFromInlineContext SymGetLineFromInlineContextW
#endif
```

> [!NOTE]
> The dbghelp.h header defines SymGetLineFromInlineContext as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).