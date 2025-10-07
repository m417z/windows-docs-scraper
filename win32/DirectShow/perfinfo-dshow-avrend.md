# PERFINFO\_DSHOW\_AVREND structure

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `PERFINFO_DSHOW_AVREND` structure contains data for a trace event of type GUID\_VIDEOREND.

The VMR logs this event immediately before rendering a frame.

## Members

**cycleCounter**

Latest clock cycle count (RDTSC instruction).

**dshowClock**

Current reference time, as returned by the [**IReferenceClock::GetTime**](https://learn.microsoft.com/windows/desktop/api/Strmif/nf-strmif-ireferenceclock-gettime) method.

**sampleTime**

Start time of the sample.

## Remarks

To enable this event, you must set the DXMPERF\_VIDEOREND flag in the *EnableFlag* parameter when you call **EnableTrace**. This flag is defined in the header file Dxmperf.h, which is included in the DirectShow base classes.

To log this event from a DirectShow filter, use the **PERFLOG\_VIDEOREND** macro, which is defined in Dxmperf.h.

## Requirements

| Requirement | Value |
|-------------------|-----------------------------------------------------------------------------------------|
| Header<br> | Perfstruct.h |

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/win32/directshow/directshow-structures)

[Event Tracing in DirectShow](https://learn.microsoft.com/windows/win32/directshow/event-tracing-in-directshow)

[Trace Event GUIDs](https://learn.microsoft.com/windows/win32/directshow/trace-guids)

