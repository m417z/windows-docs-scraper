# WaitDispatchingMessages function

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `WaitDispatchingMessages` function waits for an object to be signaled, while dispatching window messages.

## Parameters

*hObject*

Handle of the object to wait for.

*dwWait*

Time-out interval, in milliseconds.

*hwnd*

Optional handle to a window.

*uMsg*

Optional window message, specifying a message to dispatch.

*hEvent*

Optional handle to an event to wait for.

## Return value

Returns the value from the **WaitForMultipleObjects** function.

## Remarks

If an object owns a window, it should dispatch window messages while waiting. This function enables the object to wait for an event, semaphore, or other mutual exclusion object while dispatching messages.

## Requirements

| Requirement | Value |
|--------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Header<br> | Wxutil.h (include Streams.h) |
| Library<br> | Strmbase.lib (retail builds);

Strmbasd.lib (debug builds) | ## See also [Miscellaneous Helper Functions](https://learn.microsoft.com/windows/win32/directshow/miscellaneous-helper-functions)