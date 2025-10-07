# DEXTERF\_TRACK\_SEARCH\_FLAGS enumeration

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

> [!Note]
> \[Deprecated. This API may be removed from future releases of Windows.\]

The `DEXTERF_TRACK_SEARCH_FLAGS` enumeration specifies the boundary conditions on a search for an object in the timeline.

## Constants

**DEXTERF\_BOUNDING**

Search for an object that spans the specified time.

**DEXTERF\_EXACTLY\_AT**

Search for an object that starts exactly at the specified time.

**DEXTERF\_FORWARDS**

Search for an object that starts at the specified time or later.

## Remarks

These boundary conditions are summarized in the following table.

| Enumeration value | Boundary condition |
|----------------------|-------------------------------------------|
| DEXTERF\_BOUNDING | Start <= TimeStop > Time<br> |
| DEXTERF\_EXACTLY\_AT | Start == Time |
| DEXTERF\_FORWARDS | Start >= Time |

- Start: start time of the retrieved object.
- Stop: stop time of the retrieved object.
- Time: specified search time.

## Requirements

| Requirement | Value |
|-------------------|------------------------------------------------------------------------------------|
| Header<br> | Qedit.h |

## See also

[**IAMTimelineTrack::GetSrcAtTime**](https://learn.microsoft.com/windows/win32/directshow/iamtimelinetrack-getsrcattime)

