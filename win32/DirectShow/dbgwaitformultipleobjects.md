# DbgWaitForMultipleObjects function

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Waits for any (or all) of the specified objects to be signaled.

In a debug build, this function triggers an assert if the time-out interval expires before the objects are signaled. To set the time-out interval, call the [**DbgSetWaitTimeout**](https://learn.microsoft.com/windows/win32/directshow/dbgsetwaittimeout) function.

In a retail build, this function is equivalent to the **WaitForMultipleObjects** function with a time-out interval of INFINITE.

## Parameters

*nCount*

Number of objects.

*lpHandles*

Array of handles to objects, of size *nCount*.

*bWaitAll*

Boolean value that specifies whether to wait for all of the objects. If **TRUE**, the function waits for all of the objects to be signaled. Otherwise, it waits for at least one object to be signaled.

## Requirements

| Requirement | Value |
|--------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Header<br> | Wxdebug.h (include Streams.h) |
| Library<br> | Strmbase.lib (retail builds); <br>Strmbasd.lib (debug builds) |

## See also

[Wait Debugging Functions](https://learn.microsoft.com/windows/win32/directshow/wait-debugging-functions)

