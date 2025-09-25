# DXGKDDI_RELEASESWIZZLINGRANGE callback function

## Description

The *DxgkDdiReleaseSwizzlingRange* function releases a swizzling range that the [DxgkDdiAcquireSwizzlingRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_acquireswizzlingrange) function previously set up.

## Parameters

### `hAdapter` [in]

A handle to a context block that is associated with a display adapter. The display miniport driver previously provided this handle to the Microsoft DirectX graphics kernel subsystem in the *MiniportDeviceContext* output parameter of the [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pReleaseSwizzlingRange` [in]

A pointer to a [DXGKARG_RELEASESWIZZLINGRANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_releaseswizzlingrange) structure that contains information for releasing the swizzling range.

## Return value

*DxgkDdiReleaseSwizzlingRange* returns STATUS_SUCCESS, or an appropriate error result if the swizzling range is not successfully released.

## Remarks

The *DxgkDdiReleaseSwizzlingRange* function is typically called when the specified allocation (that is, the **hAllocation** member of the [DXGKARG_RELEASESWIZZLINGRANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_releaseswizzlingrange) structure that the *pReleaseSwizzlingRange* parameter points to) is evicted or destroyed, or when another allocation requires the swizzling range that the **RangeId** member of DXGKARG_RELEASESWIZZLINGRANGE specifies.

If the specified allocation is currently associated with multiple swizzling ranges (through calls to the [DxgkDdiAcquireSwizzlingRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_acquireswizzlingrange) function), the display miniport driver should release only the swizzling range that the **RangeId** member of DXGKARG_RELEASESWIZZLINGRANGE specifies. If the display miniport driver releases all of the swizzling ranges that are associated with the allocation, random corruption in the allocation might result because an application might currently be using one or more of the swizzling ranges.

The driver must use memory-mapped I/O (MMIO) to set up a swizzling range. These swizzling-range accesses must not interfere with the execution of the GPU (that is, the GPU must not be idle when *DxgkDdiReleaseSwizzlingRange* is called).

All calls to *DxgkDdiReleaseSwizzlingRange* are serialized among themselves but not with any other device driver interface (DDI) function.

*DxgkDdiReleaseSwizzlingRange* should be made pageable.

## See also

[DXGKARG_RELEASESWIZZLINGRANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_releaseswizzlingrange)

[DxgkDdiAcquireSwizzlingRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_acquireswizzlingrange)

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)