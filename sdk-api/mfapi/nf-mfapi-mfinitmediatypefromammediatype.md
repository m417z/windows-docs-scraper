# MFInitMediaTypeFromAMMediaType function

## Description

Initializes a media type from a DirectShow **AM_MEDIA_TYPE** structure.

## Parameters

### `pMFType`

Pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface of the media type to initialize. To create the uninitialized media type object, call [MFCreateMediaType](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreatemediatype).

### `pAMType`

Pointer to an **AM_MEDIA_TYPE** structure that describes the media type. The caller must fill in the structure members before calling this function.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## Remarks

This function can also be used with the following format structures that are equivalent to **AM_MEDIA_TYPE**:

* **DMO_MEDIA_TYPE** (DirectX Media Objects)
* **WM_MEDIA_TYPE** (Windows Media Format SDK)

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Media Type Conversions](https://learn.microsoft.com/windows/desktop/medfound/media-type-conversions)

[Media Types](https://learn.microsoft.com/windows/desktop/medfound/media-types)