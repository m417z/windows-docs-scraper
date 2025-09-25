# IMFMediaEngine::GetDuration

## Description

Gets the duration of the media resource.

## Return value

Returns the duration, in seconds. If no media data is available, the method returns not-a-number (NaN). If the duration is unbounded, the method returns an infinite value.

## Remarks

This method corresponds to the **duration** attribute of the **HTMLMediaElement** interface in HTML5.

If the duration changes, the Media Engine sends an **MF_MEDIA_ENGINE_EVENT_DURATIONCHANGE** event. See [IMFMediaEngineNotify::EventNotify](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaenginenotify-eventnotify).

## See also

[IMFMediaEngine](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengine)