# IDebugDataSpaces4::GetValidRegionVirtual

## Description

The **GetValidRegionVirtual** method locates the first valid region of memory in a specified memory range.

## Parameters

### `Base` [in]

Specifies the address of the beginning of the memory range to search for valid memory.

### `Size` [in]

Specifies the size, in bytes, of the memory range to search.

### `ValidBase` [out]

Receives the address of the beginning of the found valid memory.

### `ValidSize` [out]

Receives the size, in bytes, of the valid memory.

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## See also

[GetNextDifferentlyValidOffsetVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-getnextdifferentlyvalidoffsetvirtual)

[IDebugDataSpaces4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces4)