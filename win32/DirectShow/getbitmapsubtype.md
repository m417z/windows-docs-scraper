# GetBitmapSubtype function

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetBitmapSubtype` function returns the media subtype **GUID** for the specified bitmap.

## Parameters

*pHeader*

Pointer to a [**BITMAPINFOHEADER**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader) structure.

## Return value

Returns the media subtype **GUID**.

## Remarks

For uncompressed RGB types, this function maps the **biBitCount** field to the subtype. For compressed video types, this function uses the [**FOURCCMap**](https://learn.microsoft.com/windows/win32/directshow/fourccmap) class to map the **biCompression** field to the subtype.

If the function cannot match the format to a subtype, the return value is GUID\_NULL.

## Requirements

| Requirement | Value |
|--------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Header<br> | Wxutil.h (include Streams.h) |
| Library<br> | Strmbase.lib (retail builds);

Strmbasd.lib (debug builds) | ## See also [Video and Image Functions](https://learn.microsoft.com/windows/win32/directshow/video-and-image-functions)