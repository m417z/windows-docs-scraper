# IOCTL_INTERNAL_KEYBOARD_DISCONNECT IOCTL

## Description

The IOCTL_INTERNAL_KEYBOARD_DISCONNECT request is completed with a status of STATUS_NOT_IMPLEMENTED. Note that a Plug and Play keyboard can be added or removed by the Plug and Play manager.

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

None

### Input buffer length

None

### Output buffer

None

### Output buffer length

None

### Input/output buffer

### Input/output buffer length

### Status block

The **Status** member is set to STATUS_NOT_IMPLEMENTED.

## See also

[IOCTL_INTERNAL_KEYBOARD_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/kbdmou/ni-kbdmou-ioctl_internal_keyboard_connect)