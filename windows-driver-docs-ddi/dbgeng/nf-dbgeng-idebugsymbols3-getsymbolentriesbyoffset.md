# IDebugSymbols3::GetSymbolEntriesByOffset

## Description

The **GetSymbolEntriesByOffset** method returns the [symbols](https://learn.microsoft.com/windows-hardware/drivers/debugger/symbols4) which are located at a specified address.

## Parameters

### `Offset` [in]

Specifies a location in the process's memory address space within the desired symbol's range. Not all symbols have a known range, so, for best results, use the base address of the symbol.

### `Flags` [in]

Set to zero.

### `Ids` [out, optional]

Receives the symbols. This is an array of *IdsCount* entries of type [DEBUG_MODULE_AND_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_module_and_id). If *Ids* is **NULL**, this information is not returned.

### `Displacements` [out, optional]

Receives the differences between the base addresses of the found symbols and the given address according to the symbol's range.

### `IdsCount` [in]

Specifies the number of entries that the arrays *Ids* and *Displacements* can hold.

### `Entries` [out, optional]

Receives the number of symbols located at *Offset*. If *Entries* is **NULL**, this information is not returned.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

For more information about symbols, see [Symbols](https://learn.microsoft.com/windows-hardware/drivers/debugger/symbols4).

## See also

[GetSymbolEntriesByName](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getsymbolentriesbyname)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)