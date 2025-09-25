# IDebugSymbols::WriteTypedDataPhysical

## Description

The **WriteTypedDataPhysical** method writes the value of a variable in the target computer's physical memory.

## Parameters

### `Offset` [in]

Specifies the physical address in the target computer's memory of the variable.

### `Module` [in]

Specifies the base address of the module containing the type of the variable.

### `TypeId` [in]

Specifies the type ID of the type of the variable.

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
| **S_FALSE** | The method was successful. All the bytes in the buffer *Buffer* were written. However, the buffer was smaller than the size of the specified type. |

## Remarks

This method is only available in kernel mode debugging.

The number of bytes this method attempts to write is the smaller of the size of the buffer and the size of the variable.

This is a convenience method. The same result can be obtained by calling [GetTypeSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-gettypesize) and [WritePhysical](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-writephysical).

For more information about types, see [Types](https://learn.microsoft.com/windows-hardware/drivers/debugger/types).