# IAVIFile::WriteData

## Description

The **WriteData** method writes file headers. Called when an application uses the [AVIFileWriteData](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avifilewritedata) function.

## Parameters

### `ckid`

A chunk ID.

### `lpData`

A pointer specifying the memory from which the data is written.

### `cbData`

A LONG specifying the number of bytes to write.

## Return value

Returns the HRESULT defined by OLE.

## Remarks

For handlers written in C++, **WriteData** has the following syntax:

```cpp

HRESULT WriteData(DWORD fcc, LPVOID lpBuffer, LONG cbBuffer);

```

## See also

[Custom File and Stream Handler Interfaces](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handler-interfaces)

[Custom File and Stream Handlers](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handlers)