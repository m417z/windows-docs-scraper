# IMFMediaEngine::SetVolume

## Description

Sets the audio volume level.

## Parameters

### `Volume` [in]

The volume level. Volume is expressed as an attenuation level, where 0.0 indicates silence and 1.0 indicates full volume (no attenuation).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When the audio balance changes, the Media Engine sends an **MF_MEDIA_ENGINE_EVENT_VOLUMECHANGE** event. See [IMFMediaEventNotify::EventNotify](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaenginenotify-eventnotify).

## See also

[IMFMediaEngine](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengine)