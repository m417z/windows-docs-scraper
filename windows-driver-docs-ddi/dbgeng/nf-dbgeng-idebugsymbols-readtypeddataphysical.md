# IDebugSymbols::ReadTypedDataPhysical

## Description

The **ReadTypedDataPhysical** method reads the value of a variable from the target computer's physical memory.

## Parameters

### `Offset` [in]

Specifies the physical address in the target computer's memory of the variable to be read.

### `Module` [in]

Specifies the base address of the module containing the type of the variable.

### `TypeId` [in]

Specifies the type ID of the type of the variable.

### `Buffer` [out]

Receives the data that was read.

### `BufferSize` [in]

Specifies the size in bytes of the buffer *Buffer*. This is the maximum number of bytes that will be read.

### `BytesRead` [out, optional]

Receives the number of bytes that were read. If *BytesRead* is **NULL**, this information is not returned.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful. However, the buffer *Buffer* was not large enough to hold all the data and it was truncated. |

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

This method is only available in kernel mode debugging.

The number of bytes this method attempts to read is the smaller of the size of the buffer and the size of the variable.

This is a convenience method. The same result can be obtained by calling [GetTypeSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-gettypesize) and [ReadPhysical](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-readphysical).

For more information about types, see [Types](https://learn.microsoft.com/windows-hardware/drivers/debugger/types).