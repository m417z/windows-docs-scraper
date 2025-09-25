# IDirectDrawVideo::GetSurfaceDesc

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetSurfaceDesc` method retrieves a **DDSURFACEDESC** structure describing the current DirectDraw surface.

## Parameters

### `pSurfaceDesc`

Pointer to a **DDSURFACEDESC** structure describing the current DirectDraw surface.

## Return value

Returns an **HRESULT** value. If no surface has been allocated, this method will return E_FAIL. If a DCI primary surface is in use, the **DDSURFACEDESC** structure will not be filled in and the call will return S_FALSE.

## Remarks

Surfaces are allocated only when the renderer is paused. After the renderer has been paused, it cannot release the surfaces when stopped.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDirectDrawVideo Interface](https://learn.microsoft.com/windows/desktop/api/amvideo/nn-amvideo-idirectdrawvideo)