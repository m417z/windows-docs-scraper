# _D3DKMT_OFFERALLOCATIONS structure

## Description

Defines the video memory allocations that the driver offers for reuse. Used with the [D3DKMTOfferAllocations](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtofferallocations) function.

## Members

### `hDevice` [in]

A D3DKMT_HANDLE data type that represents a kernel-mode handle to the device that created the allocations.

### `pResources` [in]

An array of Direct3D runtime handles to resources to offer.

If the user-mode driver uses the array specified by **HandleList** to offer a list of allocations, it must set **pResources** to **NULL**. Conversely, if the driver uses the array specified by **pResources** to offer a list of resources, it must set **HandleList** to **NULL**.

### `HandleList` [in]

An array of D3DKMT_HANDLE data types that represent kernel-mode handles to allocations to offer.

If resources were created with the **D3D10_DDI_BIND_PRESENT** flag value set in *pCreateResource*->**BindFlags**, offer the resources by their allocation handles, not by their resource handles.

### `NumAllocations` [in]

The number of items in the **pResources** or **HandleList** members, whichever is not **NULL**.

### `Priority` [in]

The priority, of type [D3DKMT_OFFER_PRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_d3dkmt_offer_priority), with which to offer the allocations for reuse.

### `Flags`

Flag options.

## See also

[D3DKMTOfferAllocations](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtofferallocations)

[D3DKMT_OFFER_PRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_d3dkmt_offer_priority)