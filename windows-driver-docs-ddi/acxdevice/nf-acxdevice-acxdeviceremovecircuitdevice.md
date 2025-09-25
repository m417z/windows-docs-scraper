## Description

The **AcxDeviceRemoveCircuitDevice** function removes an ACX circuit device from a specified parent device.

## Parameters

### `ParentDevice`

The parent **WDFDEVICE** from which to remove the ACX circuit device.

### `Device`

The **WDFDEVICE** representing the circuit device to remove from the parent device.

## Return value

**AcxDeviceRemoveCircuitDevice** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) error code.

## Remarks

Audio drivers use this function to remove an existing audio endpoint.

This function can be called at any time during the driver's life cycle. Plug and Play takes care to serialize the removal of the device, and the associated circuits, in relation to other Plug and Play activities on the parent and siblings devices.

### Example

```cpp
NTSTATUS status;
WDFDEVICE Device;
WDFDEVICE child;

// Code to initialize WDFDEVICE objects...

// Remove the child device.
status = AcxDeviceRemoveCircuitDevice(Device, child);

if (!NT_SUCCESS(status))
{
    ASSERT(FALSE);
    goto exit;
}
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [AcxDeviceRemoveCircuit](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/nf-acxdevice-acxdeviceremovecircuit)
- [acxdevice.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/)