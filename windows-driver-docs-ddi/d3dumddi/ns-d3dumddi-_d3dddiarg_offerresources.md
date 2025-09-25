# _D3DDDIARG_OFFERRESOURCES structure

## Description

 Describes video memory resources that the user-mode display driver offers for reuse. Used with the [OfferResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_offerresources) function.

## Members

### `pResources` [in]

A pointer to an array of handles to the video memory resources that the driver offers.

### `Resources` [in]

The number of elements in the array pointed to by **pResources**.

### `Priority` [in]

A value of type [D3DDDI_OFFER_PRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_offer_priority) that indicates the importance of the resources pointed to by **pResources**.

## Remarks

This structure is pointed to by the *pData* parameter of the [OfferResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_offerresources) routine.

## See also

[D3DDDI_OFFER_PRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_offer_priority)

[OfferResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_offerresources)