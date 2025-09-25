# MFP_EVENT_TYPE enumeration

## Description

\[The feature associated with this page, MFPlay, is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** and **IMFMediaEngine** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Defines event types for the [IMFPMediaPlayerCallback](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaplayercallback) interface.

## Constants

### `MFP_EVENT_TYPE_PLAY:0`

Playback has started. This event is sent when the [IMFPMediaPlayer::Play](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-play) method completes.

### `MFP_EVENT_TYPE_PAUSE:1`

Playback has paused. This event is sent when the [IMFPMediaPlayer::Pause](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-pause) method completes.

### `MFP_EVENT_TYPE_STOP:2`

Playback has stopped. This event is sent when the [IMFPMediaPlayer::Stop](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-stop) method completes.

### `MFP_EVENT_TYPE_POSITION_SET:3`

The MFPlay player object has seeked to a new playback position. This event is sent when the [IMFPMediaPlayer::SetPosition](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-setposition) method completes.

### `MFP_EVENT_TYPE_RATE_SET:4`

The playback rate has changed. This event is sent when the [IMFPMediaPlayer::SetRate](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-setrate) method completes.

### `MFP_EVENT_TYPE_MEDIAITEM_CREATED:5`

A new media item was created. This event is sent when the [IMFPMediaPlayer::CreateMediaItemFromURL](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-createmediaitemfromurl) or [CreateMediaItemFromObject](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-createmediaitemfromobject) method completes.

### `MFP_EVENT_TYPE_MEDIAITEM_SET:6`

A media item is ready for playback. This event is sent when the [IMFPMediaPlayer::SetMediaItem](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-setmediaitem) method completes.

### `MFP_EVENT_TYPE_FRAME_STEP:7`

A frame-step operation has completed. This event is sent when the [IMFPMediaPlayer::FrameStep](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-framestep) method completes.

### `MFP_EVENT_TYPE_MEDIAITEM_CLEARED:8`

The current media item was cleared. This event is sent when the [IMFPMediaPlayer::ClearMediaItem](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-clearmediaitem) method completes.

### `MFP_EVENT_TYPE_MF:9`

A pipeline object sent an event. The player object forwards certain pipeline events to the application. For more information, see [MFP_MF_EVENT](https://learn.microsoft.com/windows/desktop/api/mfplay/ns-mfplay-mfp_mf_event).

### `MFP_EVENT_TYPE_ERROR:10`

A playback error has occurred.

### `MFP_EVENT_TYPE_PLAYBACK_ENDED:11`

Playback has ended. The player object sends this event when playback reaches the end of the media file.

### `MFP_EVENT_TYPE_ACQUIRE_USER_CREDENTIAL:12`

The media source requires authentication before it can play the file.

## Remarks

For each event type, the [IMFPMediaPlayerCallback::OnMediaPlayerEvent](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayercallback-onmediaplayerevent) callback receives a pointer to a data structure. The first part of the data structure is always an [MFP_EVENT_HEADER](https://learn.microsoft.com/windows/desktop/api/mfplay/ns-mfplay-mfp_event_header) structure. The following table lists the data structure for each event type.

In your implementation of [OnMediaPlayerEvent](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayercallback-onmediaplayerevent), you must cast the *pEventHeader* parameter to the correct structure type. A set of macros is defined for this purpose. These macros check the value of the event type and return **NULL** if there is a mismatch; otherwise they return a pointer to the correct structure type.

|  |  |
| --- | --- |
| **Event type** | **Event structure**<br><br>**Pointer cast macro** |
| MFP_EVENT_TYPE_PLAY | [MFP_PLAY_EVENT](https://learn.microsoft.com/windows/desktop/api/mfplay/ns-mfplay-mfp_play_event)<br><br>[MFP_GET_PLAY_EVENT](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-mfp_get_play_event) |
| MFP_EVENT_TYPE_PAUSE | [MFP_PAUSE_EVENT](https://learn.microsoft.com/windows/desktop/api/mfplay/ns-mfplay-mfp_pause_event)<br><br>[MFP_GET_PAUSE_EVENT](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-mfp_get_pause_event) |
| MFP_EVENT_TYPE_STOP | [MFP_STOP_EVENT](https://learn.microsoft.com/windows/desktop/api/mfplay/ns-mfplay-mfp_stop_event)<br><br>[MFP_GET_STOP_EVENT](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-mfp_get_stop_event) |
| MFP_EVENT_TYPE_POSITION_SET | [MFP_POSITION_SET_EVENT](https://learn.microsoft.com/windows/desktop/api/mfplay/ns-mfplay-mfp_position_set_event)<br><br>[MFP_GET_POSITION_SET_EVENT](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-mfp_get_position_set_event) |
| MFP_EVENT_TYPE_RATE_SET | [MFP_RATE_SET_EVENT](https://learn.microsoft.com/windows/desktop/api/mfplay/ns-mfplay-mfp_rate_set_event)<br><br>[MFP_GET_RATE_SET_EVENT](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-mfp_get_rate_set_event) |
| MFP_EVENT_TYPE_MEDIAITEM_CREATED | [MFP_MEDIAITEM_CREATED_EVENT](https://learn.microsoft.com/windows/desktop/api/mfplay/ns-mfplay-mfp_mediaitem_created_event)<br><br>[MFP_GET_MEDIAITEM_CREATED_EVENT](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-mfp_get_mediaitem_created_event) |
| MFP_EVENT_TYPE_MEDIAITEM_SET | [MFP_MEDIAITEM_SET_EVENT](https://learn.microsoft.com/windows/desktop/api/mfplay/ns-mfplay-mfp_mediaitem_set_event)<br><br>[MFP_GET_MEDIAITEM_SET_EVENT](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-mfp_get_mediaitem_set_event) |
| MFP_EVENT_TYPE_FRAME_STEP | [MFP_FRAME_STEP_EVENT](https://learn.microsoft.com/windows/desktop/api/mfplay/ns-mfplay-mfp_frame_step_event)<br><br>[MFP_GET_FRAME_STEP_EVENT](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-mfp_get_frame_step_event) |
| MFP_EVENT_TYPE_MEDIAITEM_CLEARED | [MFP_MEDIAITEM_CLEARED_EVENT](https://learn.microsoft.com/windows/desktop/api/mfplay/ns-mfplay-mfp_mediaitem_cleared_event)<br><br>[MFP_GET_MEDIAITEM_CLEARED_EVENT](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-mfp_get_mediaitem_cleared_event) |
| MFP_EVENT_TYPE_MF | [MFP_MF_EVENT](https://learn.microsoft.com/windows/desktop/api/mfplay/ns-mfplay-mfp_mf_event)<br><br>[MFP_GET_MF_EVENT](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-mfp_get_mf_event) |
| MFP_EVENT_TYPE_ERROR | [MFP_ERROR_EVENT](https://learn.microsoft.com/windows/desktop/api/mfplay/ns-mfplay-mfp_error_event)<br><br>[MFP_GET_ERROR_EVENT](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-mfp_get_error_event) |
| MFP_EVENT_TYPE_PLAYBACK_ENDED | [MFP_PLAYBACK_ENDED_EVENT](https://learn.microsoft.com/windows/desktop/api/mfplay/ns-mfplay-mfp_playback_ended_event)<br><br>[MFP_GET_PLAYBACK_ENDED_EVENT](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-mfp_get_playback_ended_event) |
| MFP_EVENT_TYPE_ACQUIRE_USER_CREDENTIAL | [MFP_ACQUIRE_USER_CREDENTIAL_EVENT](https://learn.microsoft.com/windows/desktop/api/mfplay/ns-mfplay-mfp_acquire_user_credential_event)<br><br>[MFP_GET_ACQUIRE_USER_CREDENTIAL_EVENT](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-mfp_get_acquire_user_credential_event) |

## See also

[IMFPMediaPlayerCallback](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaplayercallback)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)