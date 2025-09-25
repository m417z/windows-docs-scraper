# IAVIStream::Read

## Description

The **Read** method reads data from a stream and copies it to an application-defined buffer. If no buffer is supplied, it determines the buffer size needed to retrieve the next buffer of data. Called when an application uses the [AVIStreamRead](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avistreamread) function.

## Parameters

### `lStart`

Starting sample or frame number to read.

### `lSamples`

Number of samples to read.

### `lpBuffer`

Pointer to the application-defined buffer to contain the stream data. You can also specify **NULL** to request the required size of the buffer. Many applications precede each read operation with a query for the buffer size to see how large a buffer is needed.

### `cbBuffer`

Size, in bytes, of the buffer specified by *lpBuffer*.

### `plBytes`

Pointer to a buffer that receives the number of bytes read.

### `plSamples`

Pointer to a buffer that receives the number of samples read.

#### - ps

Pointer to the interface to a stream.

## Return value

Returns AVIERR_OK if successful or AVIERR_BUFFERTOOSMALL if the buffer is not large enough to hold the data. If successful, **Read** also returns either a buffer of data with the number of frames (samples) included in the buffer or the required buffer size, in bytes.

## Remarks

For handlers written in C++, **Read** has the following syntax:

```cpp

HRESULT Read(LONG lStart, LONG lSamples,
    LPVOID lpBuffer, LONG cbBuffer,
    LONG *plBytes, LONG *plSamples);

```

## See also

[Custom File and Stream Handler Interfaces](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handler-interfaces)

[Custom File and Stream Handlers](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handlers)