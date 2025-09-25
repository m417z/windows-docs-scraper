# IOCTL_PANEL_QUERY_BRIGHTNESS_RANGES IOCTL

## Description

IOCTL_PANEL_QUERY_BRIGHTNESS_RANGES queries the brightness ranges for a display panel.

## Parameters

### Major code

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

### Input buffer

Set to NULL.

### Input buffer length

Set to 0.

### Output buffer

A pointer to a caller-allocated buffer that receives the output data. The output is a [**PANEL_QUERY_BRIGHTNESS_RANGES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_panel_query_brightness_ranges) structure in which the queried brightness levels or nit ranges are returned.

### Output buffer length

The size, in bytes, of the output buffer. This value must be set to the size of the **PANEL_QUERY_BRIGHTNESS_RANGES** structure expected to be returned in the output buffer.

### Input/output buffer

n/a

### Input/output buffer length

n/a

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful. Otherwise, it's set to the appropriate error condition as a NTSTATUS code.

## See also

[**PANEL_QUERY_BRIGHTNESS_RANGES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_panel_query_brightness_ranges)