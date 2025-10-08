# CritCheckOut function

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Returns **FALSE** if the current thread is the owner of the specified critical section.

## Parameters

*pcCrit*

Pointer to a [**CCritSec**](https://learn.microsoft.com/windows/win32/directshow/ccritsec) critical section.

## Return value

In debug builds, returns **FALSE** if the current thread is the owner of this critical section, or **TRUE** otherwise. In retail builds, always returns **TRUE**.

## Remarks

This function is the inverse of the [**CritCheckIn**](https://learn.microsoft.com/windows/win32/directshow/critcheckin) function. If **CritCheckIn** returns **TRUE**, **CritCheckOut** returns **FALSE**, and vice versa.

## Requirements

| Requirement | Value |
|--------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Header<br> | Wxutil.h (include Streams.h) |
| Library<br> | Strmbase.lib (retail builds); <br>Strmbasd.lib (debug builds) |

## See also

[Critical Section Debugging Functions](https://learn.microsoft.com/windows/win32/directshow/critical-section-debugging-functions)

