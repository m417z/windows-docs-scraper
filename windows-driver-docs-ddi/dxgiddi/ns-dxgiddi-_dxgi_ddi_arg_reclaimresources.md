# _DXGI_DDI_ARG_RECLAIMRESOURCES structure

## Description

Describes video memory resources that are to be reclaimed and that the user-mode display driver previously offered for reuse. Used with the [pfnReclaimResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi1_2_ddi_base_functions) function by Windows Display Driver Model (WDDM) 1.2 and later user-mode display drivers.

## Members

### `hDevice` [in]

A handle to the display device (graphics context) on which the driver offers resources for reuse.

The Direct3D runtime passed this handle to the driver in the **hDrvDevice** member of the [D3D10DDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createdevice) structure when it created the device by calling the [CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice) routine.

### `pResources` [in]

A pointer to an array of handles to the resources that are to be reclaimed.

### `pDiscarded` [out]

An optional array of Boolean values that specify whether each resource or allocation was discarded.

Each Boolean value in this array corresponds to a resource at the same index location in the structure pointed to by **pResources**.

The driver sets each Boolean value to **TRUE** if the corresponding resource was discarded, or to **FALSE** if not.

If **pDiscarded** is **NULL**, the driver can ignore it.

### `Resources` [in]

The number of elements in the arrays pointed to by **pResources** and **pDiscarded**.

## See also

[pfnReclaimResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi1_2_ddi_base_functions)