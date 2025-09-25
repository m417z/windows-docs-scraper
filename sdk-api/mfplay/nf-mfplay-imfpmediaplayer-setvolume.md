# IMFPMediaPlayer::SetVolume

## Description

\[The feature associated with this page, MFPlay, is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** and **IMFMediaEngine** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Sets the audio volume.

## Parameters

### `flVolume` [in]

The volume level. Volume is expressed as an attenuation level, where 0.0 indicates silence and 1.0 indicates full volume (no attenuation).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_OUT_OF_RANGE** | The *flVolume* parameter is invalid. |

## Remarks

If you call this method before playback starts, the setting is applied after playback starts.

This method does not change the master volume level for the player's audio session. Instead, it adjusts the per-channel volume levels for audio stream(s) that belong to the current media item. Other streams in the audio session are not affected. For more information, see [Managing the Audio Session](https://learn.microsoft.com/windows/desktop/medfound/managing-the-audio-session).

## See also

[IMFPMediaPlayer](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaplayer)

[Using MFPlay for Audio/Video Playback](https://learn.microsoft.com/windows/desktop/medfound/using-mfplay-for-audio-video-playback)