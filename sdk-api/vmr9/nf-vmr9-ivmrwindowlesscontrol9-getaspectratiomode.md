# IVMRWindowlessControl9::GetAspectRatioMode

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetAspectRatioMode` method retrieves the current aspect ratio display mode.

## Parameters

### `lpAspectRatioMode` [out]

Pointer to a DWORD that receives a [VMR9AspectRatioMode](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/ne-vmr9-vmr9aspectratiomode) value that indicates the current aspect ratio mode.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *lpAspectRatioMode* is invalid |

## Remarks

Include DShow.h and D3d9.h before Vmr9.h.

## See also

[IVMRWindowlessControl9 Interface](https://learn.microsoft.com/previous-versions/ms787155(v=vs.85))

[SetAspectRatioMode](https://learn.microsoft.com/windows/desktop/api/vmr9/nf-vmr9-ivmrwindowlesscontrol9-setaspectratiomode)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)