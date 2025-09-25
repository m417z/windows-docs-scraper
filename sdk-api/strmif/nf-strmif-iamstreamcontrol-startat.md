# IAMStreamControl::StartAt

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `StartAt` method informs the pin when to start delivering data.

## Parameters

### `ptStart` [in]

Pointer to a [REFERENCE_TIME](https://learn.microsoft.com/windows/desktop/DirectShow/reference-time) value that specifies when the pin should start delivering data. If the value is **MAXLONGLONG** (0x7FFFFFFFFFFFFFFF), the method cancels the previous start request. If *psStart* is **NULL**, the pin starts immediately when the graph runs.

For preview pins, only the values **NULL** and **MAXLONGLONG** are valid, because preview pins do not time stamp the samples they deliver.

### `dwCookie` [in]

Specifies a value to send along with the start notification. See Remarks.

## Return value

If the method succeeds, the return value is S_OK. Otherwise, returns an **HRESULT** value indicating the cause of the failure.

## Remarks

By default, the pin delivers data as soon as the filter graph runs. The `StartAt` method causes the pin to wait until a specified time after the graph runs, before the pin begins delivering data.

If the *dwCookie* parameter is non-zero, the pin will send an [EC_STREAM_CONTROL_STARTED](https://learn.microsoft.com/windows/desktop/DirectShow/ec-stream-control-started) event when it starts to deliver data. The first event parameter is a pointer to the pin's [IPin](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipin) interface, and the second is the value of *dwCookie*.

This method implements the following special cases:

* If *ptStart* is **NULL**, the pin starts as soon as the graph runs. No event is sent, and the value of *dwCookie* is ignored.
* If *ptStart* contains the value **MAXLONGLONG**, and there is a pending stop request, the pin starts when the graph runs. If there is no pending stop request, the pin remains stopped. In either case, no start event is sent, and the value of *dwCookie* is ignored.

This method also handles the following boundary conditions:

* If the start time falls between the start and stop times of a sample, the pin delivers that sample.
* If the start time equals the stop time, the pin delivers one sample.

**MAXLONGLONG** is the largest possible **REFERENCE_TIME** value. In the base class library, it is also defined as the constant **MAX_TIME**.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMStreamControl Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamstreamcontrol)