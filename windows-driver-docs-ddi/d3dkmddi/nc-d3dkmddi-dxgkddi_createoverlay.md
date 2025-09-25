# DXGKDDI_CREATEOVERLAY callback function

## Description

The *DxgkDdiCreateOverlay* function enables the overlay hardware if the hardware is capable.

## Parameters

### `hAdapter` [in]

A handle to a context block that is associated with a display adapter. The display miniport driver previously provided this handle to the Microsoft DirectX graphics kernel subsystem in the *MiniportDeviceContext* output parameter of the [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pCreateOverlay` [in/out]

A pointer to a [DXGKARG_CREATEOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createoverlay) structure that describes the overlay.

## Return value

*DxgkDdiCreateOverlay* returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|DxgkDdiCreateOverlay successfully created the overlay.|
|STATUS_INVALID_PARAMETER|Parameters that were passed to DxgkDdiCreateOverlay contained errors that prevented it from completing.|
|STATUS_NO_MEMORY|DxgkDdiCreateOverlay could not allocate memory that was required for it to complete.|
|STATUS_INSUFFICIENT_RESOURCES|DxgkDdiCreateOverlay could not complete because insufficient bandwidth was available or the requested overlay hardware could not complete the task.|
|STATUS_GRAPHICS_DRIVER_MISMATCH|The display miniport driver is not compatible with the user-mode display driver that initiated the call to DxgkDdiCreateOverlay.|

## Remarks

*DxgkDdiCreateOverlay* should be made pageable.

## See also

[DXGKARG_CREATEOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createoverlay)

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)