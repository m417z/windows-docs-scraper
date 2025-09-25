# MFP_POSITION_SET_EVENT structure

## Description

\[The feature associated with this page, MFPlay, is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** and **IMFMediaEngine** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Event structure for the **MFP_EVENT_TYPE_POSITION_SET** event. This event is sent when the [IMFPMediaPlayer::SetPosition](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-setposition) method completes.

## Members

### `header`

[MFP_EVENT_HEADER](https://learn.microsoft.com/windows/desktop/api/mfplay/ns-mfplay-mfp_event_header) structure that contains data common to all [IMFPMediaPlayer](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaplayer) events.

### `pMediaItem`

Pointer to the [IMFPMediaItem](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaitem) interface of the current media item.

## Remarks

To get a pointer to this structure, cast the *pEventHeader* parameter of the [IMFPMediaPlayerCallback::OnMediaPlayerEvent](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayercallback-onmediaplayerevent) method. You can use the [MFP_GET_POSITION_SET_EVENT](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-mfp_get_position_set_event) macro for this purpose.

## See also

[IMFPMediaPlayerCallback](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaplayercallback)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)

[Using MFPlay for Audio/Video Playback](https://learn.microsoft.com/windows/desktop/medfound/using-mfplay-for-audio-video-playback)