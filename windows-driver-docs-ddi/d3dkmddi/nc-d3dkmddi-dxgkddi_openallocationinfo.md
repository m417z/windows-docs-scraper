# DXGKDDI_OPENALLOCATIONINFO callback function

## Description

The *DxgkDdiOpenAllocation* function binds non-device-specific allocations that the [DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation) function created to allocations that are specific to the specified graphics context device.

## Parameters

### `hDevice` [in]

A handle to the graphics context device that the allocations are bound from. The display miniport driver's [DxgkDdiCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdevice) function previously provided this handle to the Microsoft DirectX graphics kernel subsystem in the **hDevice** member of the [DXGKARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createdevice) structure.

### `pOpenAllocation` [in]

A pointer to a [DXGKARG_OPENALLOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_openallocation) structure that contains information about binding allocations.

## Return value

*DxgkDdiOpenAllocation* returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|DxgkDdiOpenAllocation successfully bound allocations to the graphics context device that the hDevice parameter specified.|
|STATUS_INVALID_PARAMETER|Parameters that were passed to DxgkDdiOpenAllocation contained errors that prevented it from completing.|
|STATUS_NO_MEMORY|DxgkDdiOpenAllocation could not allocate memory that was required for it to complete.|
|STATUS_GRAPHICS_DRIVER_MISMATCH|The display miniport driver is not compatible with the user-mode display driver that initiated the call to DxgkDdiOpenAllocation (that is, supplied private data to the display miniport driver).|

## Remarks

The DirectX graphics kernel subsystem calls the display miniport driver's *DxgkDdiOpenAllocation* function to bind nondevice-specific allocations that the [DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation) function created to allocations that are specific to the graphics context device that the *hDevice* parameter specifies. The display miniport driver binds allocations to a device so the driver can keep track of allocation data that is specific to a device.

The display miniport driver can bind an allocation to any device that any process (on the same graphics adapter) created and not just to a device in the creating process.

When *DxgkDdiOpenAllocation* returns STATUS_SUCCESS, the driver sets the **hDeviceSpecificAllocation** member of the [DXGK_OPENALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_openallocationinfo) structure for each allocation to a non-NULL value. The DXGK_OPENALLOCATIONINFO structure for each allocation is an element of the array that the **pOpenAllocation** member of the [DXGKARG_OPENALLOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_openallocation) structure specifies.

The driver can modify the allocation private driver data that is passed in the **pPrivateDriverData** member of the [DXGK_OPENALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_openallocationinfo) structure only when the allocation is created (which is indicated when the **Create** bit-field flag in the **Flags** member of the [DXGKARG_OPENALLOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_openallocation) structure is set). The driver should determine that it can only read the allocation private driver data when the allocation is opened (that is, when the **Create** bit-field flag is not set).

*DxgkDdiOpenAllocation* should be made pageable.

## See also

[DXGKARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createdevice)

[DXGKARG_OPENALLOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_openallocation)

[DXGK_OPENALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_openallocationinfo)

[DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation)

[DxgkDdiCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdevice)