# DXGKDDISETPOWERCOMPONENTFSTATE callback function

## Description

Called by the Microsoft DirectX graphics kernel subsystem to transition a power component to an idle state (an F-state).

## Parameters

### `DriverContext`

A handle to a context block associated with a display adapter. The display miniport driver's [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to the DirectX graphics kernel subsystem.

### `ComponentIndex`

The power component index specified by [DXGKARG_QUERYADAPTERINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryadapterinfo).**pInputData** in a call to the [DxgkDdiQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) function.

### `FState`

An F-state value that the display miniport driver has reported to the DirectX graphics kernel subsystem.

## Return value

 Returns STATUS_SUCCESS if it succeeds; otherwise, it returns STATUS_INVALID_PARAMETER.

## Remarks

The operating system calls *DxgkDdiSetPowerComponentFState* only if the display miniport driver indicates support by setting [DXGK_DRIVERCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps).**SupportRuntimePowerManagement** to **TRUE**.

**Note** To avoid a possible deadlock, do not call the [DxgkCbSetPowerComponentActive](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_setpowercomponentactive) function until this function has returned.

When the display miniport driver transitions a power component from the F0 (fully on) state to another F-state, it should save the context needed to later restore the component back to the F0 state.

The [Power Management Framework](https://learn.microsoft.com/windows-hardware/drivers/kernel/overview-of-the-power-management-framework) only transitions a component to or from the F0 state.

This function can be called simultaneously from multiple execution threads. However, only one thread at a time can call this function to control a particular component.

The operating system guarantees that this function follows the zero level synchronization mode as defined in [Threading and Synchronization Zero Level](https://learn.microsoft.com/windows-hardware/drivers/display/threading-and-synchronization-zero-level).

## See also

[DXGKARG_QUERYADAPTERINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryadapterinfo)

[DXGKRNL_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)

[DXGK_DRIVERCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps)

[DxgkCbSetPowerComponentActive](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_setpowercomponentactive)

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[DxgkDdiQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo)