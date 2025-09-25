# D3D12DDIARG_OFFERRESOURCES structure

## Description

Describes video memory resources that the user-mode display driver offers for reuse.

## Members

### `NumObjects`

The number of elements in the array pointed to by *pObjects*.

### `pObjects`

A pointer to an array of handles to the video memory objects that the driver offers.

### `Priority`

A value of type [D3DDDI_OFFER_PRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_offer_priority) that indicates the importance of the resources pointed to by *pObjects*.

### `Reserved`

Reserved.

## Remarks

## See also