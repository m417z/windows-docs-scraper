# IMFVideoSampleAllocatorCallback::SetCallback

## Description

Sets the callback object that receives notification whenever a video sample is returned to the allocator.

## Parameters

### `pNotify` [in]

A pointer to the [IMFVideoSampleAllocatorNotify](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfvideosampleallocatornotify) interface that receives notification, or **NULL** to remove the callback.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To get a video sample from the allocator, call the [IMFVideoSampleAllocator::AllocateSample](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfvideosampleallocator-allocatesample) method. When the sample is released, it returns to the pool of available samples. When this happens, the allocator invokes the [IMFVideoSampleAllocatorNotify::NotifyRelease](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfvideosampleallocatornotify-notifyrelease) callback.

The allocator holds at most one callback pointer. Calling this method again replaces the previous callback pointer.

## See also

[IMFVideoSampleAllocatorCallback](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfvideosampleallocatorcallback)