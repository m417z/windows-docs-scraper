# IDebugDataSpaces4::WriteVirtualUncached

## Description

The **WriteVirtualUncached** method writes data to the target's virtual address space.

## Parameters

### `Offset` [in]

Specifies the location in the target's virtual address space to be written.

### `Buffer` [in]

Specifies the buffer to write the memory from.

### `BufferSize` [in]

Specifies the size in bytes of the buffer. This is also the number of bytes requested to be written.

### `BytesWritten` [out, optional]

Receives the number of bytes that were actually written. If it is set to **NULL**, this information is not returned.

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was at least partially successful. *BytesWritten* indicates the number of bytes successfully written, which may be less than *BufferSize*. |

## Remarks

This method writes the buffer to the memory in the target's virtual address space.

This method behaves identically to [WriteVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-writevirtual), except that it avoids using the virtual memory cache. It is therefore useful for reading inherently volatile virtual memory, such as memory-mapped device areas, without contaminating or invalidating the cache.

## See also

[IDebugDataSpaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces)

[IDebugDataSpaces2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces2)

[IDebugDataSpaces3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces3)

[IDebugDataSpaces4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces4)

[ReadVirtualUncached](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-readvirtualuncached)

[WriteVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-writevirtual)