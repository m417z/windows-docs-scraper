# IVideoWindow::get_FullScreenMode

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `get_FullScreenMode` method queries whether the video renderer is in full-screen mode.

## Parameters

### `FullScreenMode` [out]

Receives the value OATRUE if the video renderer is in full-screen mode, or OAFALSE otherwise.

## Return value

Possible return values include the following:

| Return code | Description |
| --- | --- |
| **E_NOTIMPL** | This filter does not support full-screen mode. |
| **E_POINTER** | **NULL** pointer. |
| **S_OK** | Success. |
| **VFW_E_NOT_CONNECTED** | The video renderer filter is not connected. |

## Remarks

When the Filter Graph Manager is switching to full-screen mode, it calls this method to determine whether the current video renderer supports this mode. If the renderer does not have inherent support for full-screen playback, it should return E_NOTIMPL. If it does, it should return S_OK, and also return the correct value in the *FullScreenMode* parameter.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVideoWindow Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-ivideowindow)

[IVideoWindow::put_FullScreenMode](https://learn.microsoft.com/windows/desktop/api/control/nf-control-ivideowindow-put_fullscreenmode)