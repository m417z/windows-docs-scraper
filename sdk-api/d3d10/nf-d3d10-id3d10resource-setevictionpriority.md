# ID3D10Resource::SetEvictionPriority

## Description

Set the eviction priority of a resource.

## Parameters

### `EvictionPriority` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Eviction priority for the resource, which is one of the following values:

* DXGI_RESOURCE_PRIORITY_MINIMUM
* DXGI_RESOURCE_PRIORITY_LOW
* DXGI_RESOURCE_PRIORITY_NORMAL
* DXGI_RESOURCE_PRIORITY_HIGH
* DXGI_RESOURCE_PRIORITY_MAXIMUM

## Remarks

Resource priorities determine which resource to evict from video memory when the system has run out of video memory. The resource will not be lost; it will be removed from video memory and placed into system memory, or possibly placed onto the hard drive. The resource will be loaded back into video memory when it is required.

A resource that is set to the maximum priority, DXGI_RESOURCE_PRIORITY_MAXIMUM, is only evicted if there is no other way of resolving the incoming memory request. The Windows Display Driver Model (WDDM) tries to split an incoming memory request to its minimum size and evict lower-priority resources before evicting a resource with maximum priority.

Changing the priorities of resources should be done carefully. The wrong eviction priorities could be a detriment to performance rather than an improvement. See [QueryResourceResidency](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgidevice-queryresourceresidency) for additional information.

This method is a wrapper for [SetEvictionPriority](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiresource-setevictionpriority) and is provided in the [ID3D10Resource Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10resource) interface for convenience.

## See also

[ID3D10Resource Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10resource)