# CreateAudioMediaTypeFromUncompressedAudioFormat function

## Description

The `CreateAudioMediaTypeFromUncompressedAudioFormat` function uses the information provided in the [UNCOMPRESSEDAUDIOFORMAT](https://learn.microsoft.com/windows/desktop/api/audiomediatype/ns-audiomediatype-uncompressedaudioformat) structure to create a media type object that describes the audio format.

## Parameters

### `pUncompressedAudioFormat`

Specifies a pointer to an UNCOMPRESSEDAUDIOFORMAT structure.

### `ppIAudioMediaType`

Specifies a pointer to an [IAudioMediaType](https://learn.microsoft.com/windows/desktop/api/audiomediatype/nn-audiomediatype-iaudiomediatype) interface.

## Return value

The `CreateAudioMediaTypeFromUncompressedAudioFormat` function returns S_OK if the call to the function is successful. Otherwise, it returns an appropriate HRESULT error code.

## Remarks

When you implement custom audio system effects, the `CreateAudioMediaTypeFromUncompressedAudioFormat` function works with [IAudioSystemEffectsCustomFormats::GetFormat](https://learn.microsoft.com/windows/desktop/api/audioenginebaseapo/nf-audioenginebaseapo-iaudiosystemeffectscustomformats-getformat) to represent a custom audio data format and to provide information about the custom format.

## See also

[IAudioMediaType](https://learn.microsoft.com/windows/desktop/api/audiomediatype/nn-audiomediatype-iaudiomediatype)

[IAudioSystemEffectsCustomFormats::GetFormat](https://learn.microsoft.com/windows/desktop/api/audioenginebaseapo/nf-audioenginebaseapo-iaudiosystemeffectscustomformats-getformat)

[UNCOMPRESSEDAUDIOFORMAT](https://learn.microsoft.com/windows/desktop/api/audiomediatype/ns-audiomediatype-uncompressedaudioformat)