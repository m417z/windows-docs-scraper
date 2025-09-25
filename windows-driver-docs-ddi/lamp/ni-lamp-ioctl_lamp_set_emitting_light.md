# IOCTL_LAMP_SET_EMITTING_LIGHT IOCTL

## Description

The **IOCTL_LAMP_SET_EMITTING_LIGHT** control code turns the lamp on or off.

```cpp
#define IOCTL_LAMP_SET_EMITTING_LIGHT \
    CTL_CODE(IOCTL_LAMP_BASE, 0x0009, METHOD_BUFFERED, FILE_ANY_ACCESS)
```

## Parameters

### Major code

### Input buffer

`Irp->AssociatedIrp.SystemBuffer` points to a buffer of type **BOOLEAN**, with **TRUE** indicating a request to turn the lamp on; **FALSE** otherwise.

### Input buffer length

Length of a **BOOLEAN**.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The driver sets `Irp->IoStatus.Status` to **STATUS_SUCCESS** or the appropriate error status.

If the device has been acquired by a camera driver, the lamp driver should return a **STATUS_RESOURCE_IN_USE** error via `Irp->IoStatus.Status`.