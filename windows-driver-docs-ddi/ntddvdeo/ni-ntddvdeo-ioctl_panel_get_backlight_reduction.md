# IOCTL_PANEL_GET_BACKLIGHT_REDUCTION IOCTL

## Major Code: [[XREF-LINK:IRP_MJ_DEVICE_CONTROL]

## Description

Panel control IOCTLs must/can be handled by the monitor, OEM panel, or port/miniport driver.

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