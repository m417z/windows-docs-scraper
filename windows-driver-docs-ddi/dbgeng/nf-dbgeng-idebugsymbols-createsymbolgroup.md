# IDebugSymbols::CreateSymbolGroup

## Description

The **CreateSymbolGroup** method creates a new symbol group.

## Parameters

### `Group` [out]

Receives an interface pointer for the new [IDebugSymbolGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbolgroup) object.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

The newly created symbol group is empty; it does not contain any [symbols](https://learn.microsoft.com/windows-hardware/drivers/debugger/symbols4). Symbols may be added to the symbol group using [IDebugSymbolGroup::AddSymbol](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbolgroup2-addsymbol).

References to the returned object are managed like other COM objects, using the **IUnknown::AddRef** and **IUnknown::Release** methods. In particular, the **IUnknown::Release** method must be called when the returned object is no longer needed. See [Using Client Objects](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-client-objects) for more information about using COM interfaces in the Debugger Engine API.

For more information about symbol groups, see [Scopes and Symbol Groups](https://learn.microsoft.com/windows-hardware/drivers/debugger/scopes-and-symbol-groups).

## See also

[IDebugSymbolGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbolgroup)

[IDebugSymbolGroup::AddSymbol](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbolgroup2-addsymbol)

[IDebugSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols)

[IDebugSymbols2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols2)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)