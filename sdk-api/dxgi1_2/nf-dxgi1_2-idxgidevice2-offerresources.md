# IDXGIDevice2::OfferResources

## Description

Allows the operating system to free the video memory of resources by discarding their content.

## Parameters

### `NumResources` [in]

The number of resources in the *ppResources* argument array.

### `ppResources` [in]

An array of pointers to [IDXGIResource](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiresource) interfaces for the resources to offer.

### `Priority` [in]

A [DXGI_OFFER_RESOURCE_PRIORITY](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ne-dxgi1_2-dxgi_offer_resource_priority)-typed value that indicates how valuable data is.

## Return value

**OfferResources** returns:

* S_OK if resources were successfully offered
* E_INVALIDARG if a resource in the array or the priority is invalid

## Remarks

The priority value that the *Priority* parameter specifies describes how valuable the caller considers the content to be. The operating system uses the priority value to discard resources in order of priority. The operating system discards a resource that is offered with low priority before it discards a resource that is offered with a higher priority.

If you call **OfferResources** to offer a resource while the resource is bound to the pipeline, the resource is unbound. You cannot call **OfferResources** on a resource that is mapped. After you offer a resource, the resource cannot be mapped or bound to the pipeline until you call the [IDXGIDevice2::ReclaimResource](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgidevice2-reclaimresources) method to reclaim the resource. You cannot call **OfferResources** to offer immutable resources.

To offer shared resources, call **OfferResources** on only one of the sharing devices. To ensure exclusive access to the resources, you must use an [IDXGIKeyedMutex](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgikeyedmutex) object and then call **OfferResources** only while you hold the mutex. In fact, you can't offer shared resources unless you use **IDXGIKeyedMutex** because offering shared resources without using **IDXGIKeyedMutex** isn't supported.

**Note** The user mode display driver might not immediately offer the resources that you specified in a call to **OfferResources**. The driver can postpone offering them until the next call to [IDXGISwapChain::Present](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-present), [IDXGISwapChain1::Present1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgiswapchain1-present1), or [ID3D11DeviceContext::Flush](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-flush).

**Platform Update for Windows 7:** The runtime validates that **OfferResources** is used correctly on non-shared resources but doesn't perform the intended functionality. For more info about the Platform Update for Windows 7, see [Platform Update for Windows 7](https://learn.microsoft.com/windows/desktop/direct3darticles/platform-update-for-windows-7).

## See also

[IDXGIDevice2](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgidevice2)

[IDXGIDevice2::ReclaimResource](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgidevice2-reclaimresources)