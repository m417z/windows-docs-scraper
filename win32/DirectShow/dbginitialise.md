# DbgInitialise function

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **DbgInitialise** function initializes the debug library. Ignored in retail builds.

## Parameters

*hInst*

Handle to the module instance.

## Return value

This function does not return a value.

## Remarks

In an executable, call this method before using the DirectShow debug facilities. Before the executable quits, call the [**DbgTerminate**](https://learn.microsoft.com/windows/win32/directshow/dbgterminate) function to clean up the debug library.

In a DLL that links to the base-class library (Strmbase.lib), it is not necessary to call this function. The function is called automatically when the DLL is loaded.

## Requirements

| Requirement | Value |
|--------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Header<br> | Wxdebug.h (include Streams.h) |
| Library<br> | Strmbase.lib (retail builds);

Strmbasd.lib (debug builds) | ## See also [Debug Output Functions](https://learn.microsoft.com/windows/win32/directshow/debug-output-functions)