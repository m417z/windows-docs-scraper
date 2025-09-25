# IDXGIDevice4::ReclaimResources1

## Description

Restores access to resources that were previously offered by calling [IDXGIDevice4::OfferResources1](https://learn.microsoft.com/windows/desktop/api/dxgi1_5/nf-dxgi1_5-idxgidevice4-offerresources1).

## Parameters

### `NumResources` [in]

Type: **UINT**

The number of resources in the *ppResources* argument and *pResults* argument arrays.

### `ppResources` [in]

Type: **IDXGIResource***

An array of pointers to [IDXGIResource](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiresource) interfaces for the resources to reclaim.

### `pResults` [out]

Type: **[DXGI_RECLAIM_RESOURCE_RESULTS](https://learn.microsoft.com/windows/desktop/api/dxgi1_5/ne-dxgi1_5-dxgi_reclaim_resource_results)***

A pointer to an array that receives [DXGI_RECLAIM_RESOURCE_RESULTS](https://learn.microsoft.com/windows/desktop/api/dxgi1_5/ne-dxgi1_5-dxgi_reclaim_resource_results) values. Each value in the array corresponds to a resource at the same index that the *ppResources* parameter specifies. The caller can pass in **NULL**, if the caller intends to fill the resources with new content regardless of whether the old content was discarded.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code, including E_INVALIDARG if the resources are invalid.

## Remarks

After you call [OfferResources1](https://learn.microsoft.com/windows/desktop/api/dxgi1_5/nf-dxgi1_5-idxgidevice4-offerresources1) to offer one or more resources, you must call **ReclaimResources1** before you can use those resources again.

To reclaim shared resources, call **ReclaimResources1** only on one of the sharing devices. To ensure exclusive access to the resources, you must use an [IDXGIKeyedMutex](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgikeyedmutex) object and then call **ReclaimResources1** only while you hold the mutex.

## See also

[IDXGIDevice4](https://learn.microsoft.com/windows/desktop/api/dxgi1_5/nn-dxgi1_5-idxgidevice4)

[ReclaimResources](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgidevice2-reclaimresources)