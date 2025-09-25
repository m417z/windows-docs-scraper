# IDebugDataSpaces3::ReadVirtualUncached

## Description

The **ReadVirtualUncached** method reads memory from the target's virtual address space.

## Parameters

### `Offset` [in]

Specifies the location in the target's virtual address space to be read.

### `Buffer` [out]

Specifies the buffer to read the memory into.

### `BufferSize` [in]

Specifies the size in bytes of the buffer. This is also the number of bytes being requested.

### `BytesRead` [out, optional]

Receives the number of bytes that were read. If it is set to **NULL**, this information is not returned.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. It is possible that *BytesRead* is less than *BufferSize*, but at least one byte of data is being returned. |

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

This method fills the buffer with the contents of the memory in the target's virtual address space.

This method behaves identically to [ReadVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-readvirtual), except that it avoids using the virtual memory cache. It is therefore useful for reading inherently volatile virtual memory, such as memory-mapped device areas, without contaminating or invalidating the cache.

## See also

[IDebugDataSpaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces)

[IDebugDataSpaces2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces2)

[IDebugDataSpaces3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces3)

[IDebugDataSpaces4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces4)

[ReadVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-readvirtual)

[WriteVirtualUncached](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-writevirtualuncached)