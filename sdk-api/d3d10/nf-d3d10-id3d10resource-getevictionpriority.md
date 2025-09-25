# ID3D10Resource::GetEvictionPriority

## Description

Get the eviction priority of a resource.

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

One of the following values, which specifies the eviction priority for the resource:

* DXGI_RESOURCE_PRIORITY_MINIMUM
* DXGI_RESOURCE_PRIORITY_LOW
* DXGI_RESOURCE_PRIORITY_NORMAL
* DXGI_RESOURCE_PRIORITY_HIGH
* DXGI_RESOURCE_PRIORITY_MAXIMUM

## Remarks

This method is a wrapper for [GetEvictionPriority](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiresource-getevictionpriority) and is provided in the [ID3D10Resource Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10resource) interface for convenience.

## See also

[ID3D10Resource Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10resource)