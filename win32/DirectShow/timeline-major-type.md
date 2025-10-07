# TIMELINE\_MAJOR\_TYPE enumeration

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

> [!Note]
> \[Deprecated. This API may be removed from future releases of Windows.\]

The `TIMELINE_MAJOR_TYPE` enumeration specifies the major type of an object.

## Constants

**TIMELINE\_MAJOR\_TYPE\_COMPOSITE**

Composite object. Holds one or more tracks.

**TIMELINE\_MAJOR\_TYPE\_TRACK**

Track object. Holds one or more sources.

**TIMELINE\_MAJOR\_TYPE\_SOURCE**

Source object. Contains a reference to a media source.

**TIMELINE\_MAJOR\_TYPE\_TRANSITION**

Transition object. Defines a transition between composites, tracks, or sources.

**TIMELINE\_MAJOR\_TYPE\_EFFECT**

Effect object. Defines a single-input effect to be applied to a composite, track, or source object.

**TIMELINE\_MAJOR\_TYPE\_GROUP**

Group object. Contains one or more tracks of a given type.

## Requirements

| Requirement | Value |
|-------------------|------------------------------------------------------------------------------------|
| Header<br> | Qedit.h |

## See also

[**IAMTimeline**](https://learn.microsoft.com/windows/win32/directshow/iamtimeline)

[**IAMTimelineComp::GetCountOfType**](https://learn.microsoft.com/windows/win32/directshow/iamtimelinecomp-getcountoftype)

[**IAMTimelineObj::GetTimelineType**](https://learn.microsoft.com/windows/win32/directshow/iamtimelineobj-gettimelinetype)

