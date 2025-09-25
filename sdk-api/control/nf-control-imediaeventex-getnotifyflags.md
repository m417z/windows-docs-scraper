# IMediaEventEx::GetNotifyFlags

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetNotifyFlags` method determines whether event notifications are enabled.

## Parameters

### `lplNoNotifyFlags` [out]

Pointer to a variable that receives one of the following values:

| Value | Description |
| --- | --- |
| Zero | Event notifications are enabled. |
| AM_MEDIAEVENT_NONOTIFY | Event notifications are disabled. |

## Return value

Returns S_OK if successful, or E_POINTER if the *lplNoNotifyFlags* parameter is **NULL**.

## Remarks

By default, the Filter Graph Manager posts event notifications for the application. To disable event notification, call the [IMediaEventEx::SetNotifyFlags](https://learn.microsoft.com/windows/desktop/api/control/nf-control-imediaeventex-setnotifyflags) method with the value AM_MEDIAEVENT_NONOTIFY.

If event notifications are disabled, the handle returned by the [IMediaEvent::GetEventHandle](https://learn.microsoft.com/windows/desktop/api/control/nf-control-imediaevent-geteventhandle) method is signaled at the end of each stream—that is, whenever the Filter Graph Manager receives an [EC_COMPLETE](https://learn.microsoft.com/windows/desktop/DirectShow/ec-complete) event.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMediaEventEx Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-imediaeventex)