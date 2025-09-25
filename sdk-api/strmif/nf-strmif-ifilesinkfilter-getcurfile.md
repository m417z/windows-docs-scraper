# IFileSinkFilter::GetCurFile

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetCurFile` method retrieves the name and media type of the current file.

## Parameters

### `ppszFileName` [out]

Address of a pointer that receives the name of the file, as an **OLESTR** type.

### `pmt` [out]

Pointer to an [AM_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-am_media_type) structure that receives the media type. This parameter can by **NULL**, in which case the method does not return the media type.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_FAIL** | No file is opened. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_POINTER** | **NULL** pointer argument in *ppszFileName*. |

## Remarks

If the filter has not opened a file, the method might succeed but return **NULL** in the *ppszFileName* parameter. Check the value when the method returns.

The method allocates the memory for the string returned in *ppszFileName*, and the memory for the format block in the media type (if any). The caller must free them by calling **CoTaskMemFree**. For the media type, you can use the [FreeMediaType](https://learn.microsoft.com/windows/desktop/DirectShow/freemediatype) function in the base class library.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IFileSinkFilter Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifilesinkfilter)