# IMemAllocator::SetProperties

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetProperties` method specifies the number of buffers to allocate and the size of each buffer.

## Parameters

### `pRequest`

Pointer to an [ALLOCATOR_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-allocator_properties) structure that contains the buffer requirements.

### `pActual`

Pointer to an **ALLOCATOR_PROPERTIES** structure that receives the actual buffer properties.

## Return value

Returns an **HRESULT** value. Possible values include those shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | **NULL** pointer argument. |
| **VFW_E_ALREADY_COMMITTED** | Cannot change allocated memory while the filter is active. |
| **VFW_E_BADALIGN** | An invalid alignment was specified. |
| **VFW_E_BUFFERS_OUTSTANDING** | One or more buffers are still active. |

## Remarks

This method specifies the buffer requirements, but does not allocate any buffers. Call the [IMemAllocator::Commit](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imemallocator-commit) method to allocate buffers.

The caller allocates two ALLOCATOR_PROPERTIES structures. The *pRequest* parameter contains the caller's buffer requirements, including the number of buffers and the size of each buffer. When the method returns, the *pActual* parameter contains the actual buffer properties, as set by the allocator.

When this method is called, the allocator must not be committed or have outstanding buffers.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMemAllocator Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imemallocator)