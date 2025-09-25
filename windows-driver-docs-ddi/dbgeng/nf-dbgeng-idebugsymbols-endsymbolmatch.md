# IDebugSymbols::EndSymbolMatch

## Description

The **EndSymbolMatch** method releases the resources used by a symbol search.

## Parameters

### `Handle` [in]

Specifies the handle returned by [StartSymbolMatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-startsymbolmatch) when the search was initialized.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

This method releases the resources held by the engine during a symbol search. After these resources are released, the handle becomes invalid, so it must not be passed to [GetNextSymbolMatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getnextsymbolmatch) after it has been passed to this method.

For more information about symbols, see [Symbols](https://learn.microsoft.com/windows-hardware/drivers/debugger/symbols4).

## See also

[GetNextSymbolMatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getnextsymbolmatch)

[IDebugSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols)

[IDebugSymbols2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols2)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)

[StartSymbolMatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-startsymbolmatch)