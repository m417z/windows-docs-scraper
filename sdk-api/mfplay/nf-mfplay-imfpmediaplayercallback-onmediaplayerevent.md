# IMFPMediaPlayerCallback::OnMediaPlayerEvent

## Description

\[The feature associated with this page, MFPlay, is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** and **IMFMediaEngine** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Called by the MFPlay player object to notify the application of a playback event.

## Parameters

### `pEventHeader` [in]

Pointer to an [MFP_EVENT_HEADER](https://learn.microsoft.com/windows/desktop/api/mfplay/ns-mfplay-mfp_event_header) structure that contains information about the event.

## Remarks

The specific type of playback event is given in the **eEventType** member of the [MFP_EVENT_HEADER](https://learn.microsoft.com/windows/desktop/api/mfplay/ns-mfplay-mfp_event_header) structure. This structure contains information that is common to all of the event types. Some event types use extended structures. A set of macros is defined for casting the *pEventHeader* pointer to the correct structure type. For more information, see [MFP_EVENT_TYPE](https://learn.microsoft.com/windows/desktop/api/mfplay/ne-mfplay-mfp_event_type).

It is safe to call [IMFPMediaPlayer](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaplayer) and [IMFPMediaItem](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaitem) methods inside the **OnMediaPlayer** method. MFPlay is guaranteed not to reenter the **OnMediaPlayer** method. That is, calls to **OnMediaPlayer** are serialized, and the method will not be invoked again from inside **OnMediaPlayer**.

#### Examples

The following code shows how to cast the *pEventHeader* parameter to the correct structure type and pass the structure pointer to a handler function. The handler functions are declared at the start of the example. The application would need to provide implementations for these functions. Note that you do not have to handle every event. For example, if your application never calls [IMFPMediaPlayer::SetRate](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-setrate), you would not need to handle the **MFP_EVENT_TYPE_RATE_SET** event. In that case, simply omit **MFP_EVENT_TYPE_RATE_SET** from the **switch** statement.

```cpp
// Declarations of MFPlay event handler functions.

void OnPlay(MFP_PLAY_EVENT *pEvent);
void OnPause(MFP_PAUSE_EVENT *pEvent);
void OnStop(MFP_STOP_EVENT *pEvent);
void OnPositionSet(MFP_POSITION_SET_EVENT *pEvent);
void OnRateSet(MFP_RATE_SET_EVENT *pEvent);
void OnMediaItemCreated(MFP_MEDIAITEM_CREATED_EVENT *pEvent);
void OnMediaItemSet(MFP_MEDIAITEM_SET_EVENT *pEvent);
void OnFrameStep(MFP_FRAME_STEP_EVENT *pEvent);
void OnMediaItemCleared(MFP_MEDIAITEM_CLEARED_EVENT *pEvent);
void OnMFEvent(MFP_MF_EVENT *pEvent);
void OnError(MFP_ERROR_EVENT *pEvent);
void OnPlaybackEnded(MFP_PLAYBACK_ENDED_EVENT *pEvent);
void OnAquireUserCredential(MFP_ACQUIRE_USER_CREDENTIAL_EVENT *pEvent);

// Implementation of IMFPMediaPlayerCallback::OnMediaPlayerEvent
void STDMETHODCALLTYPE PlayerCallback::OnMediaPlayerEvent(MFP_EVENT_HEADER * pEventHeader)
{
    switch (pEventHeader->eEventType)
    {
    case MFP_EVENT_TYPE_PLAY:
        OnPlay(MFP_GET_PLAY_EVENT(pEventHeader));
        break;

    case MFP_EVENT_TYPE_PAUSE:
        OnPause(MFP_GET_PAUSE_EVENT(pEventHeader));
        break;

    case MFP_EVENT_TYPE_STOP:
        OnStop(MFP_GET_STOP_EVENT(pEventHeader));
        break;

    case MFP_EVENT_TYPE_POSITION_SET:
        OnPositionSet(MFP_GET_POSITION_SET_EVENT(pEventHeader));
        break;

    case MFP_EVENT_TYPE_RATE_SET:
        OnRateSet(MFP_GET_RATE_SET_EVENT(pEventHeader));
        break;

    case MFP_EVENT_TYPE_MEDIAITEM_CREATED:
        OnMediaItemCreated(MFP_GET_MEDIAITEM_CREATED_EVENT(pEventHeader));
        break;

    case MFP_EVENT_TYPE_MEDIAITEM_SET:
        OnMediaItemSet(MFP_GET_MEDIAITEM_SET_EVENT(pEventHeader));
        break;

    case MFP_EVENT_TYPE_FRAME_STEP:
        OnFrameStep(MFP_GET_FRAME_STEP_EVENT(pEventHeader));
        break;

    case MFP_EVENT_TYPE_MEDIAITEM_CLEARED:
        OnMediaItemCleared(MFP_GET_MEDIAITEM_CLEARED_EVENT(pEventHeader));
        break;

    case MFP_EVENT_TYPE_MF:
        OnMFEvent(MFP_GET_MF_EVENT(pEventHeader));
        break;

    case MFP_EVENT_TYPE_ERROR:
        OnError(MFP_GET_ERROR_EVENT(pEventHeader));
        break;

    case MFP_EVENT_TYPE_PLAYBACK_ENDED:
        OnPlaybackEnded(MFP_GET_PLAYBACK_ENDED_EVENT(pEventHeader));
        break;

    case MFP_EVENT_TYPE_ACQUIRE_USER_CREDENTIAL:
        OnAquireUserCredential(MFP_GET_ACQUIRE_USER_CREDENTIAL_EVENT(pEventHeader));
        break;
    }
}

```

## See also

[IMFPMediaPlayerCallback](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaplayercallback)

[Using MFPlay for Audio/Video Playback](https://learn.microsoft.com/windows/desktop/medfound/using-mfplay-for-audio-video-playback)