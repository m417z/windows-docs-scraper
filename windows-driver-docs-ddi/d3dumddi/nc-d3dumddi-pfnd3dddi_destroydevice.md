# PFND3DDDI_DESTROYDEVICE callback function

## Description

The *DestroyDevice* function destroys a graphics context.

## Parameters

### `hDevice`

A handle to the display device (graphics context) being destroyed.

## Return value

*DestroyDevice* returns S_OK or an appropriate error result.

## Remarks

The driver should free all of the resources that it allocated for the device and clean up any internal tracking data structures.

Before the driver calls the [pfnDeallocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_deallocatecb) function to release allocations, the driver must ensure that the allocations are unlocked. In other words, in the lifetime of a device, every call to the [pfnLockCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockcb) function to lock an allocation must be paired with a call to the [pfnUnlockCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_unlockcb) function to unlock the allocation. However, in one call to *pfnUnlockCb*, the driver can unlock multiple allocations that were each allocated in separate *pfnLockCb* calls.

## See also

[CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdevice)

[pfnDeallocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_deallocatecb)

[pfnLockCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockcb)

[pfnUnlockCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_unlockcb)