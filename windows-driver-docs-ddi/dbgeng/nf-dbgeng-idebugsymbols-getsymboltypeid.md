# IDebugSymbols::GetSymbolTypeId

## Description

The **GetSymbolTypeId** method returns the type ID and module of the specified symbol.

## Parameters

### `Symbol` [in]

Specifies the expression whose type ID is requested. See the Remarks section for details on the syntax of this expression.

### `TypeId` [out]

Receives the type ID.

### `Module` [out, optional]

Receives the base address of the module containing the symbol. For more information, see [Modules](https://learn.microsoft.com/windows-hardware/drivers/debugger/modules). If *Module* is **NULL**, this information is not returned.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful |

## Remarks

The Symbol expression may contain structure fields, pointer dereferencing, and array dereferencing -- for example **my_struct.some_field[0]**.

For more information about symbols, see [Symbols](https://learn.microsoft.com/windows-hardware/drivers/debugger/symbols4).

## See also

[GetSymbolTypeId](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getsymboltypeid)

[GetTypeId](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-gettypeid)

[IDebugSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols)

[IDebugSymbols2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols2)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)