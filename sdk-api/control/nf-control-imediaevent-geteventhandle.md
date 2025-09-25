# IMediaEvent::GetEventHandle

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetEventHandle` method retrieves a handle to a manual-reset event that remains signaled while the queue contains event notifications.

## Parameters

### `hEvent` [out]

Pointer to a variable that receives the event handle.

## Return value

Returns S_OK.

## Remarks

The Filter Graph Manager keeps a manual-reset event that reflects the state of the event queue. If the queue contains event notifications, the manual-reset event is signaled. If the queue is empty, the [IMediaEvent::GetEvent](https://learn.microsoft.com/windows/desktop/api/control/nf-control-imediaevent-getevent) method resets the event.

An application can use this event to determine the state of the queue. First call `GetEventHandle` to obtain a handle to the event. Wait for the event to be signaled, using a function such as [WaitForSingleObject](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitforsingleobject). When the event is signaled, call the [IMediaEvent::GetEvent](https://learn.microsoft.com/windows/desktop/api/control/nf-control-imediaevent-getevent) method to retrieve the next event notification from the queue. The Filter Graph Manager keeps the event signaled until the queue is empty; then it resets the event.

Do not close the event handle returned by this method, because the event handle is used internally by the filter graph. Also, do not use the handle after you release the Filter Graph Manager, because the handle becomes invalid after the Filter Graph Manager is destroyed. (To avoid this error, it is a good idea to duplicate the handle by calling [DuplicateHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-duplicatehandle), and use the duplicate instead of the original handle. Close the duplicate handle when you are finished.)

For Automation compatibility, this method takes a pointer to an [OAEVENT](https://learn.microsoft.com/windows/desktop/DirectShow/oaevent) type. In C++, declare a variable of type **HANDLE** and cast it an **OAEVENT** pointer, as follows:

```cpp

HANDLE hEvent;
GetEventHandle( (OAEVENT*) &hEvent );

```

Another way for applications to monitor the event queue is by calling the [IMediaEventEx::SetNotifyWindow](https://learn.microsoft.com/windows/desktop/api/control/nf-control-imediaeventex-setnotifywindow) method.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMediaEvent Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-imediaevent)