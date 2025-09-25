# IDebugDataSpaces::WriteControl

## Description

The **WriteControl** method writes implementation-specific system data.

## Parameters

### `Processor` [in]

Specifies the processor whose information is to be written.

### `Offset` [in]

Specifies the offset of the control space of the memory to write.

### `Buffer` [in]

Specifies the data to write to the control-space memory.

### `BufferSize` [in]

Specifies the size in bytes of the buffer *Buffer*. This is the maximum number of bytes that will be written.

### `BytesWritten` [out, optional]

Receives the number of bytes returned in the buffer *Buffer*. If *BytesWritten* is **NULL**, this information is not returned.

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

This method is only available in kernel-mode debugging.