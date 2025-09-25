## Description

*Dxgkrnl* calls the kernel-mode display driver's (KMD) **DxgkddiDisplayMuxPreSwitchAway** function to notify the driver that the display currently connected to it is about to be switched away to another GPU.

## Parameters

### `DriverContext`

[in] Handle to a context block that is associated with a display adapter. KMD's [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to *Dxgkrnl*.

### `VidPnTargetId`

[in] The VidPN target that the DDI is being called for.

### `pSwitchPrivateDataSize`

[out] Pointer to a ULONG variable in which the driver writes the size in bytes of the switch private data that will be passed to the other GPU during the switch.

## Return value

**DxgkddiDisplayMuxPreSwitchAway** returns STATUS_SUCCESS if it succeeds. Otherwise, it returns an appropriate NT_STATUS error code.

## Remarks

This DDI is called under [synchronization level 2](https://learn.microsoft.com/windows-hardware/drivers/display/threading-and-synchronization-second-level).

For more information, see [Automatic Display Switch](https://learn.microsoft.com/windows-hardware/drivers/display/automatic-display-switch).

## See also

[**DxgkDdiDisplayMuxPreSwitchAwayGetPrivateData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_displaymux_pre_switch_away_get_private_data)