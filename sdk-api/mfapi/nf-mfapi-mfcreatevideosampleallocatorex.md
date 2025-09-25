# MFCreateVideoSampleAllocatorEx function

## Description

Creates an object that allocates video samples that are compatible with Microsoft DirectX Graphics Infrastructure (DXGI).

## Parameters

### `riid` [in]

The identifier of the interface to retrieve. Specify one of the following values.

| Value | Meaning |
| --- | --- |
| ****IID_IUnknown**** | Retrieve an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) pointer. |
| ****IID_IMFVideoSampleAllocator**** | Retrieve an [IMFVideoSampleAllocator](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfvideosampleallocator) pointer. |
| ****IID_IMFVideoSampleAllocatorEx**** | Retrieve an [IMFVideoSampleAllocatorEx](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfvideosampleallocatorex) pointer. |
| ****IID_IMFVideoSampleAllocatorCallback**** | Retrieve an [IMFVideoSampleAllocatorCallback](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfvideosampleallocatorcallback) pointer. |

### `ppSampleAllocator` [out]

Receives a pointer to the requested interface. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function creates an allocator for DXGI video surfaces. The buffers created by this allocator expose the [IMFDXGIBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfdxgibuffer) interface. To create an allocator for Microsoft Direct3D 9 video surfaces, call [MFCreateVideoSampleAllocator](https://learn.microsoft.com/windows/desktop/api/evr/nc-evr-mfcreatevideosampleallocator).

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)