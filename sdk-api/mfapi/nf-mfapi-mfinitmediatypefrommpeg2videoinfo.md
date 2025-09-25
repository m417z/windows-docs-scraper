# MFInitMediaTypeFromMPEG2VideoInfo function

## Description

Initializes a media type from a DirectShow **MPEG2VIDEOINFO** structure.

## Parameters

### `pMFType`

Pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface of the media type to initialize. To create the uninitialized media type object, call [MFCreateMediaType](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreatemediatype).

### `pMP2VI`

Pointer to a **MPEG2VIDEOINFO** structure that describes the media type. The caller must fill in the structure members before calling this function.

### `cbBufSize`

Size of the **MPEG2VIDEOINFO** structure, in bytes.

### `pSubtype`

Pointer to a subtype GUID. This parameter can be **NULL**. If the subtype GUID is specified, the function uses it to set the media subtype. Otherwise, the function attempts to deduce the subtype from the **biCompression** field contained in the **MPEG2VIDEOINFO** structure.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Media Type Conversions](https://learn.microsoft.com/windows/desktop/medfound/media-type-conversions)

[Media Types](https://learn.microsoft.com/windows/desktop/medfound/media-types)