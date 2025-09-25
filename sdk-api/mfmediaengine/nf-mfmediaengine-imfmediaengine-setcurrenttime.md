# IMFMediaEngine::SetCurrentTime

## Description

Seeks to a new playback position.

## Parameters

### `seekTime` [in]

The new playback position, in seconds.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method corresponds to setting the **currentTime** attribute of the **HTMLMediaElement** interface in HTML5.

The method completes asynchronously. When the seek operation starts, the Media Engine sends an **MF_MEDIA_ENGINE_EVENT_SEEKING** event. When the seek operation completes, the Media Engine sends an **MF_MEDIA_ENGINE_EVENT_SEEKED** event. See [IMFMediaEventNotify::EventNotify](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaenginenotify-eventnotify).

## See also

[IMFMediaEngine](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengine)