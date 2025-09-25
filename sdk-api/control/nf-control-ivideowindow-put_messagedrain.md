# IVideoWindow::put_MessageDrain

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `put_MessageDrain` method specifies a window to receive mouse and keyboard messages from the video window.

## Parameters

### `Drain` [in]

A handle to the window, as an [OAHWND](https://learn.microsoft.com/windows/desktop/DirectShow/oahwnd) value.

## Return value

Possible return values include the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **VFW_E_NOT_CONNECTED** | The video renderer filter is not connected. |

## Remarks

This method enables an application to respond to mouse and keyboard events generated within the video window.

If *Drain* is non-**NULL**, the video renderer forwards certain messages to the specified window, using the **PostMessage** function. Which messages are forwarded might depend on the video renderer in use. The [Video Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/video-renderer-filter) and Video Mixing Renderer (VMR) filters forward the following messages:

* WM_CHAR
* WM_DEADCHAR
* WM_KEYDOWN
* WM_KEYUP
* WM_LBUTTONDBLCLK
* WM_LBUTTONDOWN
* WM_LBUTTONUP
* WM_MBUTTONDBLCLK
* WM_MBUTTONDOWN
* WM_MBUTTONUP
* WM_MOUSEACTIVATE
* WM_MOUSEMOVE
* WM_NCLBUTTONDBLCLK
* WM_NCLBUTTONDOWN
* WM_NCLBUTTONUP
* WM_NCMBUTTONDBLCLK
* WM_NCMBUTTONDOWN
* WM_NCMBUTTONUP
* WM_NCMOUSEMOVE
* WM_NCRBUTTONDBLCLK
* WM_NCRBUTTONDOWN
* WM_NCRBUTTONUP
* WM_RBUTTONDBLCLK
* WM_RBUTTONDOWN
* WM_RBUTTONUP
* WM_SYSCHAR
* WM_SYSDEADCHAR
* WM_SYSKEYDOWN
* WM_SYSKEYUP

The message drain window does not need to be a parent of the video window, so full-screen applications can use this method.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVideoWindow Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-ivideowindow)

[IVideoWindow::get_MessageDrain](https://learn.microsoft.com/windows/desktop/api/control/nf-control-ivideowindow-get_messagedrain)