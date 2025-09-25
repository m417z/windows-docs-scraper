# _D3DDDICB_RECLAIMALLOCATIONS structure

## Description

Describes video memory resources that are to be reclaimed and that the user-mode display driver previously offered for reuse. Used with the [pfnReclaimAllocationsCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_reclaimallocationscb) function.

## Members

### `pResources` [in]

A pointer to an array of handles to the resources that are to be reclaimed.

If **pResources** is not **NULL**, the **HandleList** member must be **NULL**.

**Note** If resources were created with the **D3D10_DDI_BIND_PRESENT** flag value set in *pCreateResource*->**BindFlags**, the driver must not use the **pResources** member to reclaim by resource handles. Instead, the driver must reclaim the resources by using allocation handles specified by **HandleList**.

### `HandleList` [in]

An array of D3DKMT_HANDLE data types that represent kernel-mode handles to the allocations that are to be reclaimed.

If **HandleList** is not **NULL**, the **pResources** member must be **NULL**.

### `pDiscarded` [out]

An array of Boolean values that specify whether each resource or allocation was discarded.

Each Boolean value in this array corresponds to a resource at the same index location in the arrays pointed to by **pResources** or **HandleList.**

The DirectX graphics kernel subsystem sets each Boolean value to **TRUE** if the corresponding resource was discarded, or to **FALSE** if not.

The value of **pDiscarded** can be **NULL**. If the driver sets it to **NULL**, the content of the resource or allocation can be assumed to be lost. If the driver does not need the content of the resource or allocation, setting **pDiscarded** to **NULL** might improve performance.

### `NumAllocations` [in]

The number of items in the **pResources**, **HandleList**, or **pDiscarded** members, whichever is not **NULL**.

## See also

[CreateResource(D3D11)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createresource)

[D3D10DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createresource)

[pfnReclaimAllocationsCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_reclaimallocationscb)