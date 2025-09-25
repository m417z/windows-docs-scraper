# MFInitMediaTypeFromVideoInfoHeader function

## Description

Initializes a media type from a DirectShow **VIDEOINFOHEADER** structure.

## Parameters

### `pMFType`

Pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface of the media type to initialize. To create the uninitialized media type object, call [MFCreateMediaType](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreatemediatype).

### `pVIH`

Pointer to a **VIDEOINFOHEADER** structure that describes the media type. The caller must fill in the structure members before calling this function.

### `cbBufSize`

Size of the **VIDEOINFOHEADER** structure, in bytes.

### `pSubtype`

Pointer to a subtype GUID. This parameter can be **NULL**. If the subtype GUID is specified, the function uses it to set the media subtype. Otherwise, the function attempts to deduce the subtype from the **biCompression** field contained in the **VIDEOINFOHEADER** structure.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Media Type Conversions](https://learn.microsoft.com/windows/desktop/medfound/media-type-conversions)

[Media Types](https://learn.microsoft.com/windows/desktop/medfound/media-types)