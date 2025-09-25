# DXGKDDI_DESTROYOVERLAY callback function

## Description

The *DxgkDdiDestroyOverlay* function disables overlay hardware and deletes the specified overlay handle.

## Parameters

### `hOverlay` [in]

A handle to the overlay to destroy. The display miniport driver's [DxgkDdiCreateOverlay](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createoverlay) function previously provided this handle to the Microsoft DirectX graphics kernel subsystem in the **hOverlay** member of the [DXGKARG_CREATEOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createoverlay) structure.

## Return value

*DxgkDdiDestroyOverlay* returns STATUS_SUCCESS, or an appropriate error result if overlay hardware is not successfully disabled.

## Remarks

*DxgkDdiDestroyOverlay* should be made pageable.

## See also

[DXGKARG_CREATEOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createoverlay)

[DxgkDdiCreateOverlay](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createoverlay)