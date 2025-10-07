# CheckVideoInfo2Type function

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `CheckVideoInfo2Type` function checks a media type that contains a [**VIDEOINFOHEADER2**](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvdmedia/ns-dvdmedia-videoinfoheader2) format structure for certain common errors that can cause buffer overruns or integer overflows.

> [!Note]
> This function does not guarantee that the media type is valid or that code using the structure is secure.

## Parameters

*pmt*

Pointer to the [**AM\_MEDIA\_TYPE**](https://learn.microsoft.com/windows/win32/api/strmif/ns-strmif-am_media_type) structure to validate.

## Return value

Returns one of the following **HRESULT** values.

| Return code | Description |
|------------------------------------------------------------------------------------------------------------|-----------------------------------|
| **S\_OK** | Success<br> |
| **E\_POINTER** | **NULL** pointer value<br> |
| **VFW\_E\_TYPE\_NOT\_ACCEPTED** | Invalid media type<br> |

## Remarks

This function calls [**ValidateBitmapInfoHeader**](https://learn.microsoft.com/windows/win32/directshow/validatebitmapinfoheader) to validate the [**BITMAPINFOHEADER**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader) structure in the media type. If the format type is not **FORMAT\_VideoInfo2**, the function returns **VFW\_E\_TYPE\_NOT\_ACCEPTED**.

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------|
| Header<br> | Checkbmi.h |

## See also

[Video and Image Functions](https://learn.microsoft.com/windows/win32/directshow/video-and-image-functions)

