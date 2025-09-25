## Description

The **EVT_ACX_FACTORY_CIRCUIT_POWER_UP** callback is used by the driver to add functionality in the power up path of an ACXFACTORYCIRCUIT object.

## Parameters

### `Device`

A WDFDEVICE object (described in [Summary of Framework Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/summary-of-framework-objects)) that is associated with the ACX circuit.

### `Factory`

The existing circuit factory ACXFACTORYCIRCUIT Object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `PreviousState`

A [WDF_POWER_DEVICE_STATE enumeration](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_power_device_state) that identifies the previous device power state.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

If the driver fails this callback, it tags the ACXFACTORYCIRCUIT as pending-delete. The ACX framework doesn't fail the underline ACX EvtDeviceD0Entry callback, this allows existing working ACXFACTORYCIRCUITs from this device to be used to build working audio paths.

## Remarks

To register an EvtFactoryCircuitPowerUp callback function, a driver must call [AcxFactoryCircuitInitSetAcxCircuitPnpPowerCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxfactorycircuitinitsetacxcircuitpnppowercallbacks).

If the driver has registered an EvtFactoryCircuitPowerUp callback function for a device, the framework calls the function each time the device enters its working (D0) state. A device will enter the D0 state when one of the following occurs:

- A device is enumerated (because the device was plugged in or the system was rebooted).
- The system and all of its devices return to their working states from a low-power state.
- The device returns to its working state after it entered a low-power state because it was idle (if the device supports low-power idle).
- The Plug and Play manager has redistributed the system's hardware resources among the system's devices.
- The framework calls the EvtDeviceD0Entry callback function immediately after the device enters its working (D0) state and is available to the driver, but before the device's interrupts have been enabled. The PreviousState parameter identifies the device power state that the device was in before it entered the D0 state. When the framework first calls EvtDeviceD0Entry, it provides a PreviousState value of WdfPowerDeviceD3Final.

This callback function must perform any operations that are needed to make the device fully operational.

For more information about drivers that provide this callback function, see [Supporting PnP and Power Management in Function Driver](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-pnp-and-power-management-in-function-drivers).

The EvtFactoryCircuitPowerUp callback function is called at IRQL = PASSIVE_LEVEL. You should not make this callback function pageable.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)