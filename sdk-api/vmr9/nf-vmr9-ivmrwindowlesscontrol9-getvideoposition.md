# IVMRWindowlessControl9::GetVideoPosition

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetVideoPosition` method retrieves the current source and destination rectangles used to display the video.

## Parameters

### `lpSRCRect` [out]

Pointer that receives the current source rectangle.

### `lpDSTRect` [out]

Pointer that receives the current destination rectangle.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **VFW_E_WRONG_STATE** | The VMR is not in windowless mode. |

## Remarks

Include DShow.h and D3d9.h before Vmr9.h.

## See also

[IVMRWindowlessControl9 Interface](https://learn.microsoft.com/previous-versions/ms787155(v=vs.85))

[SetVideoPosition](https://learn.microsoft.com/windows/desktop/api/vmr9/nf-vmr9-ivmrwindowlesscontrol9-setvideoposition)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)