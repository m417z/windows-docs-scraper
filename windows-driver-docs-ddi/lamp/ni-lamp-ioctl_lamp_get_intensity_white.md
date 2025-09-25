# IOCTL_LAMP_GET_INTENSITY_WHITE IOCTL

## Description

The **IOCTL_LAMP_GET_INTENSITY_WHITE** control code queries the light intensity when the lamp is configured to emit white light.

```cpp
#define IOCTL_LAMP_GET_INTENSITY_WHITE \
    CTL_CODE(IOCTL_LAMP_BASE, 0x0004, METHOD_BUFFERED, FILE_ANY_ACCESS)
```

## Parameters

### Major code

### Input buffer

`Irp->AssociatedIrp.SystemBuffer` points to a [LAMP_INTENSITY_WHITE](https://learn.microsoft.com/windows-hardware/drivers/ddi/lamp/ns-lamp-lamp_intensity_white) structure.

### Input buffer length

Length of a [LAMP_INTENSITY_WHITE](https://learn.microsoft.com/windows-hardware/drivers/ddi/lamp/ns-lamp-lamp_intensity_white) structure.

### Output buffer

`Irp->AssociatedIrp.SystemBuffer` is filled with the light intensity information.

### Output buffer length

`IO_STACK_LOCATION.Parameters.DeviceIoControl.OutputBufferLength` is the length of the buffer in bytes, passed in the `Irp->AssociatedIrp.SystemBuffer` field.

### Input/output buffer

### Input/output buffer length

### Status block

The driver sets `Irp->IoStatus.Status` to **STATUS_SUCCESS** or the appropriate error status.

If the device has been acquired by a camera driver, the lamp driver should return a **STATUS_RESOURCE_IN_USE** error via `Irp->IoStatus.Status`.

## Remarks

The payload type of this IOCTL is a [LAMP_INTENSITY_WHITE](https://learn.microsoft.com/windows-hardware/drivers/ddi/lamp/ns-lamp-lamp_intensity_white) structure.

The **Value** field is the white light intensity in percentage (0 - 100).