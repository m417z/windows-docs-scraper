# IAVIStream::Write

## Description

The **Write** method writes data to a stream. Called when an application uses the [AVIStreamWrite](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avistreamwrite) function.

## Parameters

### `lStart`

Starting sample or frame number to write.

### `lSamples`

Number of samples to write.

### `lpBuffer`

Pointer to the buffer for the data.

### `cbBuffer`

Size, in bytes, of the buffer specified by *lpBuffer*.

### `dwFlags`

Applicable flags. The AVIF_KEYFRAME flag is defined and indicates that this frame contains all the information needed for a complete image.

### `plSampWritten`

Pointer to a buffer used to contain the number of samples written.

### `plBytesWritten`

Pointer to a buffer that receives the number of bytes written.

#### - ps

Pointer to the interface to a stream.

## Return value

Returns the HRESULT defined by OLE.

## Remarks

For handlers written in C++, **Write** has the following syntax:

```cpp

HRESULT Write(LONG lStart, LONG lSamples, LPVOID lpBuffer,
    LONG cbBuffer, DWORD dwFlags, LONG *plSampWritten,
    LONG *plBytesWritten);

```

## See also

[Custom File and Stream Handler Interfaces](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handler-interfaces)

[Custom File and Stream Handlers](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handlers)