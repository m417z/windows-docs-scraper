## Description

*Dxgkrnl* calls the kernel-mode display driver's (KMD) **DxgkddiDisplayMuxUpdateState** function to notify the driver of the current mux state.

## Parameters

### `DriverContext`

[in] Handle to a context block that is associated with a display adapter. KMD's [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to *Dxgkrnl*.

### `VidPnTargetId`

[in] The VidPN target that the DDI is being called for.

### `MuxSwitchedToTarget`

[in] A Boolean value that indicates whether the mux is currently switched to connect the specified **VidPnTargetId** to the panel.

## Remarks

This DDI is called under [synchronization level 2](https://learn.microsoft.com/windows-hardware/drivers/display/threading-and-synchronization-second-level).

*Dxgkrnl* calls **DxgkDdiDisplayMuxUpdateState** to provide the driver with the current mux state in the following cases:

* At driver start, which allows the driver to avoid timely polling sequences when the panel isn't connected.
* On return from sleep (to D0 power state from D*x*). When returning from some power states (for example, hibernate) the firmware might have to reset the mux and hence the driver doesn't know the state.

**DxgkDdiDisplayMuxUpdateState** is called before any display-related DDIs involving the target that the mux is connected to.

For more information, see [Automatic Display Switch](https://learn.microsoft.com/windows-hardware/drivers/display/automatic-display-switch).