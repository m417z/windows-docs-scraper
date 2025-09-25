## Description

*Dxgkrnl* calls the kernel-mode display driver's (KMD) **DxgkddiDisplayMuxPostSwitchToPhase2** function to notify the driver that the mux switch has completed, and that the driver is now connected to the display and should perform phase 2 tasks.

## Parameters

### `DriverContext`

[in] Handle to a context block that is associated with a display adapter. KMD's [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to *Dxgkrnl*.

### `VidPnTargetId`

[in] The VidPN target that the DDI is being called for.

### `pWasPanelInPSR`

[out] Pointer to a Boolean value that the driver should set to indicate whether the panel was in panel self-refresh (PSR) when the driver took over control.

KMD should set this value to TRUE if the panel was in PSR. If the driver can't reliably determine whether the panel was in PSR, it should still set this value to TRUE. KMD should only return FALSE if it can reliably determine that the panel was not in PSR.

## Return value

**DxgkddiDisplayMuxPostSwitchToPhase2** returns STATUS_SUCCESS if it succeeds. Otherwise, it returns an appropriate error code.

## Remarks

This DDI is called under [synchronization level 2](https://learn.microsoft.com/windows-hardware/drivers/display/threading-and-synchronization-second-level).

For more information, see [Automatic Display Switch](https://learn.microsoft.com/windows-hardware/drivers/display/automatic-display-switch).

## See also

[**DxgkddiDisplayMuxPostSwitchToPhase1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_displaymux_post_switch_to_phase1)