# IAMGraphStreams::FindUpstreamInterface

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `FindUpstreamInterface` method searches the filter graph for a specified interface, upstream from a specified pin.

## Parameters

### `pPin` [in]

Pointer to the [IPin](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipin) interface of a pin. The pin must belong to a filter in the filter graph.

### `riid` [in]

Reference to an interface identifier (IID) that specifies the interface to find.

### `ppvInterface` [out]

Address of a void pointer. If the method succeeds, this variable receives a pointer to the interface specified by *riid*.

### `dwFlags` [in]

Combination of flags from the [AM_INTF_SEARCH_FLAGS](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-_am_intf_search_flags) enumeration, specifying what to search (pins or filters).

## Return value

Returns one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **E_NOINTERFACE** | Interface not found. |
| **E_POINTER** | Invalid pointer. |
| **S_OK** | Success. |

## Remarks

If *dwFlags* is zero, this method searches for the interface in the following order:

1. It queries the pin specified by *pPin*.
2. If *pPin* is an input pin, it calls **FindUpstreamInterface** recursively on the output pin that is connected to *pPin*, if any.

   If *pPin* is an output pin, it queries the filter that owns *pPin*. Then it creates a list of input pins on the filter that have internal connections to *pPin*, and calls `FindUpstreamInterface` recursively on those input pins.

   To create a list of input pins with internal connections, the method does the following:

   * Calls [IPin::QueryInternalConnections](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ipin-queryinternalconnections).
   * If that fails, calls [IBaseFilter::EnumPins](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ibasefilter-enumpins) and looks for input pins.

It stops at the first object it finds that supports the interface. You can limit the objects that are searched (filters, input pin, or output pins) by setting *dwFlags* to a non-zero value.

**Note** The [ICaptureGraphBuilder2::FindInterface](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-icapturegraphbuilder2-findinterface) method implements a more general approach to this problem, and in most situations is preferred.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMGraphStreams Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamgraphstreams)