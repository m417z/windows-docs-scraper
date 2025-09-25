# MFUnwrapMediaType function

## Description

Retrieves a media type that was wrapped in another media type by the [MFWrapMediaType](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfwrapmediatype) function.

## Parameters

### `pWrap`

Pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface of the media type that was retrieved by [MFWrapMediaType](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfwrapmediatype).

### `ppOrig`

Receives a pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface of the original media type. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)