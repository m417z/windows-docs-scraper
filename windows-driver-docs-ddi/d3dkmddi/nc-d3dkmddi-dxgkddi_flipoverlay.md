# DXGKDDI_FLIPOVERLAY callback function

## Description

The *DxgkDdiFlipOverlay* function displays a new allocation by using the specified overlay.

## Parameters

### `hOverlay` [in]

A handle to the overlay to be flipped. The display miniport driver's [DxgkDdiCreateOverlay](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createoverlay) function previously provided this handle to the Microsoft DirectX graphics kernel subsystem in the **hOverlay** member of the [DXGKARG_CREATEOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createoverlay) structure.

### `pFlipOverlay` [in]

A pointer to a [DXGKARG_FLIPOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_flipoverlay) structure that describes the new allocation to display by using the overlay.

## Return value

*DxgkDdiFlipOverlay* returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|DxgkDdiFlipOverlay successfully displays the new allocation.|
|STATUS_INVALID_PARAMETER|Parameters that were passed to DxgkDdiFlipOverlay contained errors that prevented it from completing.|
|STATUS_NO_MEMORY|DxgkDdiFlipOverlay could not allocate memory that was required for it to complete.|
|STATUS_GRAPHICS_DRIVER_MISMATCH|The display miniport driver is not compatible with the user-mode display driver that initiated the call to DxgkDdiFlipOverlay.|

## Remarks

*DxgkDdiFlipOverlay* should be made pageable.

## See also

[DXGKARG_CREATEOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createoverlay)

[DXGKARG_FLIPOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_flipoverlay)

[DxgkDdiCreateOverlay](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createoverlay)