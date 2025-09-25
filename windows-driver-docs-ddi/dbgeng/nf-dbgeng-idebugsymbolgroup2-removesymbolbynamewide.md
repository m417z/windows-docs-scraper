# IDebugSymbolGroup2::RemoveSymbolByNameWide

## Description

The **RemoveSymbolByNameWide** method removes the specified symbol from a symbol group.

## Parameters

### `Name` [in]

The name of the symbol to remove from the symbol group.

## Return value

**RemoveSymbolByNameWide** might return one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method can also return error values. For more information, see [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

## Remarks

When a symbol is removed, the indexes of the symbols that remain in the symbol group might change.

For more information about symbol groups, see [Scopes and Symbol Groups](https://learn.microsoft.com/windows-hardware/drivers/debugger/scopes-and-symbol-groups).

## See also

[AddSymbol](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbolgroup2-addsymbol)

[GetSymbolName](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbolgroup2-getsymbolname)

[IDebugSymbolGroup2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbolgroup2)

[RemoveSymbolByIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbolgroup2-removesymbolbyindex)