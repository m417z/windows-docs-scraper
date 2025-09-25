# MFP_MEDIAPLAYER_STATE enumeration

## Description

\[The feature associated with this page, MFPlay, is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** and **IMFMediaEngine** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies the current playback state.

## Constants

### `MFP_MEDIAPLAYER_STATE_EMPTY:0`

Initial state. No media items have been set on the player object.

### `MFP_MEDIAPLAYER_STATE_STOPPED:0x1`

Playback is stopped.

### `MFP_MEDIAPLAYER_STATE_PLAYING:0x2`

Playback is in progress.

### `MFP_MEDIAPLAYER_STATE_PAUSED:0x3`

Playback is paused.

### `MFP_MEDIAPLAYER_STATE_SHUTDOWN:0x4`

The player object was shut down. This state is returned after the application calls [IMFPMediaPlayer::Shutdown](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-shutdown).

## See also

[IMFPMediaPlayer::GetState](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-getstate)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)