# IAMDroppedFrames::GetDroppedInfo

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetDroppedInfo` method retrieves an array of frame numbers that were dropped.

## Parameters

### `lSize` [in]

Specifies the size of the array.

### `plArray` [out]

Pointer to an array of size *lSize*, allocated by the caller. The method fills the array with the frame numbers of the first *lSize* frames that were dropped, up to a maximum number that is device-dependent.

### `plNumCopied` [out]

Pointer to a variable that receives the number of items returned in *plArray*. This number might be less than the value of *lSize*.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | Invalid argument; the *lSize* parameter must by greater than zero. |
| **E_NOTIMPL** | Not implemented. |
| **E_POINTER** | **NULL** pointer argument. |
| **E_PROP_ID_UNSUPPORTED** | Not supported by this device. |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMDroppedFrames Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamdroppedframes)