# ICaptureGraphBuilder::RenderStream

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** The **ICaptureGraphBuilder** interface is deprecated. Use [ICaptureGraphBuilder2](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icapturegraphbuilder2) instead.

Connects a source filter's pin, of an optionally specified category, to the rendering filter, and optionally through another filter.

## Parameters

### `pCategory` [in]

Pointer to a GUID specifying which output pin of the source filter to connect. See [Pin Property Set](https://learn.microsoft.com/windows/desktop/DirectShow/pin-property-set) for a list of all pin categories. **NULL** indicates render the only output pin, regardless of category.

### `pSource` [in]

Pointer to an [IBaseFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ibasefilter) or an [IPin](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipin) interface representing either the source filter or an output pin. Source filters are typically a file source filter, such as an AVI file source filter or a capture filter.

### `pfCompressor` [in]

Pointer to an [IBaseFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ibasefilter) interface representing the optional compression filter.

### `pfRenderer` [in]

Pointer to an [IBaseFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ibasefilter) interface representing the renderer. You can use the *ppf* (multiplexer) parameter from [ICaptureGraphBuilder::SetOutputFileName](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-icapturegraphbuilder-setoutputfilename) to supply this value.

## Return value

Returns VFW_S_NOPREVIEWPIN if the capture filter has a capture pin but no preview pin, and you call `RenderStream` with the &PIN_CATEGORY_PREVIEW category on the capture pin. In this case, `RenderStream` will render the preview pin of the [Smart Tee](https://learn.microsoft.com/windows/desktop/DirectShow/smart-tee-filter) filter. For more information, see Remarks.

## Remarks

If you specify a non-**NULL**[Pin Property Set](https://learn.microsoft.com/windows/desktop/DirectShow/pin-property-set) GUID for *pCategory* and a capture filter for *pSource*, this method instantiates and connects additional required upstream filters, such as TV tuners and crossbars. It then renders the capture pin of *pSource*.

If *pSource* is a pin, then specify **NULL** for *pCategory* and this method renders the stream from that pin.

If the source filter has only one output pin, specify **NULL** for *pCategory*.

*pSource*, *pfCompressor*, and *pfRenderer* filters given as parameters must be present in the graph before this method is called.

If you are building a capture graph that is using WDM capture filters, this method will build all necessary upstream filters as well as the downstream filters.

Some capture filters that work with new WDM VPE (Video Port Extension) video capture hardware have video port pins instead of preview pins meant for previewing. Video port pins do not connect directly to a video renderer, but instead to a special filter called the [Overlay Mixer](https://learn.microsoft.com/windows/desktop/DirectShow/overlay-mixer-filter). Your application does not need to worry about this. All you have to do is call `RenderStream` with PIN_CATEGORY_PREVIEW and the capture graph builder will correctly render the VIDEO PORT pin through an overlay mixer if that is what is necessary.

When you render a capture or preview pin of a video capture filter (using `RenderStream` with the PIN_CATEGORY_CAPTURE or PIN_CATEGORY_PREVIEW category) and the capture filter has a capture pin but no preview pin, the [Smart Tee](https://learn.microsoft.com/windows/desktop/DirectShow/smart-tee-filter) filter will be used automatically to allow simultaneous capture and preview. For example, calling `RenderStream` with the PIN_CATEGORY_CAPTURE category will actually connect a Smart Tee filter to the capture pin of the filter, and then render the capture pin of the Smart Tee. If you then call `RenderStream` with the PIN_CATEGORY_PREVIEW category on the capture pin, it will actually render the preview pin of the Smart Tee. If calling `RenderStream` with PIN_CATEGORY_PREVIEW results in using the capture pin and a Smart Tee filter, `RenderStream` will return VFW_S_NOPREVIEWPIN to indicate this. Thus, if [FindInterface](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-icapturegraphbuilder-findinterface) fails to find a preview interface, you may need to call **FindInterface** with the PIN_CATEGORY_PREVIEW category and with the PIN_CATEGORY_CAPTURE category, because the preview interface can be found by looking downstream of the capture pin of the capture filter.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[ICaptureGraphBuilder Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icapturegraphbuilder)