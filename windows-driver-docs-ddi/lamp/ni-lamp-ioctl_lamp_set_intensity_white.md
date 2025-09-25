# IOCTL_LAMP_SET_INTENSITY_WHITE IOCTL

## Description

The **IOCTL_LAMP_SET_INTENSITY_WHITE** control code sets the lamp to the specified light intensity.

```cpp
#define IOCTL_LAMP_SET_INTENSITY_WHITE \
    CTL_CODE(IOCTL_LAMP_BASE, 0x0005, METHOD_BUFFERED, FILE_ANY_ACCESS)
```

## Parameters

### Major code

### Input buffer

`Irp->AssociatedIrp.SystemBuffer` points to a [LAMP_INTENSITY_WHITE](https://learn.microsoft.com/windows-hardware/drivers/ddi/lamp/ns-lamp-lamp_intensity_white) structure.

### Input buffer length

Length of a [LAMP_INTENSITY_WHITE](https://learn.microsoft.com/windows-hardware/drivers/ddi/lamp/ns-lamp-lamp_intensity_white) structure.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The driver sets `Irp->IoStatus.Status` to **STATUS_SUCCESS** or the appropriate error status.

If the device has been acquired by a camera driver, the lamp driver should return a **STATUS_RESOURCE_IN_USE** error via `Irp->IoStatus.Status`.