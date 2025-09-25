# DXGI_OFFER_RESOURCE_PRIORITY enumeration

## Description

Identifies the importance of a resource’s content when you call the [IDXGIDevice2::OfferResources](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgidevice2-offerresources) method to offer the resource.

## Constants

### `DXGI_OFFER_RESOURCE_PRIORITY_LOW:1`

The resource is low priority. The operating system discards a low priority resource before other offered resources with higher priority. It is a good programming practice to mark a resource as low priority if it has no useful content.

### `DXGI_OFFER_RESOURCE_PRIORITY_NORMAL`

The resource is normal priority. You mark a resource as normal priority if it has content that is easy to regenerate.

### `DXGI_OFFER_RESOURCE_PRIORITY_HIGH`

The resource is high priority. The operating system discards other offered resources with lower priority before it discards a high priority resource. You mark a resource as high priority if it has useful content that is difficult to regenerate.

## Remarks

Priority determines how likely the operating system is to discard an offered resource. Resources offered with lower priority are discarded first.

## See also

[DXGI Enumerations](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-enums)

[IDXGIDevice2::OfferResources](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgidevice2-offerresources)

[IDXGIDevice2::ReclaimResource](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgidevice2-reclaimresources)