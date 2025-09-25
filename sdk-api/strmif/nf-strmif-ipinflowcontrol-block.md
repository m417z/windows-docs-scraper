# IPinFlowControl::Block

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Block` method blocks or unblocks the flow of data from the pin.

## Parameters

### `dwBlockFlags` [in]

Flag that indicates whether to block or unblock the pin. Must be one of the following values:

* Zero: Unblock data flow from the pin.
* AM_PIN_FLOW_CONTROL_BLOCK: Block data flow from the pin.

### `hEvent` [in]

Handle to an event object, or **NULL**. If this parameter is non-**NULL**, the method is asynchronous and returns immediately. The event is signaled when the operation completes. If this parameter is **NULL**, the method is synchronous and does not complete until the pin is blocked. If *dwBlockFlags* is zero, this parameter must be **NULL**.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_FALSE** | Pin is already unblocked. |
| **S_OK** | Success. |
| **VFW_E_PIN_ALREADY_BLOCKED** | Pin is already blocked on another thread. |
| **VFW_E_PIN_ALREADY_BLOCKED_ON_THIS_THREAD** | Pin is already blocked on the calling thread. |

## Remarks

This method can be synchronous or asynchronous:

* To call it asynchronously, use the **CreateEvent** function to create an event object. Pass the event handle in the *hEvent* parameter. The method returns immediately and signals the event when the operation has completed. Call a wait function such as **WaitForSingleObject** to wait for the event.
* To call this method synchronously, set the *hEvent* parameter to **NULL**. The method blocks until it completes. The method might not complete until the pin is ready to deliver a sample. If the filter is paused, the method might block indefinitely. Therefore, you should not call this method synchronously from your main application thread.

## See also

[Dynamic Reconnection](https://learn.microsoft.com/windows/desktop/DirectShow/dynamic-reconnection)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IPinFlowControl Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipinflowcontrol)