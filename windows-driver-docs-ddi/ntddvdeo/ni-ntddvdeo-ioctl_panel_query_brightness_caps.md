# IOCTL_PANEL_QUERY_BRIGHTNESS_CAPS IOCTL

## Major Code: [[XREF-LINK:IRP_MJ_DEVICE_CONTROL]

## Description

Queries the brightness capabilities for a display panel.

## Parameters

### Major code

### Input buffer

### Input buffer length

### Output buffer

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful.
Otherwise, Status to the appropriate error condition as a NTSTATUS code.