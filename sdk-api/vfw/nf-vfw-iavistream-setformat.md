# IAVIStream::SetFormat

## Description

The **SetFormat** method sets format information in a stream. Called when an application uses the [AVIStreamSetFormat](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avistreamsetformat) function.

## Parameters

### `lPos`

Pointer to the interface to a stream.

### `lpFormat`

Pointer to the buffer for the format data.

### `cbFormat`

Address containing the size, in bytes, of the buffer specified by *lpFormat*.

## Return value

Returns the HRESULT defined by OLE.

## Remarks

Standard video stream handlers provide format information in a **BITMAPINFOHEADER** structure. Standard audio stream handlers provide format information in a **PCMWAVEFORMAT** structure. Other data streams can use other structures that describe the stream data.

For handlers written in C++, **SetFormat** has the following syntax:

```cpp

HRESULT SetFormat(LONG lPos, LPVOID lpFormat, LONG cbFormat)

```

## See also

[Custom File and Stream Handler Interfaces](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handler-interfaces)

[Custom File and Stream Handlers](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handlers)