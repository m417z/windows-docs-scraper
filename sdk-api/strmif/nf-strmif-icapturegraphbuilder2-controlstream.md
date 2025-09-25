# ICaptureGraphBuilder2::ControlStream

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `ControlStream` method sets the start and stop times for one or more streams of captured data.

## Parameters

### `pCategory` [in]

A pointer to a GUID that specifies one of the pin categories listed in [Pin Property Set](https://learn.microsoft.com/windows/desktop/DirectShow/pin-property-set). The value of this parameter cannot be **NULL**.

### `pType` [in]

Pointer to a major type GUID that specifies the media type, or **NULL**. If this parameter is **NULL**, set the *pFilter* parameter to **NULL** as well. Otherwise, you might control the wrong pin and get unpredictable results.

### `pFilter` [in]

Pointer to an [IBaseFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ibasefilter) interface that specifies which filter to control. To control all the capture filters in the graph, set this parameter to **NULL**.

### `pstart` [in]

Pointer to a variable that contains the start time. If the value is **MAXLONGLONG** (0x7FFFFFFFFFFFFFFF), the method cancels the previous start request. If the value is **NULL**, the pin starts immediately when the graph runs.

### `pstop` [in]

Pointer to a variable that contains the stop time. If the value is **MAXLONGLONG**, the method cancels any previous stop request. If the value is **NULL**, the pin stops immediately.

### `wStartCookie` [in]

Value that is sent as the second parameter of the [EC_STREAM_CONTROL_STARTED](https://learn.microsoft.com/windows/desktop/DirectShow/ec-stream-control-started) event notification. See Remarks for more information.

### `wStopCookie` [in]

Value that is sent as the second parameter of the [EC_STREAM_CONTROL_STOPPED](https://learn.microsoft.com/windows/desktop/DirectShow/ec-stream-control-stopped) event notification. See Remarks for more information.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_FALSE** | At least one downstream renderer will not send a stop notification. |
| **S_OK** | Success. |
| **E_FAIL** | Could not find a matching pin, or the pin did not support stream control. |
| **E_POINTER** | **NULL** pointer argument. |

## Remarks

This method locates output pins on capture filters, using search criteria that you supply in the method call. Then it calls the [IAMStreamControl](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamstreamcontrol) methods on those pins. This method enables an application to control streams without the application needing to enumerate the filters and pins in the graph.

Use this method for frame-accurate capture, or for individual control of capture and preview. For example, you can stop capturing to disk but leave video preview running.

The first three parameters specify which pins to control. A capture graph can have more than one capture filter. For example, it might have filters for video, audio, and closed captioning data. Also, a capture filter can have more than one output pin. Some capture filters have separate pins for preview and capture, or separate pins for video-only data and audio-video interleaved data. To control video preview, for example, specify PIN_CATEGORY_PREVIEW for *pCategory* and MEDIATYPE_Video for *pType*.

**Note**

If the pin category is PIN_CATEGORY_PREVIEW, you cannot set specific start and stop times, because the samples delivered by a preview pin have no time stamps (see [Time Stamps](https://learn.microsoft.com/windows/desktop/DirectShow/time-stamps)). Instead, use the values **NULL** and **MAXLONGLONG** to start and stop the pin at the desired times.

Also, this method is not supported for preview if the device uses a video port pin, because in that case the device is delivering the preview samples directly over hardware.

To control a pin, this method calls the [IAMStreamControl::StartAt](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamstreamcontrol-startat) and [IAMStreamControl::StopAt](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamstreamcontrol-stopat) methods. Each pin sends an [EC_STREAM_CONTROL_STARTED](https://learn.microsoft.com/windows/desktop/DirectShow/ec-stream-control-started) event notification when it starts. The second parameter of the event notification is the value given in *wStartCookie*. When the pin stops, it sends an [EC_STREAM_CONTROL_STOPPED](https://learn.microsoft.com/windows/desktop/DirectShow/ec-stream-control-stopped) event notification. The second parameter of that event notification is the value given in *wStopCookie*.

When this method locates a matching pin, it searches downstream for another filter that supports [IAMStreamControl](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamstreamcontrol) (typically a multiplexer). If it finds one, it also sets the start and stop times on that filter. This generates two pairs of stop notifications: one for the capture filter, and one for the downstream filter. Only the stop notification from the downstream filter uses the *wStopCookie* parameter. Waiting for this event guarantees that the downstream filter receives the last sample.

If no downstream filter supports **IAMStreamControl**, the method returns S_FALSE. In that case, you might receive the stop notification before the last sample is rendered.

**MAXLONGLONG** is the largest possible [REFERENCE_TIME](https://learn.microsoft.com/windows/desktop/DirectShow/reference-time) value. In the DirectShow base class library, it is also defined as the constant **MAX_TIME**.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[ICaptureGraphBuilder2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icapturegraphbuilder2)