# IDebugSymbolGroup2::ExpandSymbol

## Description

The **ExpandSymbol** method adds or removes the children of a symbol from a symbol group.

## Parameters

### `Index` [in]

The index of the symbol whose children will be added or removed. The index of a symbol is an identification number. The index ranges from zero through the number of symbols in the symbol group minus one.

### `Expand` [in]

A Boolean value that specifies whether to add or remove the symbols children from the symbol group. If *Expand* is true, the children are added. If *Expand* is false, the children are removed.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The symbol has no children to add. |
| **E_INVALIDARG** | The depth of the symbol is DEBUG_SYMBOL_EXPANSION_LEVEL_MASK, which is the maximum depth. This depth prevented the specified symbol's children from being added to this symbol group. |

This method can also return other error values. For more information, see [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

## Remarks

For more information about symbol groups, see [Scopes and Symbol Groups](https://learn.microsoft.com/windows-hardware/drivers/debugger/scopes-and-symbol-groups).

## See also

[GetNumberSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbolgroup2-getnumbersymbols)

[IDebugSymbolGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbolgroup)

[IDebugSymbolGroup2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbolgroup2)