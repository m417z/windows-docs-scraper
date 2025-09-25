# IMFByteStreamCacheControl2::GetByteRanges

## Description

Gets the ranges of bytes that are currently stored in the cache.

## Parameters

### `pcRanges` [out]

Receives the number of ranges returned in the *ppRanges* array.

### `ppRanges` [out]

Receives an array of [MF_BYTE_STREAM_CACHE_RANGE](https://learn.microsoft.com/windows/win32/api/mfidl/ns-mfidl-mf_byte_stream_cache_range) structures. Each structure specifies a range of bytes stored in the cache. The caller must free the array by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFByteStreamCacheControl2](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfbytestreamcachecontrol2)