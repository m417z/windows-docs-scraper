# ICaptureGraphBuilder::SetOutputFileName

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** The **ICaptureGraphBuilder** interface is deprecated. Use [ICaptureGraphBuilder2](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icapturegraphbuilder2) instead.

Creates the rendering section of the filter graph, which will save bits to disk with the specified file name.

## Parameters

### `pType` [in]

Pointer to a **GUID** representing the media subtype. Must be `&MEDIASUBTYPE_Avi`.

### `lpstrFile` [in]

Pointer to a wide-character string containing the output file name.

### `ppf` [out]

Address of a pointer to an [IBaseFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ibasefilter) interface representing the multiplexer filter. This method increments the reference count on the **IBaseFilter** interface so you must decrement the reference count by using the **Release** method on this parameter when done using the filter.

### `ppSink` [out]

Address of a pointer to an [IFileSinkFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifilesinkfilter) interface representing the file writer. This method increments the reference count on the IFileSinkFilter interface so you must decrement the reference count using **Release** when done using the filter.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Failure. |
| **E_INVALIDARG** | Invalid argument. Audio-Video Interleaved (AVI) is the only supported output format. |
| **E_OUTOFMEMORY** | Out of memory. |
| **E_POINTER** | **NULL** pointer argument. |
| **E_UNEXPECTED** | Unexpected error occurred. |
| **NOERROR** | Success. |
| **S_OK** | Instance of the AVI multiplexer filter was successfully created. |

## Remarks

This method inserts the multiplexer and the file writer into the filter graph and calls [IFileSinkFilter::SetFileName](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ifilesinkfilter-setfilename) to set the output file name.

You can use the *ppf* parameter returned by this method as the *pfRenderer* parameter in calls to [RenderStream](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-icapturegraphbuilder-renderstream).

You can use the *pSink* parameter from this method in a call to [SetFileName](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ifilesinkfilter-setfilename) to change the file name set by `ICaptureGraphBuilder::SetOutputFileName`.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[ICaptureGraphBuilder Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icapturegraphbuilder)