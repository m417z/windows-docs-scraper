# MFWaveFormatExConvertFlags enumeration

## Description

Contains flags that specify how to convert an audio media type.

## Constants

### `MFWaveFormatExConvertFlag_Normal:0`

Convert the media type to a **WAVEFORMATEX** structure if possible, or a **WAVEFORMATEXTENSIBLE** structure otherwise.

### `MFWaveFormatExConvertFlag_ForceExtensible:1`

Convert the media type to a **WAVEFORMATEXTENSIBLE** structure.

## See also

[MFCreateWaveFormatExFromMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreatewaveformatexfrommfmediatype)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)