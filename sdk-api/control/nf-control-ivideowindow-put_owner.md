# IVideoWindow::put_Owner

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `put_Owner` method specifies a parent window for the video window.

## Parameters

### `Owner` [in]

A handle to the parent window, as an [OAHWND](https://learn.microsoft.com/windows/desktop/DirectShow/oahwnd) value, or **NULL** to remove the existing parent.

## Return value

Possible return values include the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **VFW_E_NOT_CONNECTED** | The video renderer filter is not connected. |

## Remarks

Use this method to display videos in a compound document. This method changes the parent of the video window and sets the WS_CHILD style for the video window.

Reset the owner to **NULL** before releasing the Filter Graph Manager. Otherwise, messages will continue to be sent to this window and errors will likely occur when the application is terminated.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVideoWindow Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-ivideowindow)

[IVideoWindow::get_Owner](https://learn.microsoft.com/windows/desktop/api/control/nf-control-ivideowindow-get_owner)