# IDebugSymbols::ReadTypedDataVirtual

## Description

The **ReadTypedDataVirtual** method reads the value of a variable in the target's virtual memory.

## Parameters

### `Offset` [in]

Specifies the location in the target's virtual address space of the variable to read.

### `Module` [in]

Specifies the base address of the module containing the type of the variable.

### `TypeId` [in]

Specifies the type ID of the type.

### `Buffer` [out]

Receives the data that is read.

### `BufferSize` [in]

Specifies the size in bytes of the buffer *Buffer*. This is the maximum number of bytes to be read.

### `BytesRead` [out, optional]

Receives the number of bytes that were read. If *BytesRead* is **NULL**, this information is not returned.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful. However, the buffer *Buffer* was not large enough to hold all the data and it was truncated. |

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

The number of bytes this method attempts to read is the smaller of the size of the buffer and the size of the variable.

This is a convenience method. The same result can be obtained by calling [GetTypeSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-gettypesize) and [ReadVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-readvirtual).

For more information about types, see [Types](https://learn.microsoft.com/windows-hardware/drivers/debugger/types).