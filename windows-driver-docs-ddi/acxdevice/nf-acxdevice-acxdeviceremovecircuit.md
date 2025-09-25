## Description

The **AcxDeviceRemoveCircuit** function removes the specified audio circuit from an ACX device.

## Parameters

### `Device`

The **WDFDEVICE** from which to remove the audio circuit specified by the *Circuit* parameter.

### `Circuit`

The audio circuit to remove from the WDFDEVICE specified by the *Device* parameter.

## Return value

**AcxDeviceRemoveCircuit** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) error code.

## Remarks

Use [AcxDeviceAddCircuit](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/nf-acxdevice-acxdeviceaddcircuit) to add an audio circuit to a **WDFDEVICE**.

This function can only be called from the [EVT_WDF_DEVICE_RELEASE_HARDWARE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_release_hardware) callback function for this device.

### Example

```cpp
NTSTATUS              status;
WDFDEVICE             Device = NULL;
PUSBA2_DEVICE_CONTEXT devCtx;

// Code to initialize WDFDEVICE...

devCtx = GetDeviceContext(Device);

//
// Unregister filter and delete this audio filter.
//
if (devCtx->RenderCircuitAdded) {
    ASSERT(devCtx->RenderCircuit);
    status = AcxDeviceRemoveCircuit(Device, devCtx->RenderCircuit);

    devCtx->RenderCircuit = NULL;
    devCtx->RenderCircuitAdded = FALSE;
}
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [AcxDeviceAddCircuit](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/nf-acxdevice-acxdeviceaddcircuit)
- [AcxDeviceRemoveCircuitDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/nf-acxdevice-acxdeviceremovecircuitdevice)
- [acxdevice.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/)