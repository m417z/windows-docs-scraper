# IDebugDataSpaces2::ReadPhysical

## Description

The **ReadPhysical** method reads the target's memory from the specified physical address.

## Parameters

### `Offset` [in]

Specifies the physical address of the memory to read.

### `Buffer` [out]

Receives the memory that is read.

### `BufferSize` [in]

Specifies the size in bytes of the buffer *Buffer*. This is the maximum number of bytes that will be read.

### `BytesRead` [out, optional]

Receives the number of bytes read from the target's memory. If *BytesRead* is **NULL**, this information is not returned.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

This method is only available in kernel-mode debugging.