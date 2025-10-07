# DbgSetWaitTimeout function

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Sets the debugging time-out value. Ignored in retail builds.

## Parameters

*dwTimeout*

Time-out value in milliseconds, or INFINITE to wait indefinitely.

## Return value

This function does not return a value.

## Remarks

In debug builds, the [**DbgWaitForMultipleObjects**](https://learn.microsoft.com/windows/win32/directshow/dbgwaitformultipleobjects) and [**DbgWaitForSingleObject**](https://learn.microsoft.com/windows/win32/directshow/dbgwaitforsingleobject) functions use this value as the time-out interval.

## Requirements

| Requirement | Value |
|--------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Header<br> | Wxdebug.h (include Streams.h) |
| Library<br> | Strmbase.lib (retail builds);

Strmbasd.lib (debug builds) | ## See also [Wait Debugging Functions](https://learn.microsoft.com/windows/win32/directshow/wait-debugging-functions)