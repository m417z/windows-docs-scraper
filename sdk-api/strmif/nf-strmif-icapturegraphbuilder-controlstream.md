# ICaptureGraphBuilder::ControlStream

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** The **ICaptureGraphBuilder** interface is deprecated. Use [ICaptureGraphBuilder2](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icapturegraphbuilder2) instead.

Sends stream control messages to the pin of the specified category on one or more capture filters in a graph.

## Parameters

### `pCategory` [in]

Pointer to a **GUID** specifying the output pin category. See [Pin Property Set](https://learn.microsoft.com/windows/desktop/DirectShow/pin-property-set) for a list of all pin categories. This value cannot be **NULL**.

### `pFilter` [in]

Pointer to an [IBaseFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ibasefilter) interface on the filter to control. Specifying **NULL** controls all capture filters in the graph. You will get one notification for each capture filter.

### `pstart` [in]

Pointer to the start time for capture. **NULL** means start now. **MAX_TIME** means cancel previous request, or take no action if there is no previous request.

### `pstop` [in]

Pointer to the stop time for capture. **NULL** means stop now. **MAX_TIME** means cancel previous request, or take no action if there is no previous request.

### `wStartCookie` [in]

Specifies a particular value to be sent when the start occurs.

### `wStopCookie` [in]

Specifies a particular value to be sent when the stop occurs.

## Return value

Returns S_FALSE if the stop notification is sent before the last sample sent by the capture filter is rendered, otherwise returns S_OK.

If this method returns S_FALSE, the application might want to wait before stopping the filter graph to allow all samples to pass through the graph and be rendered. Otherwise, samples might be lost.

If there are no pins matching the description you provide, or if stream control cannot be supported on all of the indicated pins, this function will return a failure code.

## Remarks

Use this method for frame-accurate capture, or for individual control of capture and preview. For example, you could turn off writing of the captured image to disk if you only want to preview the captured image.

This method uses the [IAMStreamControl](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamstreamcontrol) interface on the pins.

This method sends one notification for each filter found with a pin of the specified category.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[ICaptureGraphBuilder Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icapturegraphbuilder)