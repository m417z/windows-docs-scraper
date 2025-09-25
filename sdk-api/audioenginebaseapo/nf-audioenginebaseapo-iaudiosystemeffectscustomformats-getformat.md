# IAudioSystemEffectsCustomFormats::GetFormat

## Description

The `GetFormat` method retrieves an [IAudioMediaType](https://learn.microsoft.com/windows/desktop/api/audiomediatype/nn-audiomediatype-iaudiomediatype) representation of a custom format.

## Parameters

### `nFormat` [in]

Specifies the index of a supported format. This parameter can be any value in the range from zero to one less than the return value of [GetFormatCount](https://learn.microsoft.com/windows/desktop/api/audioenginebaseapo/nf-audioenginebaseapo-iaudiosystemeffectscustomformats-getformatcount). In other words, any value in the range from zero to GetFormatCount( ) - 1.

### `ppFormat` [out, optional]

Specifies a pointer to a pointer to an **IAudioMediaType** interface. It is the responsibility of the caller to release the **IAudioMediaType** interface to which the *ppFormat* parameter points.

## Return value

The `GetFormat` method returns S_OK when the call is successful. Otherwise, it returns one of the error codes shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Invalid pointer passed to function |
| **E_OUTOFMEMORY** | Return buffer cannot be allocated |
| **E_INVALIDARG** | nFormat is out of range |

## Remarks

When the audio system calls the `GetFormat` method, the sAPO creates an audio media type object and returns an **IAudioMediaType** interface. The sAPO implementation can use the [CreateAudioMediaType](https://learn.microsoft.com/windows/desktop/api/audiomediatype/nf-audiomediatype-createaudiomediatype) utility function to create the audio media type object.

## See also

[CreateAudioMediaType](https://learn.microsoft.com/windows/desktop/api/audiomediatype/nf-audiomediatype-createaudiomediatype)

[GetFormatCount](https://learn.microsoft.com/windows/desktop/api/audioenginebaseapo/nf-audioenginebaseapo-iaudiosystemeffectscustomformats-getformatcount)

[IAudioMediaType](https://learn.microsoft.com/windows/desktop/api/audiomediatype/nn-audiomediatype-iaudiomediatype)