# MFCreateMFByteStreamOnStream function

## Description

Creates a Microsoft Media Foundation byte stream that wraps an **IStream** pointer.

## Parameters

### `pStream` [in]

A pointer to the **IStream** interface.

### `ppByteStream` [out]

Receives a pointer to the [IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream) interface. The caller must release the interface.

## Return value

Returns an **HRESULT** value.

## Remarks

This function enables applications to pass an **IStream** object to a Media Foundation API that takes an [IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream) pointer.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)