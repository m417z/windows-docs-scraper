# DisplayType function

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `DisplayType` function sends information about a media type to the debug output location. Ignored in retail builds.

## Parameters

*label*

String that contains a message to display with the media type information.

*pmtIn*

ointer to the [**AM\_MEDIA\_TYPE**](https://learn.microsoft.com/windows/win32/api/strmif/ns-strmif-am_media_type) structure that contains the media type.

## Return value

This function does not return a value.

## Remarks

This function generates several LOG\_TRACE messages. At logging level 2 or higher, the function displays the major type, subtype, and format type, and data from the format block. At logging level 5 or higher, the function displays additional information, such as the source and target rectangles for video types.

## Requirements

| Requirement | Value |
|--------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Header<br> | Wxdebug.h (include Streams.h) |
| Library<br> | Strmbase.lib (retail builds);

Strmbasd.lib (debug builds) | ## See also [Debug Output Functions](https://learn.microsoft.com/windows/win32/directshow/debug-output-functions)