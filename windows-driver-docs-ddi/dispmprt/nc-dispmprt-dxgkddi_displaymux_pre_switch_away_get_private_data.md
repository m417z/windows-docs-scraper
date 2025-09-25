## Description

*Dxgkrnl* calls the **DxgkddiDisplayMuxPreSwitchAwayGetPrivateData** function of the kernel-mode display driver (KMD) currently connected to the panel to retrieve any private data from it.

## Parameters

### `DriverContext`

[in] Handle to a context block that is associated with a display adapter. KMD's [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to *Dxgkrnl*.

### `VidPnTargetId`

[in] The VidPN target that the DDI is being called for.

### `SwitchPrivateDataSize`

[in] The size, in bytes, of the buffer that **pSwitchPrivateDataBuffer** points to. The driver provided this value to *Dxgkrnl* in a previous call to [**DxgkddiDisplayMuxPreSwitchAway**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_displaymux_pre_switch_away).

### `pSwitchPrivateDataBuffer`

[in] Pointer to the allocated buffer in which the driver should copy the switch private data to.

### `pSwitchPrivateDataGUID`

[out] Pointer to a variable in which the driver should write the GUID that describes the switch private data. The driver must set a non-zero GUID.

## Return value

**DxgkddiDisplayMuxPreSwitchAwayGetPrivateData** returns STATUS_SUCCESS if it succeeds. Otherwise, it returns an appropriate NT_STATUS error code.

## Remarks

This DDI is called under [synchronization level 2](https://learn.microsoft.com/windows-hardware/drivers/display/threading-and-synchronization-second-level).

For more information, see [Automatic Display Switch](https://learn.microsoft.com/windows-hardware/drivers/display/automatic-display-switch).

## See also

[**DxgkddiDisplayMuxPreSwitchAway**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_displaymux_pre_switch_away)