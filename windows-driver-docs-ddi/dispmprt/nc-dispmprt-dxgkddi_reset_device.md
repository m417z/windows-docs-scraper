# DXGKDDI_RESET_DEVICE callback function

## Description

The *DxgkDdiResetDevice* function sets a display adapter to VGA character mode (80 x 50).

## Parameters

### `MiniportDeviceContext` [in]

A handle to a context block associated with a display adapter. The display miniport driver's [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to the DirectX graphics kernel subsystem.

## Remarks

The HAL calls this function so it can display information on the screen during hibernation, bug checks, and the like.

*DxgkDdiResetDevice* can be called at any IRQL, so it must be in nonpageable memory. *DxgkDdiResetDevice* must not call any code that is in pageable memory and must not manipulate any data that is in pageable memory.