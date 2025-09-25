# IAVIStream::WriteData

## Description

The **WriteData** method writes headers for a stream. Called when an application uses the [AVIStreamWriteData](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avistreamwritedata) function.

## Parameters

### `fcc`

Four-character code of the stream header to write.

### `lp`

Pointer to the buffer that contains the header data to write.

### `cb`

Size, in bytes, of the buffer specified by *lpBuffer*.

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