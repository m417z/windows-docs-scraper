# ValidateBitmapInfoHeader function

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `ValidateBitmapInfoHeader` function checks a [**BITMAPINFOHEADER**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader) structure for certain common errors that can cause buffer overruns or integer overflows.

> [!Note]
> This function does not guarantee that the [**BITMAPINFOHEADER**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader) structure is valid or that code using the structure is secure.

## Parameters

*pbmi*

Pointer to the [**BITMAPINFOHEADER**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader) structure to validate.

*cbSize*

Size of the memory block that holds the structure, in bytes.

## Return value

Returns a Boolean value. If the value is **FALSE**, the [**BITMAPINFOHEADER**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader) structure is not valid.

## Remarks

This function guards against the following errors:

- Arithmetic overflow in the structure size or an invalid structure size.
- Invalid value for the **biClrUsed** member.
- Arithmetic overflow in the image size (**biSizeImage**).
- Invalid values for the image size (**biSizeImage**) for RGB formats.

The function does not check whether the structure describes a valid video format.

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------|
| Header<br> | Checkbmi.h |

## See also

[Video and Image Functions](https://learn.microsoft.com/windows/win32/directshow/video-and-image-functions)

