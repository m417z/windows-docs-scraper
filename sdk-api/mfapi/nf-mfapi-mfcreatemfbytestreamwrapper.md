# MFCreateMFByteStreamWrapper function

## Description

Creates a wrapper for a byte stream.

## Parameters

### `pStream` [in]

A pointer to the [IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream) interface of the original byte stream.

### `ppStreamWrapper` [in]

Receives a pointer to the [IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream) interface of the wrapper. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The [IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream) methods on the wrapper call directly through to the original byte stream, except for the [IMFByteStream::Close](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfbytestream-close) method. Calling **Close** on the wrapper closes the wrapper object, but leaves the original byte stream open.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)