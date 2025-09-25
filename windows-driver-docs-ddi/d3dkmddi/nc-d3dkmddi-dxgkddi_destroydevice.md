# DXGKDDI_DESTROYDEVICE callback function

## Description

The *DxgkDdiDestroyDevice* function destroys a graphics context device.

## Parameters

### `hDevice` [in]

A handle to the graphics context device that *DxgkDdiDestroyDevice* will destroy. The display miniport driver's [DxgkDdiCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdevice) function previously provided this handle to the Microsoft DirectX graphics kernel subsystem in the **hDevice** member of the [DXGKARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createdevice) structure.

## Return value

*DxgkDdiDestroyDevice* returns STATUS_SUCCESS, or an appropriate error result if the graphics context device is not successfully destroyed.

## Remarks

The DirectX graphics kernel subsystem calls the display miniport driver's *DxgkDdiDestroyDevice* function to destroy a graphics context device that the driver's [DxgkDdiCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdevice) function created. *DxgkDdiDestroyDevice* should free all of the resources that were allocated for the device and clean up any internal tracking data structures.

*DxgkDdiDestroyDevice* should be made pageable.

## See also

[DXGKARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createdevice)

[DxgkDdiCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdevice)