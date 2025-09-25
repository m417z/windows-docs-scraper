# IDebugSymbolGroup2::GetSymbolOffset

## Description

The **GetSymbolOffset** method retrieves the location in the process's virtual address space of a symbol in a symbol group, if the symbol has an absolute address.

## Parameters

### `Index` [in]

The index of the symbol whose address you want. The index of a symbol is an identification number. The index ranges from zero through the number of symbols in the symbol group minus one.

### `Offset` [out]

The location in the process's virtual address space of the symbol.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOINTERFACE** | The symbol does not have an absolute address. |

This method can also return error values. For more information, see [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

## Remarks

For more information about symbol groups, see [Scopes and Symbol Groups](https://learn.microsoft.com/windows-hardware/drivers/debugger/scopes-and-symbol-groups).

## See also

[GetNumberSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbolgroup2-getnumbersymbols)

[IDebugSymbolGroup2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbolgroup2)