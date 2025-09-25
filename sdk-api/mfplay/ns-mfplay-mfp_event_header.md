# MFP_EVENT_HEADER structure

## Description

\[The feature associated with this page, MFPlay, is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** and **IMFMediaEngine** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Contains information that is common to every type of MFPlay event.

## Members

### `eEventType`

The type of event, specified as a member of the [MFP_EVENT_TYPE](https://learn.microsoft.com/windows/desktop/api/mfplay/ne-mfplay-mfp_event_type) enumeration.

### `hrEvent`

Error or success code for the operation that caused the event.

### `pMediaPlayer`

Pointer to the [IMFPMediaPlayer](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaplayer) interface of the MFPlay player object that sent the event.

### `eState`

The new state of the MFPlay player object, specified as a member of the [MFP_MEDIAPLAYER_STATE](https://learn.microsoft.com/windows/desktop/api/mfplay/ne-mfplay-mfp_mediaplayer_state) enumeration.

### `pPropertyStore`

A pointer to the **IPropertyStore** interface of a property store object. The property store is used to hold additional event data for some event types. This member might be **NULL**.

## See also

[IMFPMediaPlayerCallback](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaplayercallback)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)

[Using MFPlay for Audio/Video Playback](https://learn.microsoft.com/windows/desktop/medfound/using-mfplay-for-audio-video-playback)