# ICaptureGraphBuilder2::SetOutputFileName

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetOutputFileName` method creates the file writing section of the filter graph.

## Parameters

### `pType` [in]

Pointer to a **GUID** that represents either the media subtype of the output or the class identifier (CLSID) of a multiplexer filter or file writer filter. If you specify a media subtype, it must be one of the following:

| Value | Description |
| --- | --- |
| MEDIASUBTYPE_Avi | Audio-Video Interleaved (AVI) |
| MEDIASUBTYPE_Asf | Advanced Systems Format (ASF) |

### `lpstrFile` [in]

Pointer to a wide-character string that contains the output file name.

### `ppf` [out]

Address of a pointer that receives the multiplexer's [IBaseFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ibasefilter) interface.

### `ppSink` [out]

Address of a pointer that receives the file writer's [IFileSinkFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifilesinkfilter) interface. Can be **NULL**.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_FAIL** | Failure. |
| **E_POINTER** | **NULL** pointer argument. |

## Remarks

This method creates a multiplexer filter based on the value of the *pType* parameter. For AVI, it creates the [AVI Mux Filter](https://learn.microsoft.com/windows/desktop/DirectShow/avi-mux-filter). For ASF, it creates the [WM ASF Writer](https://learn.microsoft.com/windows/desktop/DirectShow/wm-asf-writer-filter). For other values, it creates the filter identified by the CLSID. It adds the multiplexer to the filter graph, and returns a pointer to its **IBaseFilter** interface in the *ppf* parameter.

If the multiplexer supports the **IFileSinkFilter** interface, the method calls [IFileSinkFilter::SetFileName](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ifilesinkfilter-setfilename) to set the output file name, using the value given in the *lpwstrFile* parameter. If the multiplexer does not support **IFileSinkFilter** interface, the method adds the [File Writer Filter](https://learn.microsoft.com/windows/desktop/DirectShow/file-writer-filter) to the filter graph, connects the multiplexer to the file writer, and uses the file writer's **IFileSinkFilter** interface to call **SetFileName**. If the *pSink* parameter is not **NULL**, it receives a pointer to the **IFileSinkFilter** interface.

You can use the pointer to the multiplexer filter, returned in the *ppf* parameter, as the *pSink* parameter in the [ICaptureGraphBuilder2::RenderStream](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-icapturegraphbuilder2-renderstream) method.

For custom multiplexer filters, the method fails if the filter does not support a connection on its output pin before its input pins are connected. For example, the [WavDest Filter Sample](https://learn.microsoft.com/windows/desktop/DirectShow/wavdest-filter-sample) included with the SDK has this limitation.

If the method succeeds, the **IBaseFilter** interface returned in the *ppf* parameter has an outstanding reference count. If the method succeeds and *pSink* is not **NULL**, the **IFileSinkFilter** interface also has an outstanding reference count. Be sure to release both interfaces when you are done using them.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[ICaptureGraphBuilder2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icapturegraphbuilder2)