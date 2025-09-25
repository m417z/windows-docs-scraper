# ICaptureGraphBuilder2::FindInterface

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `FindInterface` method searches the graph for a specified interface, starting from a specified filter. You can restrict the search to a section of the graph upstream or downstream of the filter, or restrict it to a particular pin category or media type.

## Parameters

### `pCategory` [in]

A pointer to a GUID that specifies the search criteria. See Remarks for more information. The following values are possible:

* &LOOK_UPSTREAM_ONLY.
* &LOOK_DOWNSTREAM_ONLY.
* One of the pin categories listed in [Pin Property Set](https://learn.microsoft.com/windows/desktop/DirectShow/pin-property-set).
* **NULL**

See Remarks for more information.

### `pType` [in]

Pointer to a GUID that specifies the major media type of an output pin, or **NULL**.

### `pf` [in]

Pointer to the [IBaseFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ibasefilter) interface of the filter. The method begins searching from this filter.

### `riid` [in]

Interface identifier (IID) of the interface to locate.

### `ppint` [out]

Address of a variable that receives the interface pointer. Be sure to release the retrieved interface pointer when you are done with the interface.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_FAIL** | Failure. |
| **E_NOINTERFACE** | No such interface supported. |
| **E_POINTER** | **NULL** pointer argument. |

## Remarks

In a capture graph, various filters and pins might expose interfaces for setting properties such as compression parameters ([IAMVideoCompression](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamvideocompression)) or stream formats ([IAMStreamConfig](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamstreamconfig)). Depending on the capture device, other useful interfaces might include [IAMCrossbar](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamcrossbar), which routes analog signals, or [IAMTVTuner](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamtvtuner), which controls a TV tuner device. You can use this method to find an interface, without writing special code that traverses the graph.

**Important** Do not call this method to obtain an [IVideoWindow](https://learn.microsoft.com/windows/desktop/api/control/nn-control-ivideowindow) interface pointer. Always query the filter graph manager for this interface. Otherwise, the filter graph manager will not respond correctly to changes in screen resolution and other events.

If the *pCategory* parameter is **NULL**, this method searches the entire graph for the requested interface. Starting from the filter specified by the *pf* parameter, it queries the following objects in the graph.

* The filter
* The filter's pins
* All the downstream filters, including their pins
* All the upstream filters, including their pins

You can restrict the search by setting the *pCategory* and *pType* parameters, as follows:

* If *pCategory* equals &LOOK_UPSTREAM_ONLY, the search starts from the filter's input pins and continues upstream. It does not include the filter or anything downstream from the filter. The *pType* parameter is ignored.
* If *pCategory* equals &LOOK_DOWNSTREAM_ONLY, the search starts from the filter's output pins and continues downstream. It does not include the filter or anything upstream from the filter. The *pType* parameter is ignored.
* If *pCategory* specifies a pin category, the downstream portion of the search is restricted to output pins on the filter that match both the pin category and the media type given in the *pType* parameter. In this case, the method also searches the filter and everything upstream from the filter.

In addition, if *pCategory* is non-**NULL**, the method may add certain Windows Driver Model (WDM) filters upstream from filter specified in *pf*. See the remarks under "Supporting Filters" in this section for more information.

Pin categories are useful for finding pin interfaces on capture filters. For example, a capture filter might have separate pins for capture and preview. If you specify a pin category, you should also specify the media type, to make certain the method selects the correct filter and pin.

Some video capture filters have a video port pin (PIN_CATEGORY_VIDEOPORT) instead of a preview pin. If you specify PIN_CATEGORY_PREVIEW and MEDIATYPE_Video, the method treats any video port pins as preview pins. Your application does not have to test for this possibility.

**Supporting Filters**. If a capture device uses a Windows Driver Model (WDM) driver, the graph may require certain filters upstream from the [WDM Video Capture](https://learn.microsoft.com/windows/desktop/DirectShow/wdm-video-capture-filter) filter, such as a [TV Tuner](https://learn.microsoft.com/windows/desktop/DirectShow/tv-tuner-filter) filter or an [Analog Video Crossbar](https://learn.microsoft.com/windows/desktop/DirectShow/analog-video-crossbar-filter) filter. If the *pCategory* parameter does not equal **NULL**, this method automatically inserts any required WDM filters into the graph. To do so, it queries the input pins on the capture filter to determine what mediums they support, and connects them to matching filters. If the *pCategory* parameter is **NULL**, the method does not add the upstream filters.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[ICaptureGraphBuilder2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icapturegraphbuilder2)