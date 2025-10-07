# DbgLockTrace function

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Enables or disables debug logging of a given critical section.

## Parameters

*pcCrit*

Pointer to a [**CCritSec**](https://learn.microsoft.com/windows/win32/directshow/ccritsec) critical section.

*fTrace*

Value specifying whether logging is enabled. Use **TRUE** to enable logging or **FALSE** to disable it.

## Return value

This function does not return a value.

## Remarks

Use this function to trace a specific critical section. By default, debug logging of critical sections is disabled, because of the large number of critical sections.

To trace a critical section, perform the following steps:

1. Define DEBUG or \_DEBUG before you include the DirectShow headers.
2. Enable debug logging for critical sections, by calling [**DbgSetModuleLevel**](https://learn.microsoft.com/windows/win32/directshow/dbgsetmodulelevel) with the LOG\_LOCKING flag.
3. Call **DbgLockTrace** on the critical section you want to trace.

In retail builds, the **DbgLockTrace** function has no effect.

## Examples

The following code example shows how to trace a critical section.

```
DbgInitialise(g_hInst);
DbgSetModuleLevel(LOG_LOCKING, 3);

{
    CCritSec MyLock;
    DbgLockTrace(&MyLock, TRUE);

    CAutoLock cObjectLock(&MyLock);

    // Protected section of code.
    DbgOutString("This code is inside a critical section.\n");

} // Lock goes out of scope here.

DbgTerminate();
```

## Requirements

| Requirement | Value |
|--------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Header<br> | Wxutil.h (include Streams.h) |
| Library<br> | Strmbase.lib (retail builds);

Strmbasd.lib (debug builds) | ## See also [Critical Section Debugging Functions](https://learn.microsoft.com/windows/win32/directshow/critical-section-debugging-functions)