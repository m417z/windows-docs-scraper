# DXGI_RECLAIM_RESOURCE_RESULTS enumeration

## Description

Specifies result flags for the [ReclaimResources1](https://learn.microsoft.com/windows/desktop/api/dxgi1_5/nf-dxgi1_5-idxgidevice4-reclaimresources1) method.

## Constants

### `DXGI_RECLAIM_RESOURCE_RESULT_OK:0`

The surface was successfully reclaimed and has valid content. This result is identical to the *false* value returned by the older [ReclaimResources](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgidevice2-reclaimresources) API.

### `DXGI_RECLAIM_RESOURCE_RESULT_DISCARDED:1`

The surface was reclaimed, but the old content was lost and must be regenerated. This result is identical to the *true* value returned by the older [ReclaimResources](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgidevice2-reclaimresources) API.

### `DXGI_RECLAIM_RESOURCE_RESULT_NOT_COMMITTED:2`

 Both the surface and its contents are lost and invalid. The surface must be
recreated and the content regenerated in order to be used. All future use of that resource is invalid. Attempts to bind it to the pipeline or map a resource which returns this value will never succeed, and the resource cannot be reclaimed again.

## See also

[DXGI Enumerations](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-enums)