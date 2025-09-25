# AM_DVD_RENDERSTATUS structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The AM_DVD_RENDERSTATUS structure contains codes indicating the status of DVD-Video playback. These codes are used in the [IDvdGraphBuilder::RenderDvdVideoVolume](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdgraphbuilder-renderdvdvideovolume) method.

## Members

### `hrVPEStatus`

Overlay/VPE error code. Zero indicates success; any other value is failure.

### `bDvdVolInvalid`

**TRUE** if the specified DVD volume to be played does not exist; **FALSE** otherwise.

### `bDvdVolUnknown`

**TRUE** if no DVD volume is specified or if it isn't found; **FALSE** otherwise.

### `bNoLine21In`

**TRUE** if the video decoder doesn't produce line 21 (closed captioning) data; **FALSE** otherwise.

### `bNoLine21Out`

**TRUE** if the video decoder can't be shown as closed captioning on video due to a problem with graph building; **FALSE** otherwise.

### `iNumStreams`

Number of DVD streams to render.

### `iNumStreamsFailed`

Number of streams that failed to render.

### `dwFailedStreamsFlag`

Combination of [AM_DVD_STREAM_FLAGS](https://learn.microsoft.com/windows/win32/api/strmif/ne-strmif-am_dvd_stream_flags) flags indicating which streams failed.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)

[IDvdGraphBuilder::RenderDvdVideoVolume](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdgraphbuilder-renderdvdvideovolume)