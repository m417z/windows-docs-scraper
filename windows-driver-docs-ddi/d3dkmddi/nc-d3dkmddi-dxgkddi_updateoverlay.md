# DXGKDDI_UPDATEOVERLAY callback function

## Description

The *DxgkDdiUpdateOverlay* function modifies the overlay hardware.

## Parameters

### `hOverlay` [in]

A handle to the overlay to modify. The display miniport driver's [DxgkDdiCreateOverlay](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createoverlay) function previously provided this handle to the Microsoft DirectX graphics kernel subsystem in the **hOverlay** member of the [DXGKARG_CREATEOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createoverlay) structure that *pCreateOverlay* points to.

### `pUpdateOverlay` [in]

A pointer to a [DXGKARG_UPDATEOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_updateoverlay) structure that describes how to modify the overlay hardware.

## Return value

*DxgkDdiUpdateOverlay* returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|DxgkDdiUpdateOverlay successfully modified the overlay.|
|STATUS_INVALID_PARAMETER|Parameters that were passed to DxgkDdiUpdateOverlay contained errors that prevented it from completing.|
|STATUS_NO_MEMORY|DxgkDdiUpdateOverlay could not allocate memory that was required for it to complete.|
|STATUS_INSUFFICIENT_RESOURCES|DxgkDdiUpdateOverlay could not complete because insufficient bandwidth was available or the requested overlay hardware could not complete the task.|
|STATUS_GRAPHICS_DRIVER_MISMATCH|The display miniport driver is not compatible with the user-mode display driver that initiated the call to DxgkDdiUpdateOverlay.|

## Remarks

*DxgkDdiUpdateOverlay* should be made pageable.

## See also

[DXGKARG_CREATEOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createoverlay)

[DXGKARG_UPDATEOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_updateoverlay)

[DxgkDdiCreateOverlay](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createoverlay)