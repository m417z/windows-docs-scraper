# IAudioMediaType::GetUncompressedAudioFormat

## Description

The `IAudioMediaType::GetUncompressedAudioFormat` returns information about the audio data format.

## Parameters

### `pUncompressedAudioFormat` [out]

Specifies a pointer to an [UNCOMPRESSEDAUDIOFORMAT](https://learn.microsoft.com/windows/desktop/api/audiomediatype/ns-audiomediatype-uncompressedaudioformat) structure.

## Return value

The `GetUncompressedAudioFormat` method returns S_OK if it is successful. Otherwise, it returns an error code.

## Remarks

The information that is returned is useful for uncompressed formats. However, this method call will succeed for compressed formats as well. When you make this function call for a compressed audio data format, you must determine whether the returned information is applicable to your compressed format.

## See also

[UNCOMPRESSEDAUDIOFORMAT](https://learn.microsoft.com/windows/desktop/api/audiomediatype/ns-audiomediatype-uncompressedaudioformat)