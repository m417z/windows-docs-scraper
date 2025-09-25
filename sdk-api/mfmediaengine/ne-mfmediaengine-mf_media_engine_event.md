# MF_MEDIA_ENGINE_EVENT enumeration

## Description

Defines event codes for the Media Engine.

## Constants

### `MF_MEDIA_ENGINE_EVENT_LOADSTART:1`

The Media Engine has started to load the source. See [IMFMediaEngine::Load](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-load).

### `MF_MEDIA_ENGINE_EVENT_PROGRESS:2`

The Media Engine is loading the source.

### `MF_MEDIA_ENGINE_EVENT_SUSPEND:3`

The Media Engine has suspended a load operation.

### `MF_MEDIA_ENGINE_EVENT_ABORT:4`

The Media Engine cancelled a load operation that was in progress.

### `MF_MEDIA_ENGINE_EVENT_ERROR:5`

An error occurred.

| Event Parameter | Description |
| --- | --- |
| *param1* | A member of the [MF_MEDIA_ENGINE_ERR](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/ne-mfmediaengine-mf_media_engine_err) enumeration. |
| *param2* | An **HRESULT** error code, or zero. |

### `MF_MEDIA_ENGINE_EVENT_EMPTIED:6`

The Media Engine has switched to the **MF_MEDIA_ENGINE_NETWORK_EMPTY** state. This can occur when the [IMFMediaEngine::Load](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-load) method is called, or if an error occurs during the **Load** method. See [IMFMediaEngine::GetNetworkState](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-getnetworkstate).

### `MF_MEDIA_ENGINE_EVENT_STALLED:7`

The [Load](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-load) algorithm is stalled, waiting for data.

### `MF_MEDIA_ENGINE_EVENT_PLAY:8`

The Media Engine is switching to the playing state. See [IMFMediaEngine::Play](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-play).

### `MF_MEDIA_ENGINE_EVENT_PAUSE:9`

The media engine has paused. See [IMFMediaEngine::Pause](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-pause).

### `MF_MEDIA_ENGINE_EVENT_LOADEDMETADATA:10`

The Media Engine has loaded enough source data to determine the duration and dimensions of the source.

### `MF_MEDIA_ENGINE_EVENT_LOADEDDATA:11`

The Media Engine has loaded enough data to render some content (for example, a video frame).

### `MF_MEDIA_ENGINE_EVENT_WAITING:12`

Playback has stopped because the next frame is not available.

### `MF_MEDIA_ENGINE_EVENT_PLAYING:13`

Playback has started. See [IMFMediaEngine::Play](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-play).

### `MF_MEDIA_ENGINE_EVENT_CANPLAY:14`

Playback can start, but the Media Engine might need to stop to buffer more data.

### `MF_MEDIA_ENGINE_EVENT_CANPLAYTHROUGH:15`

The Media Engine can probably play through to the end of the resource, without stopping to buffer data.

### `MF_MEDIA_ENGINE_EVENT_SEEKING:16`

The Media Engine has started seeking to a new playback position. See [IMFMediaEngine::SetCurrentTime](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-setcurrenttime).

### `MF_MEDIA_ENGINE_EVENT_SEEKED:17`

The Media Engine has seeked to a new playback position. See [IMFMediaEngine::SetCurrentTime](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-setcurrenttime).

### `MF_MEDIA_ENGINE_EVENT_TIMEUPDATE:18`

The playback position has changed. See [IMFMediaEngine::GetCurrentTime](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-getcurrenttime).

### `MF_MEDIA_ENGINE_EVENT_ENDED:19`

Playback has reached the end of the source. This event is not sent if the [GetLoop](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-getloop) is **TRUE**.

### `MF_MEDIA_ENGINE_EVENT_RATECHANGE:20`

The playback rate has changed. See [IMFMediaEngine::SetPlaybackRate](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-setplaybackrate).

### `MF_MEDIA_ENGINE_EVENT_DURATIONCHANGE:21`

The duration of the media source has changed. See [IMFMediaEngine::GetDuration](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaitem-getduration).

### `MF_MEDIA_ENGINE_EVENT_VOLUMECHANGE:22`

The audio volume changed. See [IMFMediaEngine::SetVolume](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-setvolume).

### `MF_MEDIA_ENGINE_EVENT_FORMATCHANGE:1000`

The output format of the media source has changed.

| Event Parameter | Description |
| --- | --- |
| *param1* | Zero if the video format changed, 1 if the audio format changed. |
| *param2* | Zero. |

### `MF_MEDIA_ENGINE_EVENT_PURGEQUEUEDEVENTS:1001`

The Media Engine flushed any pending events from its queue.

### `MF_MEDIA_ENGINE_EVENT_TIMELINE_MARKER:1002`

The playback position reached a timeline marker. See [IMFMediaEngineEx::SetTimelineMarkerTimer](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengineex-settimelinemarkertimer).

### `MF_MEDIA_ENGINE_EVENT_BALANCECHANGE:1003`

The audio balance changed. See [IMFMediaEngineEx::SetBalance](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengineex-setbalance).

### `MF_MEDIA_ENGINE_EVENT_DOWNLOADCOMPLETE:1004`

The Media Engine has finished downloading the source data.

### `MF_MEDIA_ENGINE_EVENT_BUFFERINGSTARTED:1005`

The media source has started to buffer data.

### `MF_MEDIA_ENGINE_EVENT_BUFFERINGENDED:1006`

The media source has stopped buffering data.

### `MF_MEDIA_ENGINE_EVENT_FRAMESTEPCOMPLETED:1007`

The [IMFMediaEngineEx::FrameStep](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengineex-framestep) method completed.

### `MF_MEDIA_ENGINE_EVENT_NOTIFYSTABLESTATE:1008`

The Media Engine's [Load](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-load) algorithm is waiting to start.

| Event Parameter | Description |
| --- | --- |
| *param1* | A handle to a waitable event, of type **HANDLE**. |
| *param2* | Zero. |

If Media Engine is created with the **MF_MEDIA_ENGINE_WAITFORSTABLE_STATE** flag, the Media Engine sends the **MF_MEDIA_ENGINE_EVENT_NOTIFYSTABLESTATE** event at the start of the [Load](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-load) algorithm. The *param1* parameter is a handle to a waitable event. The **Load** thread waits for the application to signal the event by calling [SetEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-setevent).

If the Media Engine is not created with the **MF_MEDIA_ENGINE_WAITFORSTABLE_STATE**, it does not send this event, and the [Load](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-load) thread does not wait to be signalled.

### `MF_MEDIA_ENGINE_EVENT_FIRSTFRAMEREADY:1009`

The first frame of the media source is ready to render.

### `MF_MEDIA_ENGINE_EVENT_TRACKSCHANGE:1010`

Raised when a new track is added or removed.

Supported in Windows 8.1 and later.

### `MF_MEDIA_ENGINE_EVENT_OPMINFO:1011`

Raised when there is new information about the [Output Protection Manager](https://learn.microsoft.com/windows/desktop/medfound/output-protection-manager) (OPM).

This event will be raised when an OPM failure occurs, but ITA allows fallback without the OPM. In this case, constriction can be applied.

This event will not be raised when there is an OPM failure and the fallback also fails. For example, if ITA blocks playback entirely when OPM cannot be established.

Supported in Windows 8.1 and later.

### `MF_MEDIA_ENGINE_EVENT_RESOURCELOST:1012`

### `MF_MEDIA_ENGINE_EVENT_DELAYLOADEVENT_CHANGED:1013`

### `MF_MEDIA_ENGINE_EVENT_STREAMRENDERINGERROR:1014`

Raised when one of the component streams of a media stream fails. This event is only raised if the media stream contains other component streams that did not fail.

### `MF_MEDIA_ENGINE_EVENT_SUPPORTEDRATES_CHANGED:1015`

### `MF_MEDIA_ENGINE_EVENT_AUDIOENDPOINTCHANGE:1016`

## Remarks

The application receives Media Engine events through the [IMFMediaEngineNotify::EventNotify](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaenginenotify-eventnotify) method. The **EventNotify** method includes two event parameters, *param1* and *param2*. The meaning of the parameters depends on the event code. If the event description does not list any parameters, ignore the values of *param1* and *param2*.

Values below 1000 correspond to events defined in HTML 5 for media elements.

## See also

[IMFMediaEngineNotify::EventNotify](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaenginenotify-eventnotify)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)