# _AM_INTF_SEARCH_FLAGS enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies the types of object to search, when attempting to find an interface on the filter graph.

## Constants

### `AM_INTF_SEARCH_INPUT_PIN:0x1`

Search input pins.

### `AM_INTF_SEARCH_OUTPUT_PIN:0x2`

Search output pins.

### `AM_INTF_SEARCH_FILTER:0x4`

Search filters.

## Remarks

If no flags are set (the default case), it is equivalent to the bitwise **OR** of all the flags. All filters and pins are searched.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IAMGraphStreams::FindUpstreamInterface](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamgraphstreams-findupstreaminterface)