## Description

The **AcxDeviceAddCircuitDevice** function adds an ACX circuit device to a specified parent device representing an audio path.

## Parameters

### `ParentDevice`

A **WDFDEVICE** representing the parent to which the circuit device will be added.

### `Device`

A **WDFDEVICE** representing the circuit device to add to the parent device.

## Return value

**AcxDeviceAddCircuitDevice** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) error code.

## Remarks

Audio drivers use this function to enumerate a new audio endpoint.

This function can be called at any time during the driver's life cycle. Plug and Play serializes the enumeration of the device, and the associated circuits, in relation to other Plug and Play activities on the parent and siblings devices.

### Example

```cpp
WDFDEVICE Device;
WDFDEVICE renderDevice = NULL;
NTSTATUS  status;

// Code to initialize the WDFDEVICE...

// Code to create the WDFDEVICE renderDevice...

//
// Add circuit to device's dynamic circuit device list.
//
status = AcxDeviceAddCircuitDevice(Device, renderDevice);
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

- [AcxDeviceAddCircuit](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/nf-acxdevice-acxdeviceaddcircuit)
- [AcxDeviceRemoveCircuitDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/nf-acxdevice-acxdeviceremovecircuitdevice)
- [acxdevice.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/)