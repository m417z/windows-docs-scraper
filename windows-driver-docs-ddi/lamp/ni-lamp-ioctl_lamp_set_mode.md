# IOCTL_LAMP_SET_MODE IOCTL

## Description

The **IOCTL_LAMP_SET_MODE** control code sets the mode in which the lamp operates.

```cpp
#define IOCTL_LAMP_SET_MODE \
    CTL_CODE(IOCTL_LAMP_BASE, 0x0003, METHOD_BUFFERED, FILE_ANY_ACCESS)
```

## Parameters

### Major code

### Input buffer

`Irp->AssociatedIrp.SystemBuffer` points to a buffer of type [LAMP_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/lamp/ne-lamp-lamp_mode).

### Input buffer length

Length of a [LAMP_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/lamp/ne-lamp-lamp_mode).

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The driver sets `Irp->IoStatus.Status` to **STATUS_SUCCESS** or the appropriate error status.

If the device has been acquired by a camera driver, the lamp driver should return a **STATUS_RESOURCE_IN_USE** error via `Irp->IoStatus.Status`.