# IMFSimpleAudioVolume::GetMute

## Description

Queries whether the audio is muted.

## Parameters

### `pbMute` [out]

Receives a Boolean value. If **TRUE**, the audio is muted; otherwise, the audio is not muted.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_NOT_INITIALIZED** | The audio renderer is not initialized. |
| **MF_E_STREAMSINK_REMOVED** | The audio renderer was removed from the pipeline. |

## Remarks

Calling [IMFSimpleAudioVolume::SetMasterVolume](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfsimpleaudiovolume-setmastervolume) to set the volume does not change whether the audio is muted.

## See also

[IMFSimpleAudioVolume](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsimpleaudiovolume)

[Streaming Audio Renderer](https://learn.microsoft.com/windows/desktop/medfound/streaming-audio-renderer)