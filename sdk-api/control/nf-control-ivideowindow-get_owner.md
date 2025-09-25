# IVideoWindow::get_Owner

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `get_Owner` method retrieves the video window's parent window, if any.

## Parameters

### `Owner` [out]

Receives a handle to the window, as an [OAHWND](https://learn.microsoft.com/windows/desktop/DirectShow/oahwnd) type. If the video window has no parent, this parameter receives the value **NULL**.

## Return value

Possible return values include the following:

| Return code | Description |
| --- | --- |
| **E_POINTER** | **NULL** pointer. |
| **S_OK** | Success. |
| **VFW_E_NOT_CONNECTED** | The video renderer filter is not connected. |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVideoWindow Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-ivideowindow)