## Description

*Dxgkrnl* calls the kernel-mode display driver's (KMD) **DxgkddiDisplayMuxPostSwitchToPhase1** function to notify the driver that the mux switch has completed, and that the driver is now connected to the display and should perform phase 1 tasks.

## Parameters

### `DriverContext`

[in] Handle to a context block that is associated with a display adapter. KMD's [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to *Dxgkrnl*.

### `VidPnTargetId`

[in] The VidPN target that the DDI is being called for.

### `SwitchPrivateDataSize`

[in] The size, in bytes, of the buffer that is pointed to by **pSwitchPrivateDataBuffer**.

### `pSwitchPrivateDataBuffer`

[in] A pointer to a buffer that contains the private data that was obtained from the GPU that the [mux was switched away from](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_displaymux_pre_switch_away_get_private_data)

### `pSwitchPrivateDataGUID`

[in] Pointer to the GUID that describes the version/layout of the private data.

## Return value

**DxgkddiDisplayMuxPostSwitchToPhase1** returns STATUS_SUCCESS if it succeeds. Otherwise, it returns an appropriate error code.

## Remarks

This DDI is called under [synchronization level 2](https://learn.microsoft.com/windows-hardware/drivers/display/threading-and-synchronization-second-level).

KMD needs to both verify that it understands the passed GUID and validate the integrity of the data in the buffer.

If KMD doesn't understand the packet, it should ignore it. In this situation, KMD shouldn't fail the call.

For more information, see [Automatic Display Switch](https://learn.microsoft.com/windows-hardware/drivers/display/automatic-display-switch).

## See also

[**DxgkddiDisplayMuxPostSwitchAway**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_displaymux_post_switch_away)

[**DxgkddiDisplayMuxPostSwitchToPhase2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_displaymux_post_switch_to_phase2)

[**DxgkddiDisplayMuxPreSwitchAwayGetPrivateData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_displaymux_pre_switch_away_get_private_data)