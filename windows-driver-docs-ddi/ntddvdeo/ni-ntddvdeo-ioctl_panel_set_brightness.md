# IOCTL_PANEL_SET_BRIGHTNESS IOCTL

## Major Code: [[XREF-LINK:IRP_MJ_DEVICE_CONTROL]

## Description

Sets the brightness for the display panel.

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