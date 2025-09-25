# IMixerOCX::OnDisplayChange

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `OnDisplayChange` method informs the Overlay Mixer that the monitor's display settings have changed. (Not implemented.)

## Parameters

### `ulBitsPerPixel` [in]

Specifies the new bits per pixel setting.

### `ulScreenWidth` [in]

Specifies the new screen width in pixels.

### `ulScreenHeight` [in]

Specifies the new screen height in pixels.

## Return value

Returns E_NOTIMPL.

## See also

[IMixerOCX Interface](https://learn.microsoft.com/windows/desktop/api/mixerocx/nn-mixerocx-imixerocx)

[Overlay Mixer](https://learn.microsoft.com/windows/desktop/DirectShow/overlay-mixer-filter)