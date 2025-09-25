# IVMRVideoStreamControl9::GetStreamActiveState

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetStreamActiveState` method retrieves the state of the stream.

## Parameters

### `lpfActive` [out]

Receives the current state of the stream. **TRUE** means the stream is active; **FALSE** means that it is inactive.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

Include DShow.h and D3d9.h before Vmr9.h.

## See also

[IVMRVideoStreamControl9 Interface](https://learn.microsoft.com/windows/desktop/api/vmr9/nn-vmr9-ivmrvideostreamcontrol9)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)