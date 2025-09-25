# IMixerOCXNotify::OnStatusChange

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `OnStatusChange` method informs the client that a status change has occurred.

## Parameters

### `ulStatusFlags` [in]

Bitwise OR of one or more of the following status flags.

| Flag | Description |
| --- | --- |
| MIXER_STATE_UNCONNECTED (0x00000000) | The Overlay Mixer is unconnected and stopped. |
| MIXER_STATE_CONNECTED_STOPPED (0x00000001) | The Overlay Mixer is connected and stopped. |
| MIXER_STATE_CONNECTED_PAUSED (0x00000002) | The Overlay Mixer is connected and paused. |
| MIXER_STATE_CONNECTED_PLAYING (0x00000003) | The Overlay Mixer is connected and playing. |

## Return value

If the method succeeds, it returns S_OK.

## See also

[IMixerOCX Interface](https://learn.microsoft.com/windows/desktop/api/mixerocx/nn-mixerocx-imixerocx)

[IMixerOCXNotify Interface](https://learn.microsoft.com/windows/desktop/api/mixerocx/nn-mixerocx-imixerocxnotify)

[Overlay Mixer](https://learn.microsoft.com/windows/desktop/DirectShow/overlay-mixer-filter)