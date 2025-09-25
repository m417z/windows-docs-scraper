# IMFVideoSampleAllocatorEx::InitializeSampleAllocatorEx

## Description

Initializes the video sample allocator object.

## Parameters

### `cInitialSamples` [in]

The initial number of samples to allocate.

### `cMaximumSamples` [in]

The maximum number of samples to allocate.

### `pAttributes` [in]

A pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface. You can use this interface to configure the allocator. Currently, the following configuration attributes are defined:

* [MF_SA_BUFFERS_PER_SAMPLE](https://learn.microsoft.com/windows/desktop/medfound/mf-sa-buffers-per-sample)
* [MF_SA_D3D11_BINDFLAGS](https://learn.microsoft.com/windows/desktop/medfound/mf-sa-d3d11-bindflags)
* [MF_SA_D3D11_USAGE](https://learn.microsoft.com/windows/desktop/medfound/mf-sa-d3d11-usage)
* [MF_SA_D3D11_SHARED](https://learn.microsoft.com/windows/desktop/medfound/mf-sa-d3d11-shared)
* [MF_SA_D3D11_SHARED_WITHOUT_MUTEX](https://learn.microsoft.com/windows/desktop/medfound/mf-sa-d3d11-shared-without-mutex)

### `pMediaType` [in]

A pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface of a media type that describes the video format.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFVideoSampleAllocatorEx](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfvideosampleallocatorex)