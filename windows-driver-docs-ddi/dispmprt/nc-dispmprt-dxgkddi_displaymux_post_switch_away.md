## Description

*Dxgkrnl* calls the kernel-mode display driver's (KMD) **DxgkddiDisplayMuxPostSwitchAway** function to notify the driver that it's no longer connected to the display.

## Parameters

### `DriverContext`

[in] Handle to a context block that is associated with a display adapter. KMD's [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to *Dxgkrnl*.

### `VidPnTargetId`

[in] The VidPN target that the DDI is being called for.

## Return value

**DxgkddiDisplayMuxPostSwitchAway** returns STATUS_SUCCESS if it succeeds. Otherwise, it returns an appropriate error code.

## Remarks

This DDI is called under [synchronization level 2](https://learn.microsoft.com/windows-hardware/drivers/display/threading-and-synchronization-second-level).

For more information, see [Automatic Display Switch](https://learn.microsoft.com/windows-hardware/drivers/display/automatic-display-switch).

## See also

[**DxgkddiDisplayMuxPostSwitchToPhase1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_displaymux_post_switch_to_phase1)

[**DxgkddiDisplayMuxPostSwitchToPhase2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_displaymux_post_switch_to_phase2)