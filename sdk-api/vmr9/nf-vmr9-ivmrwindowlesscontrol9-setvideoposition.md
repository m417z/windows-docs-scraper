# IVMRWindowlessControl9::SetVideoPosition

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetVideoPosition` method sets the source and destination rectangles for the video.

## Parameters

### `lpSRCRect` [in]

Pointer to a **RECT** structure that specifies the source rectangle. If **NULL**, the source rectangle does not change. The default source rectangle is the entire video image.

### `lpDSTRect` [in]

Pointer to a **RECT** structure that specifies the destination rectangle. If **NULL**, the destination rectangle does not change. The default destination rectangle is {0, 0, 0, 0}.

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

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)