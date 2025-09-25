# CreateAudioMediaType function

## Description

The `CreateAudioMediaType` function uses the format specified by the caller to create a media type object that describes the audio format.

## Parameters

### `pAudioFormat`

Specifies a pointer to a WAVEFORMATEX structure.

### `cbAudioFormatSize`

Specifies the size of the WAVEFORMATEX structure pointed to by the *pAudioFormat* parameter.

### `ppIAudioMediaType`

Specifies a pointer to an [IAudioMediaType](https://learn.microsoft.com/windows/desktop/api/audiomediatype/nn-audiomediatype-iaudiomediatype) interface.

## Return value

The `CreateAudioMediaType` function returns S_OK if the call to the function is successful. Otherwise, it returns an appropriate HRESULT error code.

## Remarks

When you implement custom audio system effects, the `CreateAudioMediaType` function works with [IAudioSystemEffectsCustomFormats::GetFormat](https://learn.microsoft.com/windows/desktop/api/audioenginebaseapo/nf-audioenginebaseapo-iaudiosystemeffectscustomformats-getformat) to represent a custom audio data format and to provide information about the custom format.

## See also

[IAudioMediaType](https://learn.microsoft.com/windows/desktop/api/audiomediatype/nn-audiomediatype-iaudiomediatype)

[IAudioSystemEffectsCustomFormats::GetFormat](https://learn.microsoft.com/windows/desktop/api/audioenginebaseapo/nf-audioenginebaseapo-iaudiosystemeffectscustomformats-getformat)

[WAVEFORMATEX](https://learn.microsoft.com/windows/win32/api/mmreg/ns-mmreg-waveformatex)