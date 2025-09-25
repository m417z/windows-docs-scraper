## Description

The **AcxDeviceAddCircuit** function adds an ACX circuit to a **WDFDEVICE** to create an audio endpoint.

## Parameters

### `Device`

A **WDFDEVICE** representing the device to which the circuit will be added.

### `Circuit`

The circuit to add to the *Device*.

## Return value

**AcxDeviceAddCircuit** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) error code.

## Remarks

The audio circuit is the core building block of ACX. An audio driver creates one or more ACX circuit objects to represent a partial or complete audio data and control path. ACX assembles these ACX circuit objects together to create a complete audio path which represents an audio endpoint.

This function can only be called from the [EVT_WDF_DEVICE_PREPARE_HARDWARE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) callback function for this device.

### Example

```cpp
WDFDEVICE             Device;
NTSTATUS              status;
PCODEC_DEVICE_CONTEXT devCtx;

// Code to initialize the WDFDEVICE...

devCtx = GetCodecDeviceContext(Device);
ASSERT(devCtx != NULL);

//
// Add static circuit to device's list.
//
ASSERT(devCtx->Render);
status = AcxDeviceAddCircuit(Device, devCtx->Render);

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

- [AcxDeviceAddCircuitDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/nf-acxdevice-acxdeviceaddcircuitdevice)
- [AcxDeviceDetachCircuit](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/nf-acxdevice-acxdevicedetachcircuit)
- [AcxDeviceRemoveCircuit](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/nf-acxdevice-acxdeviceremovecircuit)
- [acxdevice.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/)