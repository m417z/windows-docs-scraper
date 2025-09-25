# IMFByteStreamTimeSeek::IsTimeSeekSupported

## Description

Queries whether the byte stream supports time-based seeking.

## Parameters

### `pfTimeSeekIsSupported` [out]

Receives the value **TRUE** if the byte stream supports time-based seeking, or **FALSE** otherwise.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFByteStreamTimeSeek](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfbytestreamtimeseek)