# IOCTL_LAMP_GET_MODE IOCTL

## Description

The **IOCTL_LAMP_GET_MODE** control code queries the mode with which the lamp is currently configured.

```cpp
#define IOCTL_LAMP_GET_MODE \
    CTL_CODE(IOCTL_LAMP_BASE, 0x0002, METHOD_BUFFERED, FILE_ANY_ACCESS)
```

## Parameters

### Major code

### Input buffer

`Irp->AssociatedIrp.SystemBuffer` points to a buffer of type [LAMP_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/lamp/ne-lamp-lamp_mode).

### Input buffer length

Length of [LAMP_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/lamp/ne-lamp-lamp_mode).

### Output buffer

`Irp->AssociatedIrp.SystemBuffer` is filled with a **LAMP_MODE** value.

### Output buffer length

`IO_STACK_LOCATION.Parameters.DeviceIoControl.OutputBufferLength` is the length of the buffer in bytes passed in the `Irp->AssociatedIrp.SystemBuffer` field.

### Input/output buffer

### Input/output buffer length

### Status block

The driver sets `Irp->IoStatus.Status` to **STATUS_SUCCESS** or the appropriate error status. It will set `Irp->IoStatus.Information` to the number of bytes required to hold a **DWORD** value.

If the device has been acquired by a camera driver, the lamp driver should return a **STATUS_RESOURCE_IN_USE** error via `Irp->IoStatus.Status`.