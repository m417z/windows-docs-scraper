# IOCTL_SERIAL_INTERNAL_RESTORE_SETTINGS IOCTL

## Description

The IOCTL_SERIAL_INTERNAL_RESTORE_SETTINGS request restores the specified operating mode of a serial device. The specified operating mode should be a mode that was returned by an [IOCTL_SERIAL_INTERNAL_BASIC_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_internal_basic_settings) request. The operating mode settings should be treated as opaque. Serial does not verify the settings when the settings are restored. Note also that a replacement for Serial might implement a different set of parameters.

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

The **AssociatedIrp.SystemBuffer** member of the IRP structure points to a client-allocated SERIAL_BASIC_SETTINGS structure that is used to input operating mode settings. The client should use settings that were returned by an IOCTL_SERIAL_INTERNAL_BASIC_SETTINGS request.

### Input buffer length

The **Parameters.DeviceIoControl.InputBufferLength** member of the IO_STACK_LOCATION structure is set to the size, in bytes, of a SERIAL_BASIC_SETTINGS structure.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the **Information** member is set to the size, in bytes, of SERIAL_BASIC_SETTINGS structure. Otherwise, the **Information** member is set to zero.

The **Status** member is set to one of the [Generic Status Values for Serial Device Control Requests](https://learn.microsoft.com/windows-hardware/drivers/serports/serial-device-control-requests2). If Status is set to STATUS_BUFFER_TOO_SMALL, the **Parameters.DeviceIoControl.InputBufferLength** member of the IO_STACK_LOCATION structure is less than the size, in bytes, of a SERIAL_BASIC_SETTINGS structure.

## See also

[IOCTL_SERIAL_INTERNAL_BASIC_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_internal_basic_settings)