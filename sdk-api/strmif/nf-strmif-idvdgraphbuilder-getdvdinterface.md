# IDvdGraphBuilder::GetDvdInterface

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetDvdInterface** method retrieves interfaces from the DVD-Video playback graph to make DVD-Video playback development easier.

## Parameters

### `riid` [in]

IID of the requested interface.

### `ppvIF` [out]

Receives a pointer to the interface. The application must release the interface.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The *ppvIF* parameter is invalid. This parameter must not be **NULL**. |
| **E_NOINTERFACE** | The requested interface could not be returned. |
| **VFW_E_DVD_GRAPHNOTREADY** | The graph is not built yet. See Remarks. |

## Remarks

You can use this method to select and configure a video renderer filter before you build the filter graph for DVD playback. The following interfaces are available:

* **Overlay Mixer Filter**: [IDDrawExclModeVideo](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iddrawexclmodevideo).
* **Video Mixing Renderer 7 (VMR-7)**: [IVMRFilterConfig](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrfilterconfig), [IVMRMixerBitmap](https://learn.microsoft.com/windows/win32/api/strmif/nn-strmif-ivmrmixerbitmap), [IVMRWindowlessControl](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrwindowlesscontrol), and [IVMRMonitorConfig](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrmonitorconfig).
* **Video Mixing Renderer 9 (VMR-9)**: [IVMRFilterConfig9](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/nn-vmr9-ivmrfilterconfig9), [IVMRMixerBitmap9](https://learn.microsoft.com/previous-versions/ms787059(v=vs.85)), [IVMRWindowlessControl9](https://learn.microsoft.com/previous-versions/ms787155(v=vs.85)), and [IVMRMonitorConfig9](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/nn-vmr9-ivmrmonitorconfig9).
* **Enhanced Video Renderer (EVR)**: [IEVRFilterConfig](https://learn.microsoft.com/windows/desktop/api/evr/nn-evr-ievrfilterconfig) and [IMFVideoRenderer](https://learn.microsoft.com/windows/desktop/api/evr/nn-evr-imfvideorenderer).**Windows Server 2003, Windows XP and Windows 2000:** This interface is not supported.

If you call **GetDvdInterface** to get any of these interfaces before you build the filter graph, the DVD Graph Builder creates the appropriate video renderer. It will use this renderer later when you build the graph. After the video renderer has been selected, you can no longer retrieve the interfaces for the other video renderers. (The **GetDvdInterface** method will return E_NOINTERFACE.)

Before the DVD playback graph is built, if you request any interfaces that are not on the previous list, the method returns VFW_E_DVD_GRAPHNOTREADY. To build the DVD graph, call [IDvdGraphBuilder::RenderDvdVideoVolume](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdgraphbuilder-renderdvdvideovolume). After you build the graph, you can use **GetDvdInterface** to retrieve some additional interfaces:

* [IDvdControl](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcontrol) (deprecated), [IDvdControl2](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcontrol2), [IDvdInfo](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdinfo) (deprecated), and [IDvdInfo2](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdinfo2) to control DVD playback.
* [IVideoWindow](https://learn.microsoft.com/windows/desktop/api/control/nn-control-ivideowindow), [IBasicVideo](https://learn.microsoft.com/windows/desktop/api/control/nn-control-ibasicvideo), and [IBasicVideo2](https://learn.microsoft.com/windows/desktop/api/control/nn-control-ibasicvideo2) to control the video settings, in windowed mode only.
* [IBasicAudio](https://learn.microsoft.com/windows/desktop/api/control/nn-control-ibasicaudio) to control the audio settings.
* [IAMLine21Decoder](https://learn.microsoft.com/previous-versions/windows/desktop/api/il21dec/nn-il21dec-iamline21decoder) to control closed caption display.
* [IMixerPinConfig](https://learn.microsoft.com/windows/desktop/api/mpconfig/nn-mpconfig-imixerpinconfig) and [IMixerPinConfig2](https://learn.microsoft.com/windows/desktop/api/mpconfig/nn-mpconfig-imixerpinconfig2) to configure the Overlay Mixer filter's first input pin, which delivers the primary video stream. (To get this interface for the other pins on the Overlay Mixer, enumerate the filter's pins and query them directly.) New applications should avoid using the Overlay Mixer filter.

To get other interfaces, call [IDvdGraphBuilder::GetFiltergraph](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdgraphbuilder-getfiltergraph). Query the returned **IGraphBuilder** interface or use **EnumFilters** to enumerate the filters.

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdGraphBuilder Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdgraphbuilder)