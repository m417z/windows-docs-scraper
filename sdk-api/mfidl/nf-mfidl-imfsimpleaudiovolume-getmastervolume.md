# IMFSimpleAudioVolume::GetMasterVolume

## Description

Retrieves the master volume level.

## Parameters

### `pfLevel` [out]

Receives the volume level. Volume is expressed as an attenuation level, where 0.0 indicates silence and 1.0 indicates full volume (no attenuation).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_NOT_INITIALIZED** | The audio renderer is not initialized. |
| **MF_E_STREAMSINK_REMOVED** | The audio renderer was removed from the pipeline. |

## Remarks

If an external event changes the master volume, the audio renderer sends an [MEAudioSessionVolumeChanged](https://learn.microsoft.com/windows/desktop/medfound/meaudiosessionvolumechanged) event, which the Media Session forwards to the application.

## See also

[IMFSimpleAudioVolume](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsimpleaudiovolume)

[Streaming Audio Renderer](https://learn.microsoft.com/windows/desktop/medfound/streaming-audio-renderer)