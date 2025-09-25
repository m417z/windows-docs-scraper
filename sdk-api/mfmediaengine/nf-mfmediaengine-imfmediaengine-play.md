# IMFMediaEngine::Play

## Description

Starts playback.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method corresponds to the **play** method of the **HTMLMediaElement** interface in HTML5.

The method completes asynchronously. When the operation starts, the Media Engine sends an **MF_MEDIA_ENGINE_EVENT_PLAY** event. When playback is under way, the Media Engine sends an **MF_MEDIA_ENGINE_EVENT_PLAYING** event. See [IMFMediaEventNotify::EventNotify](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaenginenotify-eventnotify).

## See also

[IMFMediaEngine](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengine)