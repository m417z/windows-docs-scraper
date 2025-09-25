# IDebugSymbols::GetOffsetTypeId

## Description

The **GetOffsetTypeId** method returns the type ID of the symbol closest to the specified memory location.

## Parameters

### `Offset` [in]

Specifies the location in the target's memory for the symbol. The symbol closest to this location is used.

### `TypeId` [out]

Receives the type ID of the symbol.

### `Module` [out, optional]

Specifies the location in the target's memory address space of the base of the module to which the symbol belongs. For more information, see [Modules](https://learn.microsoft.com/windows-hardware/drivers/debugger/modules). If *Module* is **NULL**, this information is not returned.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful |

## Remarks

For more information about symbols, see [Symbols](https://learn.microsoft.com/windows-hardware/drivers/debugger/symbols4).

## See also

[GetSymbolTypeId](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getsymboltypeid)

[GetTypeId](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-gettypeid)

[IDebugSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols)

[IDebugSymbols2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols2)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)