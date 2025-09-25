# MFCreatePropertiesFromMediaType function

## Description

Creates properties from a [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype).

## Parameters

### `pMediaType` [in]

A pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface.

### `riid` [in]

The interface identifier (IID) of the interface being requested.

### `ppv` [out]

Receives a pointer to the requested interface. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)