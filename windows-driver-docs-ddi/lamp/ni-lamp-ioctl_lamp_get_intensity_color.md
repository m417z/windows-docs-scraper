# IOCTL_LAMP_GET_INTENSITY_COLOR IOCTL

## Description

The **IOCTL_LAMP_GET_INTENSITY_COLOR** control code queries the light intensity when the lamp is configured to emit color light.

```cpp
#define IOCTL_LAMP_GET_INTENSITY_COLOR \
    CTL_CODE(IOCTL_LAMP_BASE, 0x0006, METHOD_BUFFERED, FILE_ANY_ACCESS)
```

## Parameters

### Major code

### Input buffer

`Irp->AssociatedIrp.SystemBuffer` points to a [LAMP_INTENSITY_COLOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/lamp/ns-lamp-lamp_intensity_color) structure.

### Input buffer length

Length of a [LAMP_INTENSITY_COLOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/lamp/ns-lamp-lamp_intensity_color) structure.

### Output buffer

`Irp->AssociatedIrp.SystemBuffer` is filled with the light intensity information.

### Output buffer length

`IO_STACK_LOCATION.Parameters.DeviceIoControl.OutputBufferLength` is the length of the buffer in bytes passed in the `Irp->AssociatedIrp.SystemBuffer` field.

### Input/output buffer

### Input/output buffer length

### Status block

The driver sets `Irp->IoStatus.Status` to **STATUS_SUCCESS** or the appropriate error status.

If the device has been acquired by a camera driver, the lamp driver should return an error **STATUS_RESOURCE_IN_USE** via `Irp->IoStatus.Status`.

## Remarks

The payload type of this IOCTL is a [LAMP_INTENSITY_COLOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/lamp/ns-lamp-lamp_intensity_color) structure.