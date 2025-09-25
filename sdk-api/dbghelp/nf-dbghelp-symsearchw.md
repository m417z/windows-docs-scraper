# SymSearchW function

## Description

Searches for PDB symbols that meet the specified criteria.

## Parameters

### `hProcess` [in]

A handle to a process. This handle must have been previously passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `BaseOfDll` [in]

The base address of the module. If this value is zero and *Mask* contains an exclamation point (!), the function looks across modules. If this value is zero and *Mask* does not contain an exclamation point, the function uses the scope established by the
[SymSetContext](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsetcontext) function.

### `Index` [in, optional]

A unique value for the symbol.

### `SymTag` [in, optional]

The PDB classification. These values are defined in Dbghelp.h in the **SymTagEnum** enumeration type. For descriptions, see the PDB documentation.

### `Mask` [in, optional]

A wildcard expression that indicates the names of the symbols to be enumerated. To specify a module name, use the !*mod* syntax.

### `Address` [in, optional]

The address of the symbol.

### `EnumSymbolsCallback` [in]

 A
[SymEnumSymbolsProc](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-psym_enumeratesymbols_callback) callback function that receives the symbol information.

### `UserContext` [in, optional]

 A user-defined value that is passed to the callback function, or **NULL**. This parameter is typically used by an application to pass a pointer to a data structure that provides context for the callback function.

### `Options` [in]

The options that control the behavior of this function.

| Value | Meaning |
| --- | --- |
| **SYMSEARCH_ALLITEMS**<br><br>0x08 | Include all symbols and other data in the .pdb files.<br><br>**DbgHelp 6.6 and earlier:** This value is not supported. |
| **SYMSEARCH_GLOBALSONLY**<br><br>0x04 | Search only for global symbols. |
| **SYMSEARCH_MASKOBJS**<br><br>0x01 | For internal use only. |
| **SYMSEARCH_RECURSE**<br><br>0x02 | Recurse from the top to find all symbols. |

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

To call the Unicode version of this function, define DBGHELP_TRANSLATE_TCHAR.

> [!NOTE]
> The dbghelp.h header defines SymSearch as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[SymEnumSymbolsProc](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-psym_enumeratesymbols_callback)