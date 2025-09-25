# IOCTL_MIPI_DSI_RESET IOCTL

### Major Code: [IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

## Description

**IOCTL_MIPI_DSI_RESET** requests the reset of a device under graphics driver and OS control.

## Parameters

### Major code

### Input buffer

n/a

### Input buffer length

n/a

### Output buffer

n/a

### Output buffer length

n/a

### Input/output buffer

A [**DXGK_DSI_RESET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_dsi_reset) structure.

### Input/output buffer length

At least ```sizeof(DXGK_DSI_RESET)```

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful.
Otherwise, Status to the appropriate error condition as a NTSTATUS code.

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

Mobile Industry Processor Interface (MIPI) Digital Serial Interface(DSI) IOCTLs must be handled by the monitor, oem-panel, or port/miniport driver.

If an OEM panel driver detects that the panel is in a bad state, it should send **IOCTL_MIPI_DSI_RESET** to request a reset of the device under graphics driver and OS control. The OS will coordinate the reset with the graphics driver. A reset is a heavy-weight operation that will cause display blanking for multiple frames, and should therefore be used only as a last resort.

Normal panel operation cannot continue while processing a reset, so the OS will treat is similarly to a display mode change, flushing pending GPU activity, including any flips, and blocking new work until complete. The OS translates the IOCTL into a [**DsiReset**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dsireset) DDI call. The driver should completely remove power from the panel and reinitialize it from scratch, and after the appropriate delay, perform any actions it needs to in order to restore the panel to a workable state before returning. When set, the **SecondaryPort** flag indicates that the reset should be targeted to a secondary panel rather than the primary.

If the graphics driver requires a full mode set in order to perform or restore from a panel reset, it should set the output flag **NeedModeSet**. If set upon return from the call, the OS will respond with a [**DxgkDdiSetTimingsFromVidPn**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_settimingsfromvidpn) call before unblocking normal activity. The driver may chose to defer some of the reset work to this call if needed, provided that a workable state is expected following the set timings call.

The graphics driver should report any low-level MIPI errors detected and not handled by the driver via the **MipiErrors** output field.

If an unrecoverable error occurs during the reset, the graphics driver should set the **ResetFailed** output flag. This is expected to be a catastrophic failure. The graphics driver should also signal that no display is available on the target by indicating that an unplug has occurred using the [**DxgkCbIndicateConnectorChange**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_indicate_connector_change) callback and then responding to [**DxgkDdiQueryConnectionChange**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryconnectionchange) by reporting a **TargetStatusDisconnected** for the target which has failed.

The output fields will be propagated back to the output buffer of the IOCTL.

## See also

[**DsiReset**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dsireset)

[**DXGK_DSI_RESET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_dsi_reset)

[**IOCTL_MIPI_DSI_QUERY_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_mipi_dsi_query_caps)

[**IOCTL_MIPI_DSI_TRANSMISSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_mipi_dsi_transmission)