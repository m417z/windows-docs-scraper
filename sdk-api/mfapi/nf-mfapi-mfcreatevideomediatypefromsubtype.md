# MFCreateVideoMediaTypeFromSubtype function

## Description

Creates a partial video media type with a specified subtype.

## Parameters

### `pAMSubtype` [in]

Pointer to a GUID that specifies the subtype. See [Video Subtype GUIDs](https://learn.microsoft.com/windows/desktop/medfound/video-subtype-guids).

### `ppIVideoMediaType` [out]

Receives a pointer to the [IMFVideoMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfvideomediatype) interface. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function creates a media type and sets the major type equal to **MFMediaType_Video** and the subtype equal to the value specified in *pAMSubtype*.

You can get the same result with the following steps:

1. Call [MFCreateMediaType](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreatemediatype). This function returns a pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface.
2. Set the [MF_MT_MAJOR_TYPE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-major-type-attribute) attribute to **MFMediaType_Video**.
3. Set the [MF_MT_SUBTYPE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-subtype-attribute) attribute to the subtype.

**Note** Prior to Windows 7, this function was exported from evr.dll. Starting in Windows 7, this function is exported from mfplat.dll, and evr.dll exports a stub function that calls into mfplat.dll. For more information, see [Library Changes in Windows 7](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-headers-and-libraries).

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Media Types](https://learn.microsoft.com/windows/desktop/medfound/media-types)