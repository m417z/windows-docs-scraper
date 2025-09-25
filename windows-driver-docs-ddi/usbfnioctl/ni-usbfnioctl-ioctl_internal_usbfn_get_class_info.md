# IOCTL_INTERNAL_USBFN_GET_CLASS_INFO IOCTL

## Description

The class driver sends this request IO control code to retrieve information about the available pipes for a device, as configured in the registry.

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

NULL.

### Input buffer length

None.

### Output buffer

A pointer to a buffer that contains a [USBFN_CLASS_INFORMATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnbase/ns-usbfnbase-_usbfn_class_information_packet) structure. Upon completion, UFX populates the structure with the name, the device interface GUID, and details of the interface when operating at a particular bus speed.

### Output buffer length

The size of a [USBFN_CLASS_INFORMATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnbase/ns-usbfnbase-_usbfn_class_information_packet) structure.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the USB function class extension (UFX) returns STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise it returns a status value for which NT_SUCCESS(status) equals FALSE.

## Remarks

The class driver should send this IOCTL request during initialization so that it can enumerate the endpoints and attributes.