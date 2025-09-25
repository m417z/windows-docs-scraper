# IMediaStream::SendEndOfStream

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This interface is deprecated. New applications should not use it.

Forces the current stream to end. If the current stream isn't writable, this method does nothing.

## Parameters

### `dwFlags` [in]

Reserved for flag data. Must be zero.

## Return value

Returns S_OK if successful or MS_E_INCOMPATIBLE if the existing sample isn't compatible with the current media stream.

## Remarks

Applications do not call this internal method.

## See also

[IMediaStream Interface](https://learn.microsoft.com/windows/desktop/api/mmstream/nn-mmstream-imediastream)