# _D3DDDIARG_RECLAIMRESOURCES structure

## Description

Describes video memory resources that are to be reclaimed and that the user-mode display driver previously offered for reuse. Used with the [ReclaimResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_reclaimresources) function.

## Members

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

[CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice)

[ReclaimResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_reclaimresources)