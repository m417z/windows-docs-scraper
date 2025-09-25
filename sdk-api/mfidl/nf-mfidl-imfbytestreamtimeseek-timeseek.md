# IMFByteStreamTimeSeek::TimeSeek

## Description

Seeks to a new position in the byte stream.

## Parameters

### `qwTimePosition`

The new position, in 100-nanosecond units.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the byte stream reads from a server, it might cache the seek request until the next read request. Therefore, the byte stream might not send a request to the server immediately.

## See also

[IMFByteStreamTimeSeek](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfbytestreamtimeseek)