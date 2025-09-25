# ICaptureGraphBuilder2::RenderStream

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `RenderStream` method connects an output pin on a source filter to a sink filter, optionally through an intermediate filter.

## Parameters

### `pCategory` [in]

A pointer to a GUID that specifies one of the pin categories listed in [Pin Property Set](https://learn.microsoft.com/windows/desktop/DirectShow/pin-property-set). To match any pin, regardless of category, set this parameter to **NULL**. Typical values include the following.

* PIN_CATEGORY_CAPTURE
* PIN_CATEGORY_PREVIEW
* PIN_CATEGORY_CC

### `pType` [in]

Pointer to a major-type GUID that specifies the media type of the output pin; or **NULL** to use any pin, regardless of media type. For a list of possible values, see [Major Types](https://learn.microsoft.com/windows/desktop/DirectShow/major-types).

### `pSource` [in]

Specifies a pointer to the starting filter for the connection, or to an output pin.

### `pfCompressor` [in]

Pointer to the [IBaseFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ibasefilter) interface of an intermediate filter, such as a compression filter. Can be **NULL**.

### `pfRenderer` [in]

Pointer to the **IBaseFilter** interface of a sink filter, such as a renderer or mux filter. If the value is **NULL**, the method uses a default renderer (see Remarks).

## Return value

Returns an **HRESULT** value. Possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **VFW_S_NOPREVIEWPIN** | Preview was rendered through the [Smart Tee Filter](https://learn.microsoft.com/windows/desktop/DirectShow/smart-tee-filter). |
| **E_FAIL** | Failure. |
| **E_INVALIDARG** | Invalid argument. |
| **E_POINTER** | **NULL** pointer argument. |
| **VFW_E_NOT_IN_GRAPH** | A filter is not in the filter graph. This error can occur if you did not call **AddFilter** to add *pSource*, *pIntermediate*, or *pSink* to the graph. It can also occur if you did not call **SetFiltergraph** to connect your graph to the Capture Graph Builder; in this case, the Capture Graph Builder object automatically creates its own filter graph. See [About the Capture Graph Builder](https://learn.microsoft.com/windows/desktop/DirectShow/about-the-capture-graph-builder). |

## Remarks

This method renders a stream by connecting two or more filters together in a chain:

* The *pSource* parameter specifies the start of the chain, either a filter or an output pin.
* The *pIntermediate* parameter specifies an intermediate filter, typically a compression filter. This parameter can be **NULL**.
* The *pSink* parameter specifies the filter at the end of the chain. Typically, this filter is either a renderer for preview, or a mux for file capture.

The method connects *pSource* to *pIntermediate*, and then connects *pIntermediate* to *pSink*. If *pIntermediate* is **NULL**, the method just connects *pSource* to *pSink*. All of the filters specified by *pSource*, *pIntermediate*, and *pSink* must be added to the graph prior to calling the method. The method uses [Intelligent Connect](https://learn.microsoft.com/windows/desktop/DirectShow/intelligent-connect), so additional filters such as decoders might be added to the graph.

If the *pSink* parameter is **NULL**, the method tries to use a default renderer. For video it uses the [Video Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/video-renderer-filter), and for audio it uses the [DirectSound Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/directsound-renderer-filter).

If *pSource* is a filter, the method searches for an output pin on that filter. In that case, use the *pCategory* and *pType* parameters to narrow the search. For example, if a filter has separate pins for preview and capture, you can specify either PIN_CATEGORY_CAPTURE or PIN_CATEGORY_PREVIEW. If *pSource* is an output pin, set the *pCategory* and *pType* to **NULL**.

In all cases, the method searches for unconnected pins. If more than one pin meets the specified criteria, the method uses the first such pin that it finds.

Note that for DV capture, if the media type is MEDIATYPE_Interleaved and the *pSink* parameter is **NULL**, the method splits the interleaved stream into an audio stream and a video stream, and renders both of those streams.

The `RenderStream` method handles many of the details required for capture graphs:

**Smart Tee**. Some capture filters have a capture pin but no preview pin. To preview, the capture pin must be connected to the [Smart Tee Filter](https://learn.microsoft.com/windows/desktop/DirectShow/smart-tee-filter). This filter splits the data into two streams, a capture stream and a preview stream. When you specify PIN_CATEGORY_PREVIEW or PIN_CATEGORY_CAPTURE, the method inserts a Smart Tee filter if one is needed. Then it renders the specified stream on the Smart Tee filter. If you render a preview stream and the method uses a Smart Tee filter, it returns VFW_S_NOPREVIEWPIN.

**Closed Captioning**. You can use this method to capture or preview closed captioning. Some capture filters deliver Vertical Blanking Interval (VBI) data, others deliver closed captioning data. To handle either case, call the method twice, once using PIN_CATEGORY_VBI and once using PIN_CATEGORY_CC. The method inserts any filters needed to convert VBI data to closed captioning. To preview the data, set the *pSink* parameter to **NULL**. To capture the data to a file, use the multiplexer filter's **IBaseFilter** interface pointer. You can capture and preview the data in the same graph. Call the method once using **NULL** and again using the multiplexer. Set the *pIntermediate* parameter to **NULL**.

**Video Port Pins**. Filters that work with video port extension (VPE) video capture hardware might have video port pins (PIN_CATEGORY_VIDEOPORT) instead of preview pins. For preview or capture to work, a video port pin must connect to the [Overlay Mixer Filter](https://learn.microsoft.com/windows/desktop/DirectShow/overlay-mixer-filter). The method handles this detail. You do not have to specify PIN_CATEGORY_VIDEOPORT. Specify PIN_CATEGORY_PREVIEW or PIN_CATEGORY_CAPTURE, and the method will connect the pin correctly. In a similar way, some filters deliver VBI data using video port pins (PIN_CATEGORY_VIDEOPORT_VBI). As with PIN_CATEGORY_VIDEOPORT, the method handles this detail. You do not have to specify PIN_CATEGORY_VIDEOPORT_VBI.

**Supporting Filters**. If a capture device uses a Windows Driver Model (WDM) driver, the graph may require certain filters upstream from the [WDM Video Capture Filter](https://learn.microsoft.com/windows/desktop/DirectShow/wdm-video-capture-filter), such as a [TV Tuner Filter](https://learn.microsoft.com/windows/desktop/DirectShow/tv-tuner-filter) or an [Analog Video Crossbar Filter](https://learn.microsoft.com/windows/desktop/DirectShow/analog-video-crossbar-filter). If this method successfully renders the stream, it also inserts any WDM filters that are required in your graph. The method queries the input pins on the capture filter to determine what mediums they support, and connects them to matching filters.

### Example Code

For a typical capture graph, connect the preview pin to the default renderer, with no intermediate filter:

| C++ |
| --- |
| ``` // Video:  pBuilder->RenderStream(&PIN_CATEGORY_PREVIEW, &MEDIATYPE_Video,      pCaptureFilter, NULL, NULL);  // Audio: pBuilder->RenderStream(&PIN_CATEGORY_PREVIEW, &MEDIATYPE_Audio,      pCaptureFilter, NULL, NULL); ``` |

Connect the capture pin to a mux filter or file writer filter, depending on what type of file you wish to output. For AVI files, use the [AVI Mux](https://learn.microsoft.com/windows/desktop/DirectShow/avi-mux-filter) filter. For ASF files, use the [WM ASF Writer](https://learn.microsoft.com/windows/desktop/DirectShow/wm-asf-writer-filter) filter. Typically, you will get a pointer to this filter from the *ppf* parameter of the [ICaptureGraphBuilder2::SetOutputFileName](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-icapturegraphbuilder2-setoutputfilename) method.

| C++ |
| --- |
| ``` pBuilder->SetOutputFileName(&MEDIASUBTYPE_Avi, L"C:\\Example.avi",      &ppf, &pSink); pBuilder->RenderStream(&PIN_CATEGORY_CAPTURE, &MEDIATYPE_Video,     pCaptureFilter, NULL, ppf); ``` |

### File Sources

You can use this method to transcode or recompress a file. The following discussion assumes that the file has at most one video stream and one audio stream, or else a single interleaved stream. Otherwise, the method will not work correctly.

A file source has one output pin, so set *pCategory* and *pType* to **NULL**. Call the method twice—once to render the video stream, and once to render the audio stream. The first call connects the source filter to a parser filter and renders one of the parser filter's output pins. The second call renders the parser's remaining output pin. If you are compressing one stream but not the other, make sure to specify the compressor filter in the first call. The method will automatically pick the correct stream based on the compression type.

| C++ |
| --- |
| ``` pBuilder->RenderStream(NULL, NULL, pSrc, pCompressor, pMux); pBuilder->RenderStream(NULL, NULL, pSrc, NULL, pMux); ``` |

For a complete example, see [Recompressing an AVI File](https://learn.microsoft.com/windows/desktop/DirectShow/recompressing-an-avi-file).

## See also

[Building Graphs with the Capture Graph Builder](https://learn.microsoft.com/windows/desktop/DirectShow/building-graphs-with-the-capture-graph-builder)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[ICaptureGraphBuilder2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icapturegraphbuilder2)

[Video Capture](https://learn.microsoft.com/windows/desktop/DirectShow/video-capture)