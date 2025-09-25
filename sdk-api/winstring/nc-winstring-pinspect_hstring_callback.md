## Description

Provides a function pointer to the callback used by the [WindowsInspectString](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowsinspectstring) function.

## Parameters

### `context`

[in]

Custom context data provided to the [WindowsInspectString](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowsinspectstring) function.

### `readAddress`

[in]

The address to read data from.

### `length`

[in]

The number of bytes to read, starting at *readAddress*.

### `buffer`

[out]

The buffer that receives a copy of the bytes that are read.

## Return value

If this function pointer succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Implement this callback when you use the [WindowsInspectString](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowsinspectstring) function. You can do a cross-process read, read from a dump file, or read from a remote debug debugging session.

## See also

[WindowsInspectString](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowsinspectstring)