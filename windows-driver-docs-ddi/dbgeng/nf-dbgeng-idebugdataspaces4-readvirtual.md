# IDebugDataSpaces4::ReadVirtual

## Description

The **ReadVirtual** method reads memory from the target's virtual address space.

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
| **S_OK** | The method was successful. It is possible that *BytesRead* is less than *BufferSize*, but at least one byte of data was returned. |

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

This method fills the buffer with the contents of the memory in the target's virtual address space.

This method may reference a cache of memory data when retrieving data. If the data is volatile, such as memory-mapped hardware state, use [ReadVirtualUncached](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-readvirtualuncached) instead.

When reading memory that contains pointers, these pointers are for the target's virtual address space and not the engine's. For example, if a data structure contained a string, a second call to this method may be needed to read the contents of the string.

## See also

[IDebugDataSpaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces)

[IDebugDataSpaces2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces2)

[IDebugDataSpaces3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces3)

[IDebugDataSpaces4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces4)

[ReadVirtualUncached](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-readvirtualuncached)

[WriteVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-writevirtual)