# IMemoryBufferByteAccess::GetBuffer

## Description

Gets an [IMemoryBuffer](https://learn.microsoft.com/uwp/api/windows.foundation.imemorybuffer) as an array of bytes.

## Parameters

### `value` [out]

A pointer to a byte array containing the buffer data.

### `capacity` [out]

The number of bytes in the returned array

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When [MemoryBuffer::Close](https://learn.microsoft.com/uwp/api/windows.foundation.memorybuffer.close) is called, the code using this buffer should set the *value* pointer to null.

## See also

[IMemoryBufferByteAccess](https://learn.microsoft.com/previous-versions/mt297505(v=vs.85))