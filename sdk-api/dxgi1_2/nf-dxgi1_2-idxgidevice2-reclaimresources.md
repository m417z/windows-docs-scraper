# IDXGIDevice2::ReclaimResources

## Description

Restores access to resources that were previously offered by calling [IDXGIDevice2::OfferResources](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgidevice2-offerresources).

## Parameters

### `NumResources` [in]

The number of resources in the *ppResources* argument and *pDiscarded* argument arrays.

### `ppResources` [in]

An array of pointers to [IDXGIResource](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiresource) interfaces for the resources to reclaim.

### `pDiscarded` [out, optional]

A pointer to an array that receives Boolean values. Each value in the array corresponds to a resource at the same index that the *ppResources* parameter specifies. The runtime sets each Boolean value to TRUE if the corresponding resource’s content was discarded and is now undefined, or to FALSE if the corresponding resource’s old content is still intact. The caller can pass in **NULL**, if the caller intends to fill the resources with new content regardless of whether the old content was discarded.

## Return value

**ReclaimResources** returns:

* S_OK if resources were successfully reclaimed
* E_INVALIDARG if the resources are invalid

## Remarks

After you call [IDXGIDevice2::OfferResources](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgidevice2-offerresources) to offer one or more resources, you must call **ReclaimResources** before you can use those resources again. You must check the values in the array at *pDiscarded* to determine whether each resource’s content was discarded. If a resource’s content was discarded while it was offered, its current content is undefined. Therefore, you must overwrite the resource’s content before you use the resource.

To reclaim shared resources, call **ReclaimResources** only on one of the sharing devices. To ensure exclusive access to the resources, you must use an [IDXGIKeyedMutex](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgikeyedmutex) object and then call **ReclaimResources** only while you hold the mutex.

**Platform Update for Windows 7:** The runtime validates that **ReclaimResources** is used correctly on non-shared resources but doesn't perform the intended functionality. For more info about the Platform Update for Windows 7, see [Platform Update for Windows 7](https://learn.microsoft.com/windows/desktop/direct3darticles/platform-update-for-windows-7).

## See also

[IDXGIDevice2](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgidevice2)

[IDXGIDevice2::OfferResources](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgidevice2-offerresources)