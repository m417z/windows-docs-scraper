# IVideoWindow::SetWindowPosition

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetWindowPosition` method sets the position of the video window.

## Parameters

### `Left` [in]

The x-coordinate, in pixels.

### `Top` [in]

The y-coordinate, in pixels.

### `Width` [in]

The width, in pixels.

### `Height` [in]

The height, in pixels.

## Return value

Possible return values include the following:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **S_OK** | Success. |
| **VFW_E_NOT_CONNECTED** | The video renderer filter is not connected. |

## Remarks

This method has the same effect as calling the [IVideoWindow::put_Left](https://learn.microsoft.com/windows/desktop/api/control/nf-control-ivideowindow-put_left), [IVideoWindow::put_Top](https://learn.microsoft.com/windows/desktop/api/control/nf-control-ivideowindow-put_top), [IVideoWindow::put_Width](https://learn.microsoft.com/windows/desktop/api/control/nf-control-ivideowindow-put_width), and [IVideoWindow::put_Height](https://learn.microsoft.com/windows/desktop/api/control/nf-control-ivideowindow-put_height) methods.

If resizing the window to the specified dimensions is impossible, this method modifies the window's size and location to make the window fit. Call the [IVideoWindow::GetWindowPosition](https://learn.microsoft.com/windows/desktop/api/control/nf-control-ivideowindow-getwindowposition) method to determine the result.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVideoWindow Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-ivideowindow)