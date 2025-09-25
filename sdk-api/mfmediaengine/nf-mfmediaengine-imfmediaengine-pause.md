# IMFMediaEngine::Pause

## Description

Pauses playback.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method corresponds to the **pause** method of the **HTMLMediaElement** interface in HTML5.

The method completes asynchronously. When the transition to paused is complete, the Media Engine sends an **MF_MEDIA_ENGINE_EVENT_PAUSE**  event. See [IMFMediaEventNotify::EventNotify](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaenginenotify-eventnotify).

Note that after you call **Pause**, the time returned by [GetCurrentTime](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-getcurrenttime) may not be precisely accurate. Apps that need a frame-accurate position value, such as media editors, should call [FrameStep](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengineex-framestep) immediately after calling **Pause** before calling **GetCurrentTime**.

## See also

[IMFMediaEngine](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengine)