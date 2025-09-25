# IEnumMediaTypes::Next

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **Next** method retrieves a specified number of media types.

## Parameters

### `cMediaTypes` [in]

The number of media types to retrieve.

### `ppMediaTypes` [out]

The address of an array of [AM_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-am_media_type) pointers. The number of elements in the array is given in the *cMediaTypes* parameter.

### `pcFetched` [out]

Receives the number of media types returned in *ppMediaTypes*. This parameter can be **NULL** if *cMediaTypes* is 1.

## Return value

Returns one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_FALSE** | Did not retrieve as many media types as requested. |
| **S_OK** | Success. |
| **E_INVALIDARG** | Invalid argument. |
| **E_POINTER** | **NULL** pointer argument. |
| **VFW_E_ENUM_OUT_OF_SYNC** | The pin's state has changed and is now inconsistent with the enumerator. |

## Remarks

The caller passes an array of [AM_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-am_media_type) pointers in *ppMediaTypes*. The method allocates a number **AM_MEDIA_TYPE** structures equal to *cMediaTypes* or to the number of media types that remain in the enumeration, whichever is less. The number of structures allocated is returned in *pcFetched*. Delete each structure by calling the [DeleteMediaType](https://learn.microsoft.com/windows/desktop/DirectShow/deletemediatype) function.

If the set of media types changes, the enumerator becomes inconsistent with the owning pin. In that case, the method returns VFW_E_ENUM_OUT_OF_SYNC. Discard any data obtained from previous calls to the enumerator, because it might be invalid. Update the enumerator by calling the [IEnumMediaTypes::Reset](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ienummediatypes-reset) method. You can then call the **Next** method safely.

## See also

[Enumerating Media Types](https://learn.microsoft.com/windows/desktop/DirectShow/enumerating-media-types)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IEnumMediaTypes Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ienummediatypes)