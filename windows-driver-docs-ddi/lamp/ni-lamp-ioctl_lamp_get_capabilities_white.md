# IOCTL_LAMP_GET_CAPABILITIES_WHITE IOCTL

## Description

The **IOCTL_LAMP_GET_CAPABILITIES_WHITE** control code queries the capabilities of the lamp when the device is configured to emit white light.

```cpp
#define IOCTL_LAMP_GET_CAPABILITIES_WHITE \
    CTL_CODE(IOCTL_LAMP_BASE, 0x0000, METHOD_BUFFERED, FILE_ANY_ACCESS)
```

## Parameters

### Major code

### Input buffer

`Irp->AssociatedIrp.SystemBuffer` points to a buffer of type [LAMP_CAPABILITIES_WHITE](https://learn.microsoft.com/windows-hardware/drivers/ddi/lamp/ns-lamp-lamp_capabilities_white).

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

By requirement, a lamp whose driver supports the **GUID_DEVINTERFACE_LAMP** interface is required to support emitting white light.

The payload of this IOCTL is a [LAMP_CAPABILITIES_WHITE](https://learn.microsoft.com/windows-hardware/drivers/ddi/lamp/ns-lamp-lamp_capabilities_white) structure.

The **IsLightIntensityAdjustable** field indicates whether the luminance level can be programmed. If this field evaluates to **FALSE**, it means that the underlying device only supports the on/off switch and the light intensity cannot be adjusted.