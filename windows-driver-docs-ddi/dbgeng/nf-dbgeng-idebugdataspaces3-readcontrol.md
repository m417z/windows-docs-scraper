# IDebugDataSpaces3::ReadControl

## Description

The **ReadControl** method reads implementation-specific system data.

## Parameters

### `Processor` [in]

Specifies the processor whose information is to be read.

### `Offset` [in]

Specifies the offset in the control space of the memory to read.

### `Buffer` [out]

Receives the data read from the control-space memory.

### `BufferSize` [in]

Specifies the size in bytes of the buffer *Buffer*. This is the maximum number of bytes that will be read.

### `BytesRead` [out, optional]

Receives the number of bytes returned in the buffer *Buffer*. If *BytesRead* is **NULL**, this information is not returned.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

This method is only available in kernel-mode debugging.