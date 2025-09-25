# IDebugDataSpaces4::ReadPhysical2

## Description

The **ReadPhysical2** method reads the target's memory from the specified physical address.

## Parameters

### `Offset` [in]

Specifies the physical address of the memory to read.

### `Flags` [in]

Specifies the properties of the physical memory to be read. This must match the way the physical memory was advertised to the operating system on the target. Possible values are listed in the following table.

| Value | Description |
| --- | --- |
| DEBUG_PHYSICAL_DEFAULT | Use the default memory caching. |
| DEBUG_PHYSICAL_CACHED | The physical memory is cached. |
| DEBUG_PHYSICAL_UNCACHED | The physical memory is uncached. |
| DEBUG_PHYSICAL_WRITE_COMBINED | The physical memory is write-combined. |

### `Buffer` [out]

Receives the memory that is read.

### `BufferSize` [in]

Specifies the size, in bytes, of the *Buffer* buffer. This is the maximum number of bytes that will be read.

### `BytesRead` [out, optional]

Receives the number of bytes read from the target's memory. If *BytesRead* is **NULL**, this information is not returned.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

This method is only available in kernel-mode debugging.

The flags DEBUG_PHYSICAL_CACHED, DEBUG_PHYSICAL_UNCACHED, and DEBUG_PHYSICAL_WRITE_COMBINED can only be used when the target is a live kernel target that is being debugged in the standard way (using a COM port, 1394 bus, or named pipe).

## See also

[IDebugDataSpaces4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces4)

[ReadPhysical](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-readphysical)

[WritePhysical2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-writephysical2)