# IMixerOCXNotify::OnInvalidateRect

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `OnInvalidateRect` method notifies the client that the video rectangle has been invalidated.

## Parameters

### `lpcRect` [in]

Specifies the rectangle that has been invalidated, in screen coordinates.

## Return value

If the method succeeds, it returns S_OK.

## See also

[IMixerOCX Interface](https://learn.microsoft.com/windows/desktop/api/mixerocx/nn-mixerocx-imixerocx)

[IMixerOCXNotify Interface](https://learn.microsoft.com/windows/desktop/api/mixerocx/nn-mixerocx-imixerocxnotify)