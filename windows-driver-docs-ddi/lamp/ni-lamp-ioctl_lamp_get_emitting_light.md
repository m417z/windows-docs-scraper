# IOCTL_LAMP_GET_EMITTING_LIGHT IOCTL

## Description

The **IOCTL_LAMP_GET_EMITTING_LIGHT** control code queries if the lamp is turned on.

```cpp
#define IOCTL_LAMP_GET_EMITTING_LIGHT \
    CTL_CODE(IOCTL_LAMP_BASE, 0x0008, METHOD_BUFFERED, FILE_ANY_ACCESS)
```

## Parameters

### Major code

### Input buffer

`Irp->AssociatedIrp.SystemBuffer` points to a buffer of type **BOOLEAN**.

### Input buffer length

Length of a **BOOLEAN**.

### Output buffer

`Irp->AssociatedIrp.SystemBuffer` contains the lamp state; **TRUE** if the lamp is turned on and emitting light; **FALSE** otherwise.

### Output buffer length

`IO_STACK_LOCATION.Parameters.DeviceIoControl.OutputBufferLength` is the length of the buffer in bytes passed in the `Irp->AssociatedIrp.SystemBuffer` field.

### Input/output buffer

### Input/output buffer length

### Status block

The driver sets `Irp->IoStatus.Status` to **STATUS_SUCCESS** or the appropriate error status. It will set `Irp->IoStatus.Information` to the number of bytes required to hold a **DWORD** value.

If the device has been acquired by a camera driver, the lamp driver should return a **STATUS_RESOURCE_IN_USE** error via `Irp->IoStatus.Status`.