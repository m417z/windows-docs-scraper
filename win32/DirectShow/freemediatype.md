# FreeMediaType function

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **FreeMediaType** function deletes the format block in an [**AM\_MEDIA\_TYPE**](https://learn.microsoft.com/windows/win32/api/strmif/ns-strmif-am_media_type) structure.

## Parameters

*mt* \[ref\]

A reference to an [**AM\_MEDIA\_TYPE**](https://learn.microsoft.com/windows/win32/api/strmif/ns-strmif-am_media_type) structure.

## Return value

This function does not return a value.

## Remarks

The format block is allocated on the heap. The **pbFormat** member of the [**AM\_MEDIA\_TYPE**](https://learn.microsoft.com/windows/win32/api/strmif/ns-strmif-am_media_type) points to the format block. Use this function to free just the format block. To delete an allocated **AM\_MEDIA\_TYPE** structure, call [**DeleteMediaType**](https://learn.microsoft.com/windows/win32/directshow/deletemediatype).

This function is defined in the [DirectShow Base Classes](https://learn.microsoft.com/windows/win32/directshow/directshow-base-classes) library. If you prefer not to link to the base class library, you can use the following code:

```C++
// Release the format block for a media type.

void _FreeMediaType(AM_MEDIA_TYPE& mt)
{
    if (mt.cbFormat != 0)
    {
        CoTaskMemFree((PVOID)mt.pbFormat);
        mt.cbFormat = 0;
        mt.pbFormat = NULL;
    }
    if (mt.pUnk != NULL)
    {
        // pUnk should not be used.
        mt.pUnk->Release();
        mt.pUnk = NULL;
    }
}
```

## Requirements

| Requirement | Value |
|--------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Header<br> | Mtype.h (include Streams.h) |
| Library<br> | Strmbase.lib (retail builds); <br>Strmbasd.lib (debug builds) |

## See also

[**DeleteMediaType**](https://learn.microsoft.com/windows/win32/directshow/deletemediatype)

[**Media Type Functions**](https://learn.microsoft.com/windows/win32/directshow/media-type-functions)

