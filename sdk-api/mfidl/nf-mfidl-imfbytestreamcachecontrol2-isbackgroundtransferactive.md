# IMFByteStreamCacheControl2::IsBackgroundTransferActive

## Description

Queries whether background transfer is active.

## Parameters

### `pfActive` [out]

Receives the value **TRUE** if background transfer is currently active, or **FALSE** otherwise.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Background transfer might stop because the cache limit was reached (see [IMFByteStreamCacheControl2::SetCacheLimit](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfbytestreamcachecontrol2-setcachelimit)) or because the [IMFByteStreamCacheControl::StopBackgroundTransfer](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfbytestreamcachecontrol-stopbackgroundtransfer) method was called.

## See also

[IMFByteStreamCacheControl2](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfbytestreamcachecontrol2)