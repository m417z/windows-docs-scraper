# IVMRWindowlessControl::GetAspectRatioMode

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetAspectRatioMode` method queries whether the VMR will preserve the aspect ratio of the source video.

## Parameters

### `lpAspectRatioMode` [out]

Pointer to a variable that receives a [VMR_ASPECT_RATIO_MODE](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-vmr_aspect_ratio_mode) value indicating the aspect ratio mode.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

| Return code | Description |
| --- | --- |
| **E_POINTER** | **NULL** pointer argument |
| **S_OK** | Success |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVMRWindowlessControl Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrwindowlesscontrol)

[IVMRWindowlessControl::SetAspectRatioMode](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrwindowlesscontrol-setaspectratiomode)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)