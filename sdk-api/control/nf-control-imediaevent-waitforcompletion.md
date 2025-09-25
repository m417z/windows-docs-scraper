# IMediaEvent::WaitForCompletion

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `WaitForCompletion` method waits for the filter graph to render all available data. The filter graph must be running or the method fails.

## Parameters

### `msTimeout` [in]

Time-out interval, in milliseconds. Pass zero to return immediately. Pass the value INFINITE to block indefinitely.

### `pEvCode` [out]

Pointer to a variable that receives an event code. See Remarks for more information.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_ABORT** | Time-out expired. |
| **VFW_E_WRONG_STATE** | The filter graph is not running. |

## Remarks

This method blocks until the time-out expires, or one of the following events occurs:

* [EC_COMPLETE](https://learn.microsoft.com/windows/desktop/DirectShow/ec-complete)
* [EC_ERRORABORT](https://learn.microsoft.com/windows/desktop/DirectShow/ec-errorabort)
* [EC_USERABORT](https://learn.microsoft.com/windows/desktop/DirectShow/ec-userabort)

During the wait, the method discards all other event notifications.

If the return value is S_OK, the *pEvCode* parameter receives the event code that ended the wait. When the method returns, the filter graph is still running. The application can pause or stop the graph, as appropriate.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMediaEvent Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-imediaevent)