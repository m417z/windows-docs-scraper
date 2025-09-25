# IOCTL_INTERNAL_I8042_KEYBOARD_START_INFORMATION IOCTL

## Description

The IOCTL_INTERNAL_I8042_KEYBOARD_START_INFORMATION request passes a pointer to a keyboard interrupt object. I8042prt sends this request synchronously to the top of the device stack after the keyboard interrupt object is created. Upper-level filter drivers that need to synchronize their callback operation with the I8042prt keyboard ISR can use the pointer to the keyboard interrupt object.

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

**AssociatedIrp.SystemBuffer** points to a buffer allocated by I8042prt to input an [INTERNAL_I8042_START_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/ns-ntdd8042-_internal_i8042_start_information) structure.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** specifies the size, in bytes, of an [INTERNAL_I8042_START_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/ns-ntdd8042-_internal_i8042_start_information) structure.

### Output buffer

None

### Output buffer length

None

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** member is set to zero.

The **Status** member is set to STATUS_SUCCESS.

## See also

[INTERNAL_I8042_START_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/ns-ntdd8042-_internal_i8042_start_information)