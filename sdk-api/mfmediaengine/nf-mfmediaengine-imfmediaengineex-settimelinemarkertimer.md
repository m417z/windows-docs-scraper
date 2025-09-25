# IMFMediaEngineEx::SetTimelineMarkerTimer

## Description

Specifies a presentation time when the Media Engine will send a marker event.

## Parameters

### `timeToFire` [in]

The presentation time for the marker event, in seconds.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When playback reaches the time specified by *timeToFire*, the Media Engine sends an **MF_MEDIA_ENGINE_EVENT_TIMELINE_MARKER** event through the [IMFMediaEngineNotify::EventNotify](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaenginenotify-eventnotify) method. Calling this method cancels any previous marker that is still pending.

If the application seeks past the marker point, the Media Engine cancels the marker and does not send the event.

During forward playback, set *timeToFire* to a value greater than the current playback position. During reverse playback, set *timeToFire* to a value less than the playback position.

To cancel a marker, call [IMFMediaEngineEx::CancelTimelineMarkerTimer](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengineex-canceltimelinemarkertimer).

## See also

[IMFMediaEngineEx](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengineex)