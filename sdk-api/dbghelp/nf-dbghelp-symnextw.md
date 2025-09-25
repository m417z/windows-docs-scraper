## Description

Retrieves symbol information for the next symbol.

## Parameters

### `hProcess` [in]

A handle to a process. This handle must have been previously passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `siw` [in, out]

A pointer to a
[SYMBOL_INFO](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-symbol_info) structure that provides information about the current symbol. Upon return, the structure contains information about the next symbol.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function requires that the [SYMBOL_INFO](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-symbol_info) structure have valid data for the current symbol. The next symbol is the symbol with the virtual address that is next in the sequence.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

To call the Unicode version of this function, define DBGHELP_TRANSLATE_TCHAR.

> [!NOTE]
> The dbghelp.h header defines SymNext as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[SYMBOL_INFO](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-symbol_info)

[SymPrev](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symprev)