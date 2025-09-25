# IAVIStream::ReadFormat

## Description

The **ReadFormat** method obtains format information from a stream. Fills and returns a structure with the data in an application-defined buffer. If no buffer is supplied, determines the buffer size needed to retrieve the buffer of format data. Called when an application uses the [AVIStreamReadFormat](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avistreamreadformat) function.

## Parameters

### `lPos`

Position of the sample or frame.

### `lpFormat`

Pointer to the buffer for the format data. Specify **NULL** to request the required size of the buffer.

### `lpcbFormat`

Pointer to a buffer that receives the size, in bytes, of the buffer specified by *lpFormat*. When this method is called, the contents of this parameter indicates the size of the buffer specified by *lpFormat*. When this method returns control to the application, the contents of this parameter specifies the amount of data read or the required size of the buffer.

#### - ps

Pointer to the interface to a stream.

## Return value

Returns the HRESULT defined by OLE.

## Remarks

The type of data stored in a stream dictates the format information and the structure that contains the format information. A stream handler should return all applicable format information in this structure, including palette information when the format uses a palette. A stream handler should not return stream data with the structure.

Standard video stream handlers provide format information in a **BITMAPINFOHEADER** structure. Standard audio stream handlers provide format information in a **PCMWAVEFORMAT** structure. Other data streams can use other structures that describe the stream data.

For handlers written in C++, **ReadFormat** has the following syntax:

```cpp

HRESULT ReadFormat(LONG lPos, LPVOID lpFormat,
    LONG *lpcbFormat)

```

## See also

[Custom File and Stream Handler Interfaces](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handler-interfaces)

[Custom File and Stream Handlers](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handlers)