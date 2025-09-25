# AM_DVD_GRAPH_FLAGS enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AM_DVD_GRAPH_FLAGS** enumeration specifies how the DVD Navigator builds a DVD playback graph. These flags are used with the [IDvdGraphBuilder::RenderDvdVideoVolume](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdgraphbuilder-renderdvdvideovolume) method.

## Constants

### `AM_DVD_HWDEC_PREFER:0x1`

Use a hardware decoder if possible. If none is available, use a software decoder. This is the default setting. Hardware DVD decoders are registered under the CLSID_DVDHWDecodersCategory filter category. See [Filter Categories](https://learn.microsoft.com/windows/desktop/DirectShow/filter-categories).

### `AM_DVD_HWDEC_ONLY:0x2`

Use a hardware decoder; do not use a software decoder. Do not combine this flag with the AM_DVD_VMR9_ONLY or AM_DVD_EVR_ONLY flag.

### `AM_DVD_SWDEC_PREFER:0x4`

Use a software decoder if possible. If none is available, use a hardware decoder.

### `AM_DVD_SWDEC_ONLY:0x8`

Use a software decoder; do not use a hardware decoder.

### `AM_DVD_NOVPE:0x100`

Do not show video on the computer monitor. Use of this flag should be limited only to the combination of a hardware DVD-Video decoder and a display device with a port that can connect to a TV. A set-top box type of device that can play back DVD-Video could play DVD titles to be viewed on a TV set rather than a computer monitor.

### `AM_DVD_DO_NOT_CLEAR:0x200`

Do not clear the filter graph before building the DVD playback graph. By default, the [RenderDvdVideoVolume](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdgraphbuilder-renderdvdvideovolume) method removes any existing filters from the graph before it builds the DVD playback graph.

**Note** Applies to Windows Vista and later.

### `AM_DVD_VMR9_ONLY:0x800`

Use the [Video Mixing Renderer Filter 9](https://learn.microsoft.com/windows/desktop/DirectShow/video-mixing-renderer-filter-9) (VMR-9) for rendering; fail if the VMR-9 is not available. Do not combine this flag with the AM_DVD_EVR_ONLY flag.

### `AM_DVD_EVR_ONLY:0x1000`

Use the Enhanced Video Renderer (EVR) for rendering; fail if the EVR is not available.

**Note** Applies to Windows Vista and later.

### `AM_DVD_EVR_QOS:0x2000`

### `AM_DVD_ADAPT_GRAPH:0x4000`

### `AM_DVD_MASK:0xffff`

## Remarks

Do not combine more than one of the following flags:

* AM_DVD_HWDEC_PREFER
* AM_DVD_HWDEC_ONLY
* AM_DVD_SWDEC_PREFER
* AM_DVD_SWDEC_ONLY

If you have already selected a video renderer by calling [IDvdGraphBuilder::GetDvdInterface](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdgraphbuilder-getdvdinterface), do not set the **AM_DVD_VMR9_ONLY** or **AM_DVD_EVR_ONLY** flag.

To use the VMR-9, the decoder's [IAMDecoderCaps::GetDecoderCaps](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamdecodercaps-getdecodercaps) method must return the **AM_GETDECODERCAP_QUERY_VMR9_SUPPORT** flag. To use the EVR, the decoder's **GetDecoderCaps** method must return the **AM_GETDECODERCAP_QUERY_EVR_SUPPORT** flag.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IDvdGraphBuilder::RenderDvdVideoVolume](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdgraphbuilder-renderdvdvideovolume)