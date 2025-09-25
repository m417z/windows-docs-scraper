# IDebugSymbols2::GetOffsetByName

## Description

The **GetOffsetByName** method returns the location of a symbol identified by name.

## Parameters

### `Symbol` [in]

Specifies the name of the symbol to locate. The name may be qualified by a module name (for example, **mymodule!main**).

### `Offset` [out]

Receives the location in the target's memory address space of the base of the symbol's memory allocation.

## Return value

This method may also return other error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful. However, the name *Symbol* was not unique and multiple symbols with that name were found. One of these symbols was arbitrarily chosen and returned. |
| **E_FAIL** | No symbol could be found with the specified name. |

## Remarks

If the name *Symbol* is not unique and **GetOffsetByName** finds multiple symbols with that name, then the ambiguity will be resolved arbitrarily. In this case the value S_FALSE will be returned. [StartSymbolMatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-startsymbolmatch) can be used to initiate a search to determine which is the desired result.

**GetNameByOffset** does not support pattern matching (e.g. wildcards). To find a symbol using pattern matching use **StartSymbolMatch**.

If the module name for the symbol is known, it is best to qualify the symbol name with the module name. Otherwise the engine will search the symbols for all modules until it finds a match; this can take a long time if it has to load the symbol files for a lot of modules. If the symbol name is qualified with a module name, the engine only searches the symbols for that module.

For more information about symbols and symbol names, see [Symbols](https://learn.microsoft.com/windows-hardware/drivers/debugger/symbols4).

## See also

[GetNameByOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getnamebyoffset)

[IDebugSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols)

[IDebugSymbols2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols2)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)