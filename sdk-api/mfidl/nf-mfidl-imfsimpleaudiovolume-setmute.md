# IMFSimpleAudioVolume::SetMute

## Description

Mutes or unmutes the audio.

## Parameters

### `bMute` [in]

Specify **TRUE** to mute the audio, or **FALSE** to unmute the audio.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_NOT_INITIALIZED** | The audio renderer is not initialized. |
| **MF_E_STREAMSINK_REMOVED** | The audio renderer was removed from the pipeline. |

## Remarks

This method does not change the volume level returned by the [IMFSimpleAudioVolume::GetMasterVolume](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfsimpleaudiovolume-getmastervolume) function.

## See also

[IMFSimpleAudioVolume](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsimpleaudiovolume)

[Streaming Audio Renderer](https://learn.microsoft.com/windows/desktop/medfound/streaming-audio-renderer)