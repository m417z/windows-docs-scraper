# MFP_MEDIAITEM_SET_EVENT structure

## Description

\[The feature associated with this page, MFPlay, is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** and **IMFMediaEngine** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Event structure for the **MFP_EVENT_TYPE_MEDIAITEM_SET** event. This event is sent when the [IMFPMediaPlayer::SetMediaItem](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-setmediaitem) method completes.

## Members

### `header`

[MFP_EVENT_HEADER](https://learn.microsoft.com/windows/desktop/api/mfplay/ns-mfplay-mfp_event_header) structure that contains data common to all [IMFPMediaPlayer](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaplayer) events.

### `pMediaItem`

A pointer to the [IMFPMediaItem](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaitem) interface of the media item that was queued for playback.

## Remarks

To get a pointer to this structure, cast the *pEventHeader* parameter of the [IMFPMediaPlayerCallback::OnMediaPlayerEvent](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayercallback-onmediaplayerevent) method. You can use the [MFP_GET_MEDIAITEM_SET_EVENT](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-mfp_get_mediaitem_set_event) macro for this purpose.

If one or more streams could not be connected to a media sink, the event property store contains the [MFP_PKEY_StreamRenderingResults](https://learn.microsoft.com/windows/desktop/medfound/mfp-pkey-streamrenderingresults) property. The value of the property is an array of **HRESULT** values, indicating which streams were connected successfully. The event property store can be accessed through the **header.pPropertyStore** member.

## See also

[IMFPMediaPlayerCallback](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaplayercallback)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)

[Using MFPlay for Audio/Video Playback](https://learn.microsoft.com/windows/desktop/medfound/using-mfplay-for-audio-video-playback)