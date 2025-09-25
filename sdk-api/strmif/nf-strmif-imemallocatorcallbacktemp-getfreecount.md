# IMemAllocatorCallbackTemp::GetFreeCount

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetFreeCount` method returns the number of free media samples. This number equals the total number of media samples minus the number of samples that are currently held by filters.

## Parameters

### `plBuffersFree` [out]

Pointer to a variable that receives the number of free media samples.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_POINTER** | **NULL** pointer argument |
| **S_OK** | Success |

## Remarks

A filter holds a sample by keeping a reference count on it. It releases the sample by releasing the reference count.

Until the allocator is committed, the samples are not guaranteed to be allocated.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMemAllocatorCallbackTemp Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imemallocatorcallbacktemp)