# IVideoWindow::GetWindowPosition

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetWindowPosition` method retrieves the position of the video window.

## Parameters

### `pLeft` [out]

Receives the x-coordinate, in pixels.

### `pTop` [out]

Receives the y-coordinate, in pixels.

### `pWidth` [out]

Receives the width of the window, in pixels.

### `pHeight` [out]

Receives the height of the window, in pixels.

## Return value

Possible return values include the following:

| Return code | Description |
| --- | --- |
| **E_POINTER** | **NULL** pointer. |
| **S_OK** | Success. |
| **VFW_E_NOT_CONNECTED** | The video renderer filter is not connected. |

## Remarks

This method has the same effect as calling the [IVideoWindow::get_Left](https://learn.microsoft.com/windows/desktop/api/control/nf-control-ivideowindow-get_left), [IVideoWindow::get_Top](https://learn.microsoft.com/windows/desktop/api/control/nf-control-ivideowindow-get_top), [IVideoWindow::get_Width](https://learn.microsoft.com/windows/desktop/api/control/nf-control-ivideowindow-get_width), and [IVideoWindow::get_Height](https://learn.microsoft.com/windows/desktop/api/control/nf-control-ivideowindow-get_height) methods.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVideoWindow Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-ivideowindow)

[IVideoWindow::SetWindowPosition](https://learn.microsoft.com/windows/desktop/api/control/nf-control-ivideowindow-setwindowposition)