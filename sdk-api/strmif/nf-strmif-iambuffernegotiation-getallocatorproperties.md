# IAMBufferNegotiation::GetAllocatorProperties

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetAllocatorProperties` method retrieves the allocator properties that the pin is using.

## Parameters

### `pprop` [out]

Pointer to an [ALLOCATOR_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-allocator_properties) structure, allocated by the caller, that receives the allocator properties.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | **NULL** pointer argument. |
| **VFW_E_NOT_CONNECTED** | Pin is not connected. |

## Remarks

Call this method after the pins connect, to find out the allocator properties that were chosen.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMBufferNegotiation Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iambuffernegotiation)