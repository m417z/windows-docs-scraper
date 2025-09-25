# MFCreateAudioMediaType function

## Description

[This API is not supported and may be altered or unavailable in the future.]

Creates an audio media type from a **WAVEFORMATEX** structure.

## Parameters

### `pAudioFormat` [in]

Pointer to a **WAVEFORMATEX** structure that describes the audio format.

### `ppIAudioMediaType` [out]

Receives a pointer to the [IMFAudioMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfaudiomediatype) interface. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The [IMFAudioMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfaudiomediatype) interface is deprecated, so applications should avoid using this function. To create a media type from a **WAVEFORMATEX** structure, do the following:

1. Call [MFCreateMediaType](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreatemediatype). This function returns a pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface. The returned media type object is initially empty.
2. Call [MFInitMediaTypeFromWaveFormatEx](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfinitmediatypefromwaveformatex) to populate the media type from the **WAVEFORMATEX** structure.

Alternatively, you can call [MFCreateMediaType](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreatemediatype) and then set the media type attributes directly.

This function is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[Audio Media Types](https://learn.microsoft.com/windows/desktop/medfound/audio-media-types)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Media Types](https://learn.microsoft.com/windows/desktop/medfound/media-types)