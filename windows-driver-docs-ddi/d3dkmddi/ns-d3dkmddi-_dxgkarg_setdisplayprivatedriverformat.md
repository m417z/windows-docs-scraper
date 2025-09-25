# _DXGKARG_SETDISPLAYPRIVATEDRIVERFORMAT structure

## Description

The DXGKARG_SETDISPLAYPRIVATEDRIVERFORMAT structure describes how to set the private-format attribute for a video present source.

## Members

### `VidPnSourceId` [in]

The zero-based identification number that identifies the video present source in a path of a video present network (VidPN) topology to change the private driver format attribute of.

### `PrimaryAllocation` [in]

If nonzero, handle to the allocation for the current primary surface for the video present source that the **VidPnSourceId** member specifies. The display miniport driver returns this handle when its [DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation) function is called to create the primary surface. This handle is returned in the **hAllocation** member of the [DXGK_ALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfo) structure of the primary-surface element in the **pAllocationInfo** array member of the [DXGKARG_CREATEALLOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createallocation) structure. This handle is a pointer to a private driver data structure that contains information about the primary allocation.

If **PrimaryAllocation** is set to zero, no primary surface is currently associated with the video present source. In this situation, the video present source is not visible.

### `PrivateDriverFormatAttribute` [in]

A UINT value that specifies the private-format attribute to set for the video present source that the **VidPnSourceId** member specifies.

## See also

[DXGKARG_CREATEALLOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createallocation)

[DXGK_ALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfo)

[DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation)

[DxgkDdiSetDisplayPrivateDriverFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setdisplayprivatedriverformat)