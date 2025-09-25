# IMediaEvent::CancelDefaultHandling

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `CancelDefaultHandling` method cancels the Filter Graph Manager's default handling for a specified event. The event notification is passed to the application.

## Parameters

### `lEvCode`

Event code for which to cancel default handling.

## Return value

Returns an **HRESULT** value. Possible values include those shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | No default handling for this event. |

## Remarks

To restore the default handling for an event, call the [IMediaEvent::RestoreDefaultHandling](https://learn.microsoft.com/windows/desktop/api/control/nf-control-imediaevent-restoredefaulthandling) method with the event code.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMediaEvent Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-imediaevent)