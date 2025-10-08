# StringFromResource function

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `StringFromResource` function loads a string from a resource file with the given resource identifier.

## Parameters

*pBuffer*

Pointer to the string corresponding to *iResourceID*.

*iResourceID*

Resource identifier of the string to retrieve.

## Return value

Returns the same string as *pBuffer*. If the function is not successful, returns a null string.

## Remarks

The *pBuffer* buffer must be at least STR\_MAX\_LENGTH bytes.

## Requirements

| Requirement | Value |
|--------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Header<br> | Wxutil.h (include Streams.h) |
| Library<br> | Strmbase.lib (retail builds); <br>Strmbasd.lib (debug builds) |

## See also

[Property Page Helper Functions](https://learn.microsoft.com/windows/win32/directshow/property-page-helper-functions)

