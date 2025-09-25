# IDebugSymbols3::WriteTypedDataVirtual

## Description

The **WriteTypedDataVirtual** method writes data to the target's virtual address space. The number of bytes written is the size of the specified type.

## Parameters

### `Offset` [in]

Specifies the location in the target's virtual address space where the data will be written.

### `Module` [in]

Specifies the base address of the module containing the type.

### `TypeId` [in]

Specifies the type ID of the type.

### `Buffer` [in]

Specifies the buffer containing the data to be written.

### `BufferSize` [in]

Specifies the size in bytes of the buffer *Buffer*. This is the maximum number of bytes to be written.

### `BytesWritten` [out, optional]

Receives the number of bytes that were written. If *BytesWritten* is **NULL**, this information is not returned.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful. All the bytes in the buffer *Buffer* were written. However, the buffer was smaller than the size of the type specified. |

## Remarks

This is a convenience method. The same result can be obtained by calling [GetTypeSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-gettypesize) and [WriteVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-writevirtual).

For more information about types, see [Types](https://learn.microsoft.com/windows-hardware/drivers/debugger/types).