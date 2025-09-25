# AM_GRAPH_CONFIG_RECONNECT_FLAGS enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies how to reconnect filters when dynamically rebuilding the filter graph.

## Constants

### `AM_GRAPH_CONFIG_RECONNECT_DIRECTCONNECT:0x1`

Do not insert additional filters into the graph while reconnecting, aside from any filter explicitly requested.

### `AM_GRAPH_CONFIG_RECONNECT_CACHE_REMOVED_FILTERS:0x2`

Place filters removed from the graph into the filter cache.

### `AM_GRAPH_CONFIG_RECONNECT_USE_ONLY_CACHED_FILTERS:0x4`

When inserting additional filters into the graph, use only filters currently in the filter cache.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IGraphConfig::Reconnect](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-igraphconfig-reconnect)

[IPinFlowControl::Block](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ipinflowcontrol-block)