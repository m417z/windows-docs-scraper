# IMFVideoSampleAllocatorCallback::GetFreeSampleCount

## Description

Gets the number of video samples that are currently available for use.

## Parameters

### `plSamples` [out]

Receives the number of available samples.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To get a video sample from the allocator, call the [IMFVideoSampleAllocator::AllocateSample](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfvideosampleallocator-allocatesample) method. The **AllocateSample** method removes a sample from the sample pool and returns it to the caller. When a sample is released, it returns to the pool. The **GetFreeSampleCount** method returns the count of samples that remain in the sample pool.

## See also

[IMFVideoSampleAllocatorCallback](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfvideosampleallocatorcallback)