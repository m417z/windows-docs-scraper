# _DXGI_DDI_ARG_OFFERRESOURCES structure

## Description

Describes video memory resources that the user-mode display driver offers for reuse. Used with the [pfnOfferResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_offerresources) function. Used with the [pfnReclaimResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi1_2_ddi_base_functions) function by Windows Display Driver Model (WDDM) 1.2 and later user-mode display drivers.

## Members

### `hDevice` [in]

A handle to the display device (graphics context) on which the driver offers resources for reuse.

The Direct3D runtime passed this handle to the driver in the **hDrvDevice** member of the [D3D10DDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createdevice) structure when it created the device by calling the [CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice) routine.

### `pResources` [in]

A pointer to an array of handles to the video memory resources that the driver offers.

### `Resources` [in]

The number of elements in the array pointed to by **pResources**.

### `Priority` [in]

A value of type [D3DDDI_OFFER_PRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_offer_priority) that indicates the importance of the resources pointed to by **pResources**.

## See also

[CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice)

[D3D10DDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createdevice)

[D3DDDI_OFFER_PRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_offer_priority)

[pfnOfferResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_offerresources)