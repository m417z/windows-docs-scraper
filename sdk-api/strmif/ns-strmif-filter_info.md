# FILTER_INFO structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `FILTER_INFO` structure contains information about a filter.

## Members

### `achName`

Null-terminated string containing the name of the filter.

### `pGraph`

If the filter is member of a filter graph, contains a pointer to the filter graph's [IFilterGraph](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifiltergraph) interface. If the filter is not a member of a filter graph, this value of this member is **NULL**.

## Remarks

If the **pGraph** member is not **NULL**, the application should release the [IFilterGraph](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifiltergraph) interface when it is finished using it.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)