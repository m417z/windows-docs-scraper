## Description

*Dxgkrnl* calls the kernel-mode display driver's (KMD) **DxgkddiDisplayMuxSwitchCanceled** function to notify the driver that the switch sequence was canceled before being completed.

## Parameters

### `DriverContext`

[in] Handle to a context block that is associated with a display adapter. KMD's [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to *Dxgkrnl*.

### `VidPnTargetId`

[in] The VidPN target that the DDI is being called for.

### `MuxSwitchedToTarget`

[in] Boolean value that indicates whether the display mux is currently switched to connect the target identified by **VidPnTargetId** to the panel.

## Return value

**DxgkddiDisplayMuxSwitchCanceled** returns **STATUS_SUCCESS** if it succeeds. Otherwise, it returns an appropriate error code.

## Remarks

This DDI is called under [synchronization level 2](https://learn.microsoft.com/windows-hardware/drivers/display/threading-and-synchronization-second-level).

In general, the driver should revert any hardware or internal driver state that was modified as part of the switch sequence. The following table shows some examples of what the driver should do, but it isn't an exhaustive list.

| MuxSwitchedToTarget | Mux was switched to GPU before switch | Mux was switched away from GPU before switch |
| --- | --- | --- |
| FALSE | Ensure that the driver has turned off power to the internal panel, disabled brightness levels, and stopped sending brightness levels to the mux. The driver/GPU is ready for the next switch sequence. | Nothing |
| TRUE | If the driver already reported the lid as disconnected then add a new connection change packet to report the lid as connected again. The driver/GPU should be ready for the [**DxgkddiSettimingsfromvidpn**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_settimingsfromvidpn) call that will occur shortly. On the next **DxgkddiSettimingsfromvidpn** call, the driver needs to ensure PSR is disabled. | If the driver hasn't already reported the lid as connected then add a connection change packet to report the lid as connected. The driver/GPU should be ready for **DxgkddiSettimingsfromvidpn** call that will occur shortly. On the next **DxgkddiSettimingsfromvidpn** call, the driver needs to ensure PSR is disabled. |

For more information, see [Automatic Display Switch](https://learn.microsoft.com/windows-hardware/drivers/display/automatic-display-switch).

## See also

[**DxgkddiSettimingsfromvidpn**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_settimingsfromvidpn)