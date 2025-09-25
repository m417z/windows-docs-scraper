## Description

The **AcxDeviceRemoveFactoryCircuit** function removes a factory circuit for creating audio circuits from a **WDFDEVICE**.

## Parameters

### `Device`

The **WDFDEVICE** from which the ACX factory circuit will be removed.

### `Factory`

The ACX factory circuit to remove from the **WDFDEVICE** specified by the *Device* parameter.

## Return value

**AcxDeviceRemoveFactoryCircuit** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) error code.

## Remarks

A typical driver won’t need to call **AcxDeviceRemoveFactoryCircuit**. This function should not be called if the factory circuit has created circuit devices that are still active.

If a driver decides to call this function for a factory circuit, the driver becomes responsible for first removing the circuit devices created through the associated factory circuit, *before* **AcxDeviceRemoveFactoryCircuit** is called.

For more information about working with circuits see [ACX circuit dynamic removal](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-circuits#acx-circuit-dynamic-removal) and [ACX device enumeration](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-device-enumeration).

This function can only be called from the [EVT_WDF_DEVICE_RELEASE_HARDWARE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_release_hardware) callback function for this device.

Use [AcxDeviceAddFactoryCircuit](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/nf-acxdevice-acxdeviceaddfactorycircuit) to add a factory circuit to a **WDFDEVICE**.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [AcxDeviceAddFactoryCircuit](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/nf-acxdevice-acxdeviceaddfactorycircuit)
- [AcxDeviceRemoveCircuit](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/nf-acxdevice-acxdeviceremovecircuit)
- [AcxDeviceRemoveCircuitDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/nf-acxdevice-acxdeviceremovecircuitdevice)
- [acxdevice.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/)