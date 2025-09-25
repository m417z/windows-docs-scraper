# IMFPMediaPlayer::SetMute

## Description

\[The feature associated with this page, MFPlay, is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** and **IMFMediaEngine** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Mutes or unmutes the audio.

## Parameters

### `fMute`

Specify **TRUE** to mute the audio, or **FALSE** to unmute the audio.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If you call this method before playback starts, the setting is applied after playback starts.

This method does not mute the entire audio session to which the player belongs. It mutes only the streams from the current media item. Other streams in the audio session are not affected. For more information, see [Managing the Audio Session](https://learn.microsoft.com/windows/desktop/medfound/managing-the-audio-session).

## See also

[IMFPMediaPlayer](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaplayer)

[Using MFPlay for Audio/Video Playback](https://learn.microsoft.com/windows/desktop/medfound/using-mfplay-for-audio-video-playback)