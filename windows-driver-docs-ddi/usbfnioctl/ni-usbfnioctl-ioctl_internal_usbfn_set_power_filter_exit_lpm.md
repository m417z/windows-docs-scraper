# IOCTL_INTERNAL_USBFN_SET_POWER_FILTER_EXIT_LPM IOCTL

## Description

Do not use.

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

None.

### Input buffer length

None.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful.

Otherwise, Status to the appropriate error condition as a NTSTATUS code.

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

This request must be sent after sending the [IOCTL_INTERNAL_USBFN_ACTIVATE_USB_BUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnioctl/ni-usbfnioctl-ioctl_internal_usbfn_activate_usb_bus) request.

Upon receiving this request, the filter driver
communicates with the hardware and brings the controller out of LPM.

## See also

[Link Power management in USB 3.0 Hardware](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)