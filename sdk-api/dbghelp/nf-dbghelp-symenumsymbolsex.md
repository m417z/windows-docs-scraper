# SymEnumSymbolsEx function

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
| **foo** | If *BaseOfDll* is not zero, then [SymEnumSymbols](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumsymbols) will look for a global symbol named "foo".<br><br>If *BaseOfDll* is zero, then [SymEnumSymbols](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumsymbols) will look for a local symbol named "foo" within the scope established by the most recent call to the [SymSetContext](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsetcontext) function. |
| **foo?** | If *BaseOfDll* is not zero, then [SymEnumSymbols](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumsymbols) will look for a global symbol that starts with "foo" and contains one extra character afterwards, such as "fool" and "foot".<br><br>If *BaseOfDll* is zero, then [SymEnumSymbols](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumsymbols) will look for a symbol that starts with "foo" and contains one extra character afterwards, such as "fool" and "foot". The search would be within the scope established by the most recent call to the [SymSetContext](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsetcontext) function. |
| **foo*!bar** | [SymEnumSymbols](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumsymbols) will look in every loaded module that starts with the text "foo" for a symbol called "bar". It could find matches such as these, "foot!bar", "footlocker!bar", and "fool!bar". |
| ***!*** | [SymEnumSymbols](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumsymbols) will enumerate every symbol in every loaded module. |

### `EnumSymbolsCallback` [in]

A [SymEnumSymbolsProc](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-psym_enumeratesymbols_callback) callback function that
receives the symbol information.

### `UserContext` [in, optional]

A user-defined value that is passed to the callback function, or **NULL**. This
parameter is typically used by an application to pass a pointer to a data structure that provides context for
the callback function.

### `Options` [in]

Indicates possible options.

| Value | Meaning |
| --- | --- |
| **SYMENUM_OPTIONS_DEFAULT**<br><br>1 | Use the default options. |
| **SYMENUM_OPTIONS_INLINE**<br><br>2 | Enumerate inline symbols. |

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error
information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).