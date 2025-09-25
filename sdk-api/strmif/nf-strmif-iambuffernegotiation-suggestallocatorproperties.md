# IAMBufferNegotiation::SuggestAllocatorProperties

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SuggestAllocatorProperties` method informs the pin of the application's preferred allocator properties. Call this method before the pin connects.

## Parameters

### `pprop` [in]

Pointer to an [ALLOCATOR_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-allocator_properties) structure that contains the requested properties. A negative value for any member indicates that the pin should use its default setting for that property.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_FAIL** | Failure. |
| **E_POINTER** | **NULL** pointer argument. |
| **VFW_E_ALREADY_CONNECTED** | Pin is already connected. |

## Remarks

If both pins in the connection expose the [IAMBufferNegotiation](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iambuffernegotiation) interface, call this method on each pin, to ensure that one pin does not override the other.

To request a particular number of buffers, set the **cBuffers** member of the **ALLOCATOR_PROPERTIES** structure. To request a particular buffer size, set the **cbBuffer** member. An application typically should not specify the alignment or prefix. If the number of buffers or size of each buffer is too small, the filter graph might drop samples.

#### Examples

| C++ |
| --- |
| ``` ALLOCATOR_PROPERTIES AllocProp; AllocProp.cbAlign = -1;  // -1 means no preference. AllocProp.cbBuffer = dwBytesPerSec *  dwLatencyInMilliseconds / 1000; AllocProp.cbPrefix = -1; AllocProp.cBuffers = -1; pIAMBufferNegotiation->SuggestAllocatorProperties(&AllocProp); ``` |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMBufferNegotiation Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iambuffernegotiation)