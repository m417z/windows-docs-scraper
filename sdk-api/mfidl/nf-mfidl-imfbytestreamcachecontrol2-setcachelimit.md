# IMFByteStreamCacheControl2::SetCacheLimit

## Description

Limits the cache size.

## Parameters

### `qwBytes` [in]

The maximum number of bytes to store in the cache, or **ULONGLONG_MAX**  for no limit. The default value is no limit.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFByteStreamCacheControl2](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfbytestreamcachecontrol2)