# IMediaEventEx::SetNotifyWindow

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetNotifyWindow` method registers a window to process event notifications.

## Parameters

### `hwnd` [in]

Handle to the window, or **NULL** to stop receiving event messages.

### `lMsg` [in]

Window message to be passed as the notification.

### `lInstanceData` [in]

Value to be passed as the *lParam* parameter for the *lMsg* message.

## Return value

Returns S_OK if successful or E_INVALIDARG if the *hwnd* parameter is not a valid handle to a window.

## Remarks

This method designates a window that will process event notifications. Whenever the Filter Graph Manager puts an event in the event queue, it will also post a message to the designated window. The *hwnd* parameter specifies the window, and the *lMsg* parameter specifies the message. The application should define a private window message for this purpose. The message's *lParam* parameter is set to the value of **lInstanceData**, and the *wParam* parameter is set to zero.

When the window receives the message, it should call the [IMediaEvent::GetEvent](https://learn.microsoft.com/windows/desktop/api/control/nf-control-imediaevent-getevent) method to retrieve the event. Events are asynchronous, so the queue might contain several events (or none). Call **GetEvent** repeatedly, until it returns an error code.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMediaEventEx Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-imediaeventex)