# IMFByteStreamCacheControl::StopBackgroundTransfer

## Description

Stops the background transfer of data to the local cache.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The byte stream resumes transferring data to the cache if the application does one of the following:

* Reads data from the byte stream.
* Calls the byte stream's [IMFByteStreamBuffering::EnableBuffering](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfbytestreambuffering-enablebuffering) method.

## See also

[IMFByteStreamCacheControl](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfbytestreamcachecontrol)