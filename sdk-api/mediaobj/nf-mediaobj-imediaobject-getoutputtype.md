# IMediaObject::GetOutputType

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetOutputType` method retrieves a preferred media type for a specified output stream.

## Parameters

### `dwOutputStreamIndex`

Zero-based index of an output stream on the DMO.

### `dwTypeIndex`

Zero-based index on the set of acceptable media types.

### `pmt` [out]

Pointer to a [DMO_MEDIA_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/mediaobj/ns-mediaobj-dmo_media_type) structure allocated by the caller, or **NULL**. If this parameter is non-**NULL**, the method fills the structure with the media type. You can use the value **NULL** to test whether the type index is in range, by checking the return code.

## Return value

Returns an **HRESULT** value. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **DMO_E_INVALIDSTREAMINDEX** | Invalid stream index. |
| **DMO_E_NO_MORE_ITEMS** | Type index is out of range. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_POINTER** | **NULL** pointer argument. |
| **S_OK** | Success. |

## Remarks

Call this method to enumerate an output stream's preferred media types. The DMO assigns each media type an index value, in order of preference. The most preferred type has an index of zero. To enumerate all the types, make successive calls while incrementing the type index, until the method returns DMO_E_NO_MORE_ITEMS. The DMO is not guaranteed to enumerate every media type that it supports.

The format block in the returned type might be **NULL**. If so, the format type is GUID_NULL. You should check the format type before dereferencing the format block.

If the method succeeds, call [MoFreeMediaType](https://learn.microsoft.com/windows/desktop/api/dmort/nf-dmort-mofreemediatype) to free the format block. (This function is also safe to call when the format block is **NULL**.)

To set the media type, call the [IMediaObject::SetOutputType](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediaobject-setoutputtype) method. Setting the media type on one stream can change another stream's preferred types. In fact, a stream might not have a preferred type until the type is set on another stream. For example, a decoder might not have a preferred output type until the input type is set. However, the DMO is not required to update its preferred types dynamically in this fashion. Thus, the types returned by this method are not guaranteed to be valid; they might fail when used in the **SetOutputType** method.

To test whether a particular media type is acceptable, call **SetOutputType** with the DMO_SET_TYPEF_TEST_ONLY flag.

To test whether the *dwTypeIndex* parameter is in range, set *pmt* to **NULL**. The method returns S_OK if the index is in range, or DMO_E_NO_MORE_ITEMS if the index is out of range.

## See also

[IMediaObject Interface](https://learn.microsoft.com/windows/desktop/api/mediaobj/nn-mediaobj-imediaobject)