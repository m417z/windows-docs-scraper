# IAVIStream::ReadData

## Description

The **ReadData** method reads data headers of a stream. Called when an application uses the [AVIStreamReadData](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avistreamreaddata) function.

## Parameters

### `fcc`

Four-character code of the stream header to read.

### `lp`

Pointer to the buffer to contain the header data.

### `lpcb`

Size, in bytes, of the buffer specified by *lpBuffer*. When this method returns control to the application, the contents of this parameter specifies the amount of data read.

## Return value

Returns the HRESULT defined by OLE.

## Remarks

For handlers written in C++, **ReadData** has the following syntax:

```cpp

HRESULT ReadData(DWORD fcc, LPVOID lp, LONG *lpcb);

```

## See also

[Custom File and Stream Handler Interfaces](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handler-interfaces)

[Custom File and Stream Handlers](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handlers)