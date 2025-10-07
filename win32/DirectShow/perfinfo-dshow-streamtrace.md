# PERFINFO\_DSHOW\_STREAMTRACE structure

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `PERFINFO_DSHOW_STREAMTRACE` structure contains data for a DirectShow trace event of type GUID\_STREAMTRACE.

## Members

**id**

Event identifier. See Remarks.

**reserved**

Reserved. Set to zero.

**dshowClock**

Stream time for this event, in 100-nanosecond units. This value is optional and can be zero.

**data**

Optional event data consisting of four **ULONGLONG** values. The meaning of this data depends on the event identifier.

## Remarks

The following event identifiers are defined.

| Event identifier | Description |
|------------------|-------------|
| PERFINFO_STREAMTRACE_MPEG2DEMUX_PTS_TRANSLATION | Logged when the [MPEG-2 Demultiplexer](https://learn.microsoft.com/windows/win32/directshow/mpeg-2-demultiplexer) filter converts a presentation time stamp (PTS) to stream time.

* **data**[0]: Converted start time.
* **data**[1]: Converted stop time.
* **data**[2]. Stream identifier for the input pin.
* **data**[3]: PTS that was converted.

|
| PERFINFO_STREAMTRACE_MPEG2DEMUX_SAMPLE_RECEIVE | Logged when MPEG-2 Demultiplexer receives a sample.

* **data**[0]: Current time returned by [**QueryPerformanceCounter**](https://learn.microsoft.com/windows/win32/api/profileapi/nf-profileapi-queryperformancecounter).

|
| PERFINFO_STREAMTRACE_VMR_BEGIN_ADVISE | Logged when the VMR schedules a sample for rendering, immediately before the VMR calls [**IReferenceClock::AdviseTime**](https://learn.microsoft.com/windows/desktop/api/Strmif/nf-strmif-ireferenceclock-advisetime).

* **data**[0]: Reference time when streaming began, which corresponds to stream time zero.

|
| PERFINFO_STREAMTRACE_VMR_BEGIN_DECODE | Logged when the VMR begins a decoding operation—that is, when the decoder calls [**IAMVideoAccelerator::BeginFrame**](https://learn.microsoft.com/previous-versions/windows/desktop/api/videoacc/nf-videoacc-iamvideoaccelerator-beginframe). No event data. |
| PERFINFO_STREAMTRACE_VMR_BEGIN_DEINTERLACE | Logged when the VMR begins a deinterlacing or video compositing operation. No event data. |
| PERFINFO_STREAMTRACE_VMR_DROPPED_FRAME | Logged when the VMR drops a frame; for example, if a sample was late.

* **data**[0]: Sample start time.
* **data**[1]: Sample end time.

|
| PERFINFO_STREAMTRACE_VMR_END_ADVISE | Logged when the VMR receives an advise notification from the reference clock. No event data. |
| PERFINFO_STREAMTRACE_VMR_END_DECODE | Logged when the VMR ends a decoding operation—that is, when the decoder calls [**IAMVideoAccelerator::EndFrame**](https://learn.microsoft.com/previous-versions/windows/desktop/api/videoacc/nf-videoacc-iamvideoaccelerator-endframe). No event data. |
| PERFINFO_STREAMTRACE_VMR_END_DEINTERLACE | Logged when the VMR completes a deinterlacing or video compositing operation. No event data. |
| PERFINFO_STREAMTRACE_VMR_RECEIVE | Logged when the VMR receives a new sample. No event data. |
| PERFINFO_STREAMTRACE_VMR_RENDER_TIME | Logged when the VMR finishes rendering a frame.

* **data**[0]: Time that it took to render this frame.
* **data**[1]: Running average of frame rendering times.

|

To log this event from a DirectShow filter, use the **PERFLOG\_STREAMTRACE** function, which is defined in the header file Dxmperf.h. This header is included in the DirectShow base classes.

## Requirements

| Requirement | Value |
|-------------------|-----------------------------------------------------------------------------------------|
| Header<br> | Perfstruct.h |

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/win32/directshow/directshow-structures)

[Event Tracing in DirectShow](https://learn.microsoft.com/windows/win32/directshow/event-tracing-in-directshow)

[Trace Event GUIDs](https://learn.microsoft.com/windows/win32/directshow/trace-guids)

