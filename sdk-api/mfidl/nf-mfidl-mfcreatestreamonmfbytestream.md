# MFCreateStreamOnMFByteStream function

## Description

Returns an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) pointer that wraps a Microsoft Media Foundation byte stream.

## Parameters

### `pByteStream` [in]

A pointer to the [IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream) interface of the Media Foundation byte stream.

### `ppStream` [out]

Receives a pointer to the [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function enables an application to pass a Media Foundation byte stream to an API that takes an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) pointer.

## See also

[MFCreateMFByteStreamOnStream](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-mfcreatemfbytestreamonstream)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)