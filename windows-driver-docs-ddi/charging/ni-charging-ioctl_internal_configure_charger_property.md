# IOCTL_INTERNAL_CONFIGURE_CHARGER_PROPERTY IOCTL

## Description

The **IOCTL_INTERNAL_CONFIGURE_CHARGER_PROPERTY** control code is sent from a configurable charger to a device that handles configurable chargers. It configures charger properties.

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

**Irp->AssociatedIrp.SystemBuffer** must contain a structure that starts with a [CONFIGURABLE_CHARGER_PROPERTY_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/charging/ns-charging-_configurable_charger_property_header) structure.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the buffer.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS or the appropriate error status.

## See also

[CONFIGURABLE_CHARGER_PROPERTY_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/charging/ns-charging-_configurable_charger_property_header)

[**charging.h**](https://learn.microsoft.com/windows-hardware/drivers/ddi/charging/)