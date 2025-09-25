# _DXGKARG_OPENALLOCATION structure

## Description

The DXGKARG_OPENALLOCATION structure describes allocations that the display miniport driver should open.

## Members

### `NumAllocations` [in]

The number of elements in the array that the **pOpenAllocation** member specifies, which represents the number of device-specific allocations to open.

### `pOpenAllocation` [in/out]

An array of [DXGK_OPENALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_openallocationinfo) structures for the allocations to open.

### `pPrivateDriverData` [in]

A pointer to a block of private data that is passed from the user-mode display driver to the display miniport driver. This block of private data is the same resource-specific data that is passed in the **pPrivateDriverData** member of the [DXGKARG_CREATEALLOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createallocation) structure in the call to the [DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation) function. The display miniport driver cannot modify this block of private data.

### `PrivateDriverSize` [in]

The size, in bytes, of the block of private data that **pPrivateDriverData** points to.

### `Flags` [in]

A [DXGK_OPENALLOCATIONFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_openallocationflags) structure that identifies the operation to perform for allocations.

### `SubresourceIndex` [in]

Supported beginning with Windows 8.

An index into the resource for the render target surface.

The operating system specifies this member only if the display miniport driver supports [GDI Hardware Acceleration](https://learn.microsoft.com/windows-hardware/drivers/display/gdi-hardware-acceleration). Specifically, the display miniport driver must implement the [DxgkDdiRenderKm](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_renderkm) function and must create the device with the **GdiDevice** member set in [DXGKARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createdevice).**Flags**.

If the value of **SubresourceIndex** is greater than the number of subresources in the allocation, the display miniport driver should return an error.

### `SubresourceOffset` [out]

Supported beginning with Windows 8.

The offset, in bytes, from the start of the allocation to the start of the subresource.

### `Pitch` [out]

Supported beginning with Windows 8.

The pitch, in bytes, of the allocation—that is, the distance, in bytes, to the start of the next row.

## See also

[DXGKARG_CREATEALLOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createallocation)

[DXGK_OPENALLOCATIONFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_openallocationflags)

[DXGK_OPENALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_openallocationinfo)

[DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation)

[DxgkDdiOpenAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_openallocationinfo)