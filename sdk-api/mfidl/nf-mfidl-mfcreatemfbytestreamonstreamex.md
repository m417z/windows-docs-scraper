# MFCreateMFByteStreamOnStreamEx function

## Description

Creates a Microsoft Media Foundation byte stream that wraps an [IRandomAccessStream](https://learn.microsoft.com/previous-versions/hh438400(v=vs.85)) object.

## Parameters

### `punkStream` [in]

A pointer to the [IRandomAccessStream](https://learn.microsoft.com/previous-versions/hh438400(v=vs.85)) interface.

### `ppByteStream` [out]

Receives a pointer to the [IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream) interface. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)