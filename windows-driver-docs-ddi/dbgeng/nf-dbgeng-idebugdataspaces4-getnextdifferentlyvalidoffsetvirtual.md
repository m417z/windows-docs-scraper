# IDebugDataSpaces4::GetNextDifferentlyValidOffsetVirtual

## Description

The **GetNextDifferentlyValidOffsetVirtual** method returns the offset of the next address whose validity might be different from the validity of the specified address.

## Parameters

### `Offset` [in]

Specifies a start address. The address returned in *NextOffset* will be the next address whose validity might be defined differently from this one.

### `NextOffset` [out]

Receives the address of the next address whose validity might be defined differently from the address in *Offset*.

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The size of regions of validity depends on the target. For example, in live user-mode debugging sessions, where virtual address validity changes from page to page, *NextOffset* will receive the address of the next page. In user-mode dump files the validity can change from byte to byte.

## See also

[GetValidRegionVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-getvalidregionvirtual)

[IDebugDataSpaces4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces4)