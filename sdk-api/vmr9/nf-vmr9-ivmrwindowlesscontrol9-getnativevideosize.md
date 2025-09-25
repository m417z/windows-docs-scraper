# IVMRWindowlessControl9::GetNativeVideoSize

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetNativeVideoSize` method retrieves the un-stretched video size and aspect ratio of the video.

## Parameters

### `lpWidth` [out]

Pointer that receives the width of the native video rectangle.

### `lpHeight` [out]

Pointer that receives the height of the native video rectangle.

### `lpARWidth` [out]

Pointer that receives the aspect ratio width of the native video rectangle.

### `lpARHeight` [out]

Pointer that receives the aspect ratio height of the native video rectangle.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **VFW_E_WRONG_STATE** | The VMR is not in windowless mode. |

## Remarks

If the VMR is not connected to an upstream filter, this method will succeed but all parameters will be set to zero.

If *lpWidth* is 640 and *lpHeight* is 480, then *lpARWidth* will be 4 and *lpARHeight* will be 3.

Include DShow.h and D3d9.h before Vmr9.h.

## See also

[IVMRWindowlessControl9 Interface](https://learn.microsoft.com/previous-versions/ms787155(v=vs.85))

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)