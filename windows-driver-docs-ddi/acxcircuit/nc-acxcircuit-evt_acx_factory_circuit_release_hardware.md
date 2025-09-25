## Description

The **EVT_ACX_FACTORY_CIRCUIT_RELEASE_HARDWARE** callback is used by the driver to add functionality when an ACXFACTORYCIRCUIT is in the release hardware phase.

## Parameters

### `Device`

A WDFDEVICE object (described in [Summary of Framework Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/summary-of-framework-objects)) that is associated with the ACX circuit.

### `Factory`

The existing circuit factory ACXFACTORYCIRCUIT Object. (For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `ResourcesTranslated`

A WDF resource list that describes the translated resources to be used for the prepare hardware phase. This is a WDF framework resource-list object that represents a list of hardware resources for a device. For more information about translated resource lists, see [Raw and Translated Resources](https://learn.microsoft.com/windows-hardware/drivers/wdf/hardware-resources-for-kmdf-drivers).

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

To register an EvtAcxFactoryCircuitReleaseHardware callback function, your driver must call [AcxFactoryCircuitInitSetAcxCircuitPnpPowerCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxfactorycircuitinitsetacxcircuitpnppowercallbacks).

If a driver has registered an EvtAcxFactoryCircuitReleaseHardware callback function, the framework calls it during the following transitions:

- Resource rebalancing
- Orderly removal
- Surprise removal

The ACX framework calls the EvtAcxFactoryCircuitReleaseHardware callback function after the WDF framework has stopped sending I/O requests to the device, any interrupts assigned to the device have been disabled and disconnected, and the device has been turned off.

The ACX framework calls the EvtAcxFactoryCircuitReleaseHardware callback function before the WDF framework calls the driver's EvtDeviceReleaseHardware callback function.

When the framework calls the EvtAcxFactoryCircuitReleaseHardware the PDO for the device still exists and can be queried for device information that is available in the powered off state, for example PCI configuration state.

In addition, the translated hardware resources that the framework supplies to EvtDeviceReleaseHardware are still assigned to the device. The primary purpose of this callback function is to release those resources, and in particular to un-map any memory resources that the driver's EvtAcxCircuitPrepareHardware callback function mapped. The driver can also use this callback to perform any other ACXCIRCUIT management activity that might be required in the powered down state. Usually, all other hardware shutdown operations should take place in the driver's EvtDeviceD0Exit callback function.

The ACX framework always calls the driver's EvtAcxFactoryCircuitReleaseHardware callback function if the driver's EvtAcxFactoryCircuitPrepareHardware callback function has been called, unless the EvtAcxFactoryCircuitPrepareHardware returned a failure code.

For more information about when the ACX and WDF framework call these callback functions, see [PnP and Power Management Scenarios](https://learn.microsoft.com/windows-hardware/drivers/wdf/pnp-and-power-management-scenarios).

For more information about hardware resources, see [Introduction to Hardware Resources](https://learn.microsoft.com/windows-hardware/drivers/wdf/introduction-to-hardware-resources).

For more information about drivers that provide this callback function, see [Supporting PnP and Power Management in Function Driver](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-pnp-and-power-management-in-function-drivers).

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)