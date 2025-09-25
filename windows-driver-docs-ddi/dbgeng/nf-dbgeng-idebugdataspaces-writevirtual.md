# IDebugDataSpaces::WriteVirtual

## Description

The **WriteVirtual** method writes data to the target's virtual address space.

## Parameters

### `Offset` [in]

Specifies the location in the target's virtual address space to be written.

### `Buffer` [in]

Specifies the buffer to write the memory from.

### `BufferSize` [in]

Specifies the size in bytes of the buffer. This is also the number of bytes requested to be written.

### `BytesWritten` [out, optional]

Receives the number of bytes that were written. If it is set to **NULL**, this information is not returned.

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was at least partially successful. *BytesWritten* indicates the number of bytes successfully written, which may be less than *BufferSize*. |

## Remarks

This method writes the buffer to the memory in the target's virtual address space.

This method may only write to a cache of memory data when storing data. To avoid caching, use [WriteVirtualUncached](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-writevirtualuncached) instead.

## See also

[IDebugDataSpaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces)

[IDebugDataSpaces2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces2)

[IDebugDataSpaces3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces3)

[IDebugDataSpaces4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces4)

[ReadVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-readvirtual)

[WriteVirtualUncached](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-writevirtualuncached)