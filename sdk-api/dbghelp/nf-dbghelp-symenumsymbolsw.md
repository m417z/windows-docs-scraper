# SymEnumSymbolsW function

## Description

Enumerates all symbols in a process.

## Parameters

### `hProcess` [in]

A handle to a process. This handle must have been previously passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `BaseOfDll` [in]

The base address of the module. If this value is zero and *Mask* contains an
exclamation point (!), the function looks across modules. If this value is zero and
*Mask* does not contain an exclamation point, the function uses the scope established by
the [SymSetContext](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsetcontext) function.

### `Mask` [in, optional]

A wildcard string that indicates the names of the symbols to be enumerated. The text can optionally contain
the wildcards, "*" and "?".

To specify a specific module or set of modules, begin the text with a wildcard string specifying the module,
followed by an exclamation point. When specifying a module, *BaseOfDll* is ignored.

| Value | Meaning |
| --- | --- |
| **foo** | If *BaseOfDll* is not zero, then **SymEnumSymbols** will look for a global symbol named "foo".<br><br>If *BaseOfDll* is zero, then **SymEnumSymbols** will look for a local symbol named "foo" within the scope established by the most recent call to the [SymSetContext](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsetcontext) function. |
| **foo?** | If *BaseOfDll* is not zero, then **SymEnumSymbols** will look for a global symbol that starts with "foo" and contains one extra character afterwards, such as "fool" and "foot".<br><br>If *BaseOfDll* is zero, then **SymEnumSymbols** will look for a symbol that starts with "foo" and contains one extra character afterwards, such as "fool" and "foot". The search would be within the scope established by the most recent call to the [SymSetContext](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsetcontext) function. |
| **foo*!bar** | **SymEnumSymbols** will look in every loaded module that starts with the text "foo" for a symbol called "bar". It could find matches such as these, "foot!bar", "footlocker!bar", and "fool!bar". |
| ***!*** | **SymEnumSymbols** will enumerate every symbol in every loaded module. |

### `EnumSymbolsCallback` [in]

A [SymEnumSymbolsProc](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-psym_enumeratesymbols_callback) callback function that
receives the symbol information.

### `UserContext` [in, optional]

A user-defined value that is passed to the callback function, or **NULL**. This
parameter is typically used by an application to pass a pointer to a data structure that provides context for
the callback function.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error
information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to
this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize
all concurrent calls from more than one thread to this function.

To call the Unicode version of this function, define
**DBGHELP_TRANSLATE_TCHAR**.

#### Examples

For an example, see [Enumerating Symbols](https://learn.microsoft.com/windows/desktop/Debug/enumerating-symbols).

> [!NOTE]
> The dbghelp.h header defines SymEnumSymbols as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[SymEnumSymbolsProc](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-psym_enumeratesymbols_callback)