# IMemAllocator::GetBuffer

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetBuffer** method retrieves a media sample that contains an empty buffer.

## Parameters

### `ppBuffer` [out]

Receives a pointer to the buffer's [IMediaSample](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediasample) interface. The caller must release the interface.

### `pStartTime` [in]

Pointer to the start time of the sample, or **NULL**.

### `pEndTime` [in]

Pointer to the ending time of the sample, or **NULL**.

### `dwFlags` [in]

Bitwise combination of zero or more of the following flags:

| Flag | Description |
| --- | --- |
| AM_GBF_NOTASYNCPOINT | This sample is not a synchronization point. Dynamic format changes are not allowed on this sample. When called on the Overlay Mixer or VMR, this flag implies that the buffer returned will contain an image that is identical to the last image delivered. |
| AM_GBF_PREVFRAMESKIPPED | This sample is the first after a discontinuity. (Only the video renderer uses this flag.) |
| AM_GBF_NOWAIT | Do not wait for a buffer to become available. |
| AM_GBF_NODDSURFACELOCK | Used with the [Video Mixing Renderer Filter 7](https://learn.microsoft.com/windows/desktop/DirectShow/video-mixing-renderer-filter-7) to request an unlocked DirectDraw surface. For more information, see [Working with Direct3D Render Targets](https://learn.microsoft.com/windows/desktop/DirectShow/working-with-direct3d-render-targets). |

## Return value

Returns an **HRESULT** value. Possible values include those shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **VFW_E_NOT_COMMITTED** | Allocator is decommitted. |
| **VFW_E_TIMEOUT** | Timed out. |

## Remarks

By default, this method blocks until a free sample is available or the allocator is decommitted. If the caller specifies the AM_GBF_NOWAIT flag and no sample is available, the allocator can return immediately with a return value of VFW_E_TIMEOUT. However, allocators are not required to support this flag.

The sample returned in *ppBuffer* has a valid buffer pointer. The caller is responsible for setting any other properties on the sample, such as the time stamps, the media times, or the sync-point property. (For more information, see [IMediaSample](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediasample).)

The *pStartTime* and *pEndTime* parameters are not applied to the sample. The allocator might use these values to determine which buffer it retrieves. For example, the [Video Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/video-renderer-filter) filter uses these values to synchronize switching between DirectDraw surfaces. To set the time stamp on the sample, call the [IMediaSample::SetTime](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediasample-settime) method.

You must call the [IMemAllocator::Commit](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imemallocator-commit) method before calling this method. This method fails after the [IMemAllocator::Decommit](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imemallocator-decommit) method is called.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMemAllocator Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imemallocator)