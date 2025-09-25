## Description

The **AcxDeviceAddFactoryCircuit** function adds a factory circuit to a **WDFDEVICE** for creating audio circuits.

## Parameters

### `Device`

A **WDFDEVICE** to which the ACX factory circuit will be added.

### `Factory`

The ACX factory circuit to add to the **WDFDEVICE** specified by the *Device* parameter.

## Return value

**AcxDeviceAddFactoryCircuit** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) error code.

## Remarks

An ACX driver may create one or more circuits in the following scenarios:

- At initialization time
- At run time, as side effect of an external event, such as detecting a new audio component
- Because it registered itself with ACX as circuit factory. The ACX framework uses the registered factory to ask the driver to create a new circuit.

Use [AcxDeviceRemoveFactoryCircuit](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/nf-acxdevice-acxdeviceremovefactorycircuit) to remove a factory circuit from a **WDFDEVICE**.

This function can only be called from the [EVT_WDF_DEVICE_PREPARE_HARDWARE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) callback function for this device.

### Example

```cpp
WDFDEVICE                Device;
NTSTATUS                 status;
PCAPTURE_DEVICE_CONTEXT  devCtx;

// Code to initialize WDFDEVICE...

//
// Add control circuit to child's list.
//
status = AcxDeviceAddFactoryCircuit(Device, devCtx->CtrlCircuit);

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

- [AcxDeviceRemoveFactoryCircuit](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/nf-acxdevice-acxdeviceremovefactorycircuit)
- [acxdevice.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/)