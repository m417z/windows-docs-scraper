# MFP_MF_EVENT structure

## Description

\[The feature associated with this page, MFPlay, is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** and **IMFMediaEngine** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Event structure for the **MFP_EVENT_TYPE_MF** event. The MFPlay player object uses this event to forward certain events from the Media Foundation pipeline to the application.

## Members

### `header`

[MFP_EVENT_HEADER](https://learn.microsoft.com/windows/desktop/api/mfplay/ns-mfplay-mfp_event_header) structure that contains data common to all [IMFPMediaPlayer](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaplayer) events.

### `MFEventType`

Media Foundation event type. Currently, the MFPlay player object forwards the following pipeline events to the application:

| Event | Description |
| --- | --- |
| [MEBufferingStarted](https://learn.microsoft.com/windows/desktop/medfound/mebufferingstarted) | The source has started buffering data. |
| [MEBufferingStopped](https://learn.microsoft.com/windows/desktop/medfound/mebufferingstopped) | The source has stopped buffering data. |
| [MEExtendedType](https://learn.microsoft.com/windows/desktop/medfound/meextendedtype) | Custom event type. |
| [MEReconnectEnd](https://learn.microsoft.com/windows/desktop/medfound/mereconnectend) | The source has completed an attempt to reconnect to the server. |
| [MEReconnectStart](https://learn.microsoft.com/windows/desktop/medfound/mereconnectstart) | The source is attempting to reconnect to the server. |
| [MERendererEvent](https://learn.microsoft.com/windows/desktop/medfound/merendererevent) | Event sent by a renderer, such as the [Enhanced Video Renderer](https://learn.microsoft.com/windows/desktop/medfound/enhanced-video-renderer) (EVR). |
| [MEStreamSinkFormatChanged](https://learn.microsoft.com/windows/desktop/medfound/mestreamsinkformatchanged) | A stream format has changed. |

### `pMFMediaEvent`

Pointer to the [IMFMediaEvent](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediaevent) interface of the Media Foundation event.

### `pMediaItem`

Pointer to the [IMFPMediaItem](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaitem) interface of the current media item.

## Remarks

To get a pointer to this structure, cast the *pEventHeader* parameter of the [IMFPMediaPlayerCallback::OnMediaPlayerEvent](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayercallback-onmediaplayerevent) method. You can use the [MFP_GET_MF_EVENT](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-mfp_get_mf_event) macro for this purpose.

If **MFEventType** is [MEStreamSinkFormatChanged](https://learn.microsoft.com/windows/desktop/medfound/mestreamsinkformatchanged), the following property may be stored in the event property store, which can be accessed through the **header.pPropertyStore** member.

| Property | Description |
| --- | --- |
| [MFP_PKEY_StreamIndex](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd375565(v=vs.85)) | The index of the stream whose format changed. |

## See also

[IMFPMediaPlayerCallback](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaplayercallback)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)

[Using MFPlay for Audio/Video Playback](https://learn.microsoft.com/windows/desktop/medfound/using-mfplay-for-audio-video-playback)