# AM_MPEGSYSTEMTYPE structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AM_MPEGSYSTEMTYPE** structure defines the format block for an MPEG-1 system stream. This structure is used when the **formattype** member of the [AM_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-am_media_type) structure is FORMAT_MPEG1System.

## Members

### `dwBitRate`

Bits per second.

### `cStreams`

Number of streams.

### `Streams`

List [AM_MPEGSTREAMTYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpegtype/ns-mpegtype-am_mpegstreamtype) structures that describe the elementary streams. The number of elements in the list is given by the **cStream** member. The size of each **AM_MPEGSTREAMTYPE** structure is variable. Use the **AM_MPEGSTREAMTYPE_ELEMENTLENGTH** macro to calculate the size of each structure.

## Remarks

The **Streams** member contains a list of [AM_MPEGSTREAMTYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpegtype/ns-mpegtype-am_mpegstreamtype) structures. The size of each **AM_MPEGSTREAMTYPE** structure is aligned to an 8-byte boundary. Given a pointer to an **AM_MPEGSTREAMTYPE** structure in list, use the **AM_MPEGSTREAMTYPE_NEXT** macro to get a pointer to the next structure.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)

[MEPG-1 Media Types](https://learn.microsoft.com/windows/desktop/DirectShow/mpeg-1-media-types)