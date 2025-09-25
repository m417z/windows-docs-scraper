# IOCTL_MIPI_DSI_QUERY_CAPS IOCTL

### Major Code: [IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

## Description

**IOCTL_MIPI_DSI_QUERY_CAPS** retrieves the basic capabilities of the MIPI DSI interface exposed by the graphics driver, and identification information from the panel.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

n/a

### Output buffer

Buffer in which the DSI capabilities are returned. Must be at least ```sizeof(DXGK_DSI_CAPS)```.

### Output buffer length

Size in bytes of the output buffer.

### Input/output buffer

n/a

### Input/output buffer length

n/a

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful.
Otherwise, Status to the appropriate error condition as a NTSTATUS code.

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

Mobile Industry Processor Interface (MIPI) Digital Serial Interface(DSI) IOCTLs must be handled by the monitor, oem-panel, or port/miniport driver.

The OEM panel driver should initialize by using **IOCTL_MIPI_DSI_QUERY_CAPS** which provides information to allow the OEM panel driver to verify driver support and provides the raw level 1 DDB data from the display to allow one panel driver to support multiple devices and to confirm that there is no mismatch. The capabilities are returned in a [**DXGK_DSI_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_dsi_caps) structure. It is responsibility of the OEM panel driver to validate DSI capability, and compatibility with the panel since neither the graphics driver nor the OS has sufficient information to do so, particularly for any manufacturer defined or undefined elements.

The OS translates the query IOCTL into a call to [**DsiQueryCaps**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dsicaps), passing in the target id of the monitor as input and the caps structure for output. The graphics driver should fill in the requested fields, using cached information if available since the data should be static. Since the OS needs the **TargetMaximumReturnPacketSize** value for packet validation, it may request the capabilities from the graphics driver before receiving a request from the panel driver.

## See also

[**DsiQueryCaps**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dsicaps)

[**DXGK_DSI_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_dsi_caps)

[**IOCTL_MIPI_DSI_RESET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_mipi_dsi_reset)

[**IOCTL_MIPI_DSI_TRANSMISSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_mipi_dsi_transmission)