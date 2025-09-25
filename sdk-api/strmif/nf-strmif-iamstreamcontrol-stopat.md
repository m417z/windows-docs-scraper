# IAMStreamControl::StopAt

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `StopAt` method informs the pin when to stop delivering data.

## Parameters

### `ptStop` [in]

Pointer to a [REFERENCE_TIME](https://learn.microsoft.com/windows/desktop/DirectShow/reference-time) value that specifies when the pin should stop delivering data. If the value is **MAXLONGLONG** (0x7FFFFFFFFFFFFFFF), the method cancels any previous stop request. If *psStop* is **NULL**, the pin stops immediately.

For preview pins, only the values **NULL** and **MAXLONGLONG** are valid, because preview pins do not time stamp the samples they deliver.

### `bSendExtra` [in]

Specifies a Boolean value that indicates whether to send an extra sample after the scheduled stop time. If **TRUE**, the pin sends one extra sample.

### `dwCookie` [in]

Specifies a value to send along with the start notification. See Remarks.

## Return value

If the method succeeds, the return value is S_OK. Otherwise, returns an **HRESULT** value indicating the cause of the failure.

## Remarks

If the *dwCookie* parameter is non-zero, the pin will send an [EC_STREAM_CONTROL_STOPPED](https://learn.microsoft.com/windows/desktop/DirectShow/ec-stream-control-stopped) event when it stops delivering data. The first event parameter is a pointer to the pin's [IPin](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipin) interface, and the second is the value of *dwCookie*. If *ptStop* is **NULL** or **MAXLONGLONG**, no event is sent, and the value of *dwCookie* is ignored.

In video capture, you would typically call this method on the capture filter's output pin and the multiplexer's input pin. The application should wait for the stop event from the multiplexer. This ensures that the capture filter sends the right number of frames, while guaranteeing that all frames reach the multiplexer. Also, set the *bSendExtra* parameter to **TRUE** for the capture pin, but **FALSE** for the multiplexer pin. This causes the capture filter to send one additional frame. The multiplexer relies on the time stamps from the capture pin, so if the extra frame is not sent, the multiplexer will wait indefinitely for the stop time. When the multiplexer receives the extra frame, it will discard it.

This method handles the following boundary conditions:

* If the stop time falls between the start and stop times of a sample, the pin delivers that sample.
* If the start time equals the stop time, the pin delivers one sample.

**MAXLONGLONG** is the largest possible [REFERENCE_TIME](https://learn.microsoft.com/windows/desktop/DirectShow/reference-time) value. In the base class library, it is also defined as the constant **MAX_TIME**.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMStreamControl Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamstreamcontrol)