# MFInitMediaTypeFromWaveFormatEx function

## Description

Initializes a media type from a **WAVEFORMATEX** structure.

## Parameters

### `pMFType`

Pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface of the media type to initialize. To create the uninitialized media type object, call [MFCreateMediaType](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreatemediatype).

### `pWaveFormat`

Pointer to a **WAVEFORMATEX** structure that describes the media type. The caller must fill in the structure members before calling this function.

### `cbBufSize`

Size of the **WAVEFORMATEX** structure, in bytes.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Media Type Conversions](https://learn.microsoft.com/windows/desktop/medfound/media-type-conversions)

[Media Types](https://learn.microsoft.com/windows/desktop/medfound/media-types)