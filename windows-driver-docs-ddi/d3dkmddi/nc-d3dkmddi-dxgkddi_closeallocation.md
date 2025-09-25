# DXGKDDI_CLOSEALLOCATION callback function

## Description

The *DxgkDdiCloseAllocation* function unbinds device-specific allocations that the [DxgkDdiOpenAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_openallocationinfo) function created.

## Parameters

### `hDevice` [in]

A handle to the graphics context device that allocations are unbound from. The display miniport driver's [DxgkDdiCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdevice) function previously provided this handle to the Microsoft DirectX graphics kernel subsystem in the **hDevice** member of the [DXGKARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createdevice) structure.

### `pCloseAllocation` [in]

A pointer to a [DXGKARG_CLOSEALLOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_closeallocation) structure that contains information about unbinding allocations.

## Return value

*DxgkDdiCloseAllocation* returns STATUS_SUCCESS, or an appropriate error result if the allocations are not successfully unbound from the graphics context device.

## Remarks

Before the display miniport driver receives a call to its [DxgkDdiDestroyAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_destroyallocation) function to release allocations, the driver calls the *DxgkDdiCloseAllocation* function to close all bindings to those allocations.

For a resource that contains multiple allocations, the DirectX graphics kernel subsystem directs *DxgkDdiCloseAllocation* to simultaneously close all of the allocations by specifying the handles to the device-specific allocations in the **pOpenHandleList** member of the [DXGKARG_CLOSEALLOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_closeallocation) structure.

*DxgkDdiCloseAllocation* should be made pageable.

## See also

[DXGKARG_CLOSEALLOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_closeallocation)

[DXGKARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createdevice)

[DxgkDdiCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdevice)

[DxgkDdiDestroyAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_destroyallocation)

[DxgkDdiOpenAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_openallocationinfo)