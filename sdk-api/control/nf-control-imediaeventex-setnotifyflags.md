# IMediaEventEx::SetNotifyFlags

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetNotifyFlags` method enables or disables event notifications.

## Parameters

### `lNoNotifyFlags` [in]

Value indicating whether to enable or disable event notifications. Must be one of the following values:

| Value | Description |
| --- | --- |
| Zero | Enable event notifications. |
| AM_MEDIAEVENT_NONOTIFY | Disable event notifications. |

## Return value

Returns S_OK if successful, or E_INVALIDARG if the *lNoNotifyFlags* parameter is invalid.

## Remarks

By default, the Filter Graph Manager posts event notifications for the application. If the *lNoNotifyFlags* parameter is AM_MEDIAEVENT_NONOTIFY, the Filter Graph Manager clears any pending event notifications from the queue, and does not post any new ones.

If event notifications are disabled, the handle returned by the [IMediaEvent::GetEventHandle](https://learn.microsoft.com/windows/desktop/api/control/nf-control-imediaevent-geteventhandle) method is signaled at the end of each stream—that is, whenever the Filter Graph Manager receives an [EC_COMPLETE](https://learn.microsoft.com/windows/desktop/DirectShow/ec-complete) event.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMediaEventEx Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-imediaeventex)