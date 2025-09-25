# DXGKDDI_GETSCANLINE callback function

## Description

The *DxgkDdiGetScanLine* function determines whether the specified video present target of a video present network (VidPN) is in vertical blanking mode and retrieves the current scan line.

## Parameters

### `hAdapter` [in]

A handle to a context block that is associated with a display adapter. The display miniport driver previously provided this handle to the Microsoft DirectX graphics kernel subsystem in the *MiniportDeviceContext* output parameter of the [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pGetScanLine` [in/out]

A pointer to a [DXGKARG_GETSCANLINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_getscanline) structure that contains the vertical blanking status of a video present target.

## Return value

*DxgkDdiGetScanLine* returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in *Ntstatus.h*.

## Remarks

*DxgkDdiGetScanLine* should be made pageable.

## See also

[DXGKARG_GETSCANLINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_getscanline)

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)