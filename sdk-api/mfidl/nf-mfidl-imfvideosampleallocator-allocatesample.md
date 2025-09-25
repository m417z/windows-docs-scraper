# IMFVideoSampleAllocator::AllocateSample

## Description

Gets a video sample from the allocator.

## Parameters

### `ppSample` [out]

Receives a pointer to the [IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample) interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_NOT_INITIALIZED** | The allocator was not initialized. Call [IMFVideoSampleAllocator::InitializeSampleAllocator](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfvideosampleallocator-initializesampleallocator) or [InitializeSampleAllocatorEx::InitializeSampleAllocatorEx](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfvideosampleallocatorex-initializesampleallocatorex). |
| **MF_E_SAMPLEALLOCATOR_EMPTY** | No samples are available. |

## See also

[IMFVideoSampleAllocator](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfvideosampleallocator)