# IMFVideoSampleAllocatorNotify::NotifyRelease

## Description

Called when a video sample is returned to the allocator.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To get a video sample from the allocator, call the [IMFVideoSampleAllocator::AllocateSample](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfvideosampleallocator-allocatesample) method. When the sample is released and then returned to the pool of available samples, the allocator invokes the **NotifyRelease** method.

## See also

[IMFVideoSampleAllocatorNotify](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfvideosampleallocatornotify)

[IMFVideoSampleAllocatorNotifyEx](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfvideosampleallocatornotifyex)