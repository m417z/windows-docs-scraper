# IOCTL_INTERNAL_USBFN_GET_INTERFACE_DESCRIPTOR_SET IOCTL

## Description

The class driver sends this request to get the entire USB interface descriptor set for a function on the device.

**Note** Do not use this request to retrieve the interface descriptor set for the entire device.

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

A pointer to a buffer that contains a [USBFN_INTERFACE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnbase/ns-usbfnbase-_usbfn_interface_info) structure.

### Input buffer length

The length of the input buffer must be at least `sizeof(USBFN_INTERFACE_INFO)`.

### Output buffer

A pointer to a buffer that contains a [USBFN_INTERFACE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnbase/ns-usbfnbase-_usbfn_interface_info) structure. USB function class extension (UFX) populates the structure with the entire interface descriptor set including its endpoint descriptors.

### Output buffer length

The length of the output buffer must be at least `sizeof(USBFN_INTERFACE_INFO)`.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the USB function class extension (UFX) returns STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise it returns a status value for which NT_SUCCESS(status) equals FALSE.

## Remarks

This request must be sent after sending the [IOCTL_INTERNAL_USBFN_ACTIVATE_USB_BUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnioctl/ni-usbfnioctl-ioctl_internal_usbfn_activate_usb_bus) request.

The length of the entire interface descriptor is variable. The class driver might need to send this IOCTL request twice to get the entire descriptor set.

If the length of the entire descriptor set is greater than the specified output buffer length, UFX sets the **Size** member of [USBFN_INTERFACE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnbase/ns-usbfnbase-_usbfn_interface_info) to the actual buffer length and fails the request with STATUS_BUFFER_TOO_SMALL. The driver must then allocated an output buffer of length specified by **Size** and resend the request.

## See also

[IOCTL_INTERNAL_USBFN_ACTIVATE_USB_BUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnioctl/ni-usbfnioctl-ioctl_internal_usbfn_activate_usb_bus)

[USBFN_INTERFACE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnbase/ns-usbfnbase-_usbfn_interface_info)