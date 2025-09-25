# IOCTL_LAMP_GET_CAPABILITIES_COLOR IOCTL

## Description

The **IOCTL_LAMP_GET_CAPABILITIES_COLOR** control code queries the capabilities of the lamp when the device is configured to emit color light.

```cpp
#define IOCTL_LAMP_GET_CAPABILITIES_COLOR \
    CTL_CODE(IOCTL_LAMP_BASE, 0x0001, METHOD_BUFFERED, FILE_ANY_ACCESS)
```

## Parameters

### Major code

### Input buffer

`Irp->AssociatedIrp.SystemBuffer` points to a buffer of type [LAMP_CAPABILITIES_COLOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/lamp/ns-lamp-lamp_capabilities_color).

### Input buffer length

Length of the buffer.

### Output buffer

`Irp->AssociatedIrp.SystemBuffer` is filled with all capabilities supported by the lamp hardware.

### Output buffer length

`IO_STACK_LOCATION.Parameters.DeviceIoControl.OutputBufferLength` is the length of the buffer (in bytes) passed in the `Irp->AssociatedIrp.SystemBuffer` field.

### Input/output buffer

### Input/output buffer length

### Status block

The driver sets `Irp->IoStatus.Status` to **STATUS_SUCCESS** or the appropriate error status. It will set `Irp->IoStatus.Information` to the number of bytes required to hold the buffer.

## Remarks

The payload of this IOCTL is a [LAMP_CAPABILITIES_COLOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/lamp/ns-lamp-lamp_capabilities_color) structure.

The **IsSupported** field indicates whether the lamp can emit color light. If the hardware does not support color light, the driver should set this field to **FALSE**.

The **IsLightIntensityAdjustable** field indicates whether the luminance level can be programmed. If the lamp does not support color light (**IsSupported** evaluates to **FALSE**), a client should discard the value of **IsLightIntensityAdjustable**.