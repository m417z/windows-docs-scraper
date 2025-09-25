# IVideoWindow::put_WindowStyle

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `put_WindowStyle` method sets the window styles on the video window.

## Parameters

### `WindowStyle` [in]

One or more flags from the GWL_STYLE value of the Windows **SetWindowLong** function.

## Return value

Possible return values include the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **VFW_E_NOT_CONNECTED** | The video renderer filter is not connected. |

## Remarks

This method is a thin wrapper over the **SetWindowLong** function and must be treated with care. In particular, you should retrieve the current styles and then add or remove flags. With some exceptions, flags allowed by the Windows **CreateWindow** function are acceptable. However, do not use this method to change the window size, and do not use the following flags:

* WS_DISABLED
* WS_HSCROLL
* WS_ICONIC
* WS_MAXIMIZE
* WS_MINIMIZE
* WS_VSCROLL

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVideoWindow Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-ivideowindow)

[IVideoWindow::get_WindowStyle](https://learn.microsoft.com/windows/desktop/api/control/nf-control-ivideowindow-get_windowstyle)

[IVideoWindow::put_WindowStyleEx](https://learn.microsoft.com/windows/desktop/api/control/nf-control-ivideowindow-put_windowstyleex)