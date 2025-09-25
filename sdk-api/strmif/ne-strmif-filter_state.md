# FILTER_STATE enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies a filter's state or the state of the filter graph.

## Constants

### `State_Stopped:0`

Stopped. The filter is not processing data.

### `State_Paused`

Paused. The filter is processing data, but not rendering it.

### `State_Running`

Running. The filter is processing and rendering data.

## See also

[Data Flow in the Filter Graph](https://learn.microsoft.com/windows/desktop/DirectShow/data-flow-in-the-filter-graph)

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IMediaControl::GetState](https://learn.microsoft.com/windows/desktop/api/control/nf-control-imediacontrol-getstate)

[IMediaFilter::GetState](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediafilter-getstate)