# IFullScreenVideoEx::GetMessageDrain

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetMessageDrain` method retrieves the window that receives mouse and keyboard messages, if any.

## Parameters

### `hwnd` [out]

Pointer to a variable that receives the handle of the window. If no window has been designated to receive messages, this parameter receives the value **NULL**.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_POINTER** | **NULL** pointer argument. |
| **S_OK** | Success. |

## Remarks

This method is equivalent to the [IVideoWindow::get_MessageDrain](https://learn.microsoft.com/windows/desktop/api/control/nf-control-ivideowindow-get_messagedrain) method.

The Full Screen video renderer posts all mouse and keyboard messages to the window designated as a message drain. The exact list of messages that are posted is the same as the list given in [IVideoWindow::put_MessageDrain](https://learn.microsoft.com/windows/desktop/api/control/nf-control-ivideowindow-put_messagedrain).

Applications do not need to use this method. Use the [IVideoWindow::get_MessageDrain](https://learn.microsoft.com/windows/desktop/api/control/nf-control-ivideowindow-get_messagedrain) method on the Filter Graph Manager instead.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IFullScreenVideoEx Interface](https://learn.microsoft.com/windows/desktop/api/amvideo/nn-amvideo-ifullscreenvideoex)