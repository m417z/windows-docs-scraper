# IOCTL_INTERNAL_USBFN_SET_POWER_FILTER_STATE IOCTL

## Description

Do not use.
ucxc

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

The input buffer contains a [USBFN_POWER_FILTER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnioctl/ns-usbfnioctl-_usbfn_power_filter_state) structure that specifies the device state.

### Input buffer length

The size of a [USBFN_POWER_FILTER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnioctl/ns-usbfnioctl-_usbfn_power_filter_state) structure.

### Output buffer

NULL.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful.

Otherwise, Status to the appropriate error condition as a NTSTATUS code.

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).