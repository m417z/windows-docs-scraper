# DbgTerminate function

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **DbgTerminate** function cleans up the debug library. Ignored in retail builds.

## Parameters

This function has no parameters.

## Return value

This function does not return a value.

## Remarks

Call this function if you call the [**DbgInitialise**](https://learn.microsoft.com/windows/win32/directshow/dbginitialise) function.

## Requirements

| Requirement | Value |
|--------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Header<br> | Wxdebug.h (include Streams.h) |
| Library<br> | Strmbase.lib (retail builds);

Strmbasd.lib (debug builds) | ## See also [Debug Output Functions](https://learn.microsoft.com/windows/win32/directshow/debug-output-functions)