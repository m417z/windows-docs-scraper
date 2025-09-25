## Description

The **AcxDeviceDetachCircuit** function detaches an audio circuit from a **WDFDEVICE** prior to removal.

## Parameters

### `Device`

The **WDFDEVICE** from which to detach the audio circuit specified by the *Circuit* parameter.

### `Circuit`

The audio circuit to remove from the **WDFDEVICE** specified by the *Device* parameter.

## Return value

**AcxDeviceDetachCircuit** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) error code.

This function can only be called from the [EVT_WDF_DEVICE_RELEASE_HARDWARE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_release_hardware) callback function for this device.

**AcxDeviceDetachCircuit** detaches the circuit from the device. The caller is responsible for deleting the **ACXCIRCUIT** object.

## Remarks

### Example

```cpp
WDFDEVICE                    Device;
NTSTATUS                     status;
PCODEC_RENDER_DEVICE_CONTEXT renderDevCtx = NULL;

// Code to initialize WDFDEVICE...

renderDevCtx = GetRenderDeviceContext(Device);

ASSERT(renderDevCtx->Circuit);
status = AcxDeviceDetachCircuit(Device, renderDevCtx->Circuit);

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
- [AcxDeviceRemoveCircuitDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/nf-acxdevice-acxdeviceremovecircuitdevice)
- [acxdevice.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/)