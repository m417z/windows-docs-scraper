# IDebugDataSpaces3::WritePhysical

## Description

The **WritePhysical** method writes data to the specified physical address in the target's memory.

## Parameters

### `Offset` [in]

Specifies the physical address of the memory to write the data to.

### `Buffer` [in]

Specifies the data to write.

### `BufferSize` [in]

Specifies the size in bytes of the buffer *Buffer*. This is the maximum number of bytes that will be written.

### `BytesWritten` [out, optional]

Receives the number of bytes written to the target's memory. If *BytesWritten* is **NULL**, this information is not returned.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

This method is only available in kernel-mode debugging.