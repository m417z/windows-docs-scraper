# _D3DDDICB_OFFERALLOCATIONS structure

## Description

Defines the video memory allocations that the driver offers for reuse. Used with the [pfnOfferAllocationsCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_offerallocationscb) function.

## Members

### `pResources` [in]

An array of Direct3D runtime handles to resources to offer.

If the user-mode driver uses the array specified by **HandleList** to offer a list of allocations, it must set **pResources** to **NULL**. Conversely, if the driver uses the array specified by **pResources** to offer a list of resources, it must set **HandleList** to **NULL**.

### `HandleList` [in]

An array of D3DKMT_HANDLE data types that represent kernel-mode handles to allocations to offer.

If resources were created with the **D3D10_DDI_BIND_PRESENT** flag value set in *pCreateResource*->**BindFlags**, offer the resources by their allocation handles, not by their resource handles.

### `NumAllocations` [in]

The number of items in the **pResources** or **HandleList** members, whichever is not **NULL**.

### `Priority` [in]

The priority, of type [D3DDDI_OFFER_PRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_offer_priority), with which to offer the allocations for reuse.

**Note** Do not set this member to a value of **D3DDDI_OFFER_PRIORITY_NONE**.

## See also

[CreateResource(D3D11)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createresource)

[D3DDDI_OFFER_PRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_offer_priority)

[pfnOfferAllocationsCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_offerallocationscb)