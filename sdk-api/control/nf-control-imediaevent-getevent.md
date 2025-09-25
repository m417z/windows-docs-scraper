# IMediaEvent::GetEvent

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetEvent` method retrieves the next event notification from the event queue.

## Parameters

### `lEventCode` [out]

Pointer to a variable that receives the event code.

### `lParam1` [out]

Pointer to a variable that receives the first event parameter.

### `lParam2` [out]

Pointer to a variable that receives the second event parameter.

### `msTimeout` [in]

Time-out interval, in milliseconds. Use INFINITE to block until there is an event.

## Return value

Returns an **HRESULT** value. Possible values include those shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_ABORT** | Timeout expired. |

## Remarks

If no event is on the queue, this method waits up to *msTimeout* milliseconds for an event to arrive. Avoid using a time-out interval of INFINITE, because threads cannot process any messages while waiting in `GetEvent`. If you call `GetEvent` from the same thread that processes Windows messages, specify only small wait times, in order to remain responsive to user input.

After calling `GetEvent`, call the [IMediaEvent::FreeEventParams](https://learn.microsoft.com/windows/desktop/api/control/nf-control-imediaevent-freeeventparams) method to release any resources allocated for the event parameters.

For a list of notification codes and event parameter values, see [Event Notification Codes](https://learn.microsoft.com/windows/desktop/DirectShow/event-notification-codes).

Because this method removes the event from the filter graph event queue, there is no way for multiple clients to monitor events from the same graph.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMediaEvent Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-imediaevent)

[IMediaEventEx](https://learn.microsoft.com/windows/desktop/api/control/nn-control-imediaeventex)