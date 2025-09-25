## Description

The **EVT_ACX_FACTORY_CIRCUIT_CREATE_CIRCUIT** callback is invoked by ACX when the driver must create an ACXCIRCUIT object with the specified configuration.

## Parameters

### `Parent`

A WDFDEVICE object (described in [Summary of Framework Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/summary-of-framework-objects)) that is the parent of the WDFDEVICE referenced in Device object.

### `Device`

A WDFDEVICE object (described in [Summary of Framework Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/summary-of-framework-objects)) created in the EVT_ACX_FACTORY_CIRCUIT_CREATE_CIRCUITDEVICE callback. This device will be associated with the new ACXCIRCUIT.

### `Factory`

The existing circuit factory ACXFACTORYCIRCUIT Object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Config`

An [ACX_FACTORY_CIRCUIT_ADD_CIRCUIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/ns-acxcircuit-acx_factory_circuit_add_circuit) structure that defines the configuration for the new ACXCIRCUIT.

### `CircuitInit`

ACXCIRCUIT_INIT is an opaque object used for circuit initialization. Use [AcxCircuitInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxcircuitinitallocate) to initialize the ACXCIRCUIT_INIT structure.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

An AcxFactoryCircuit represents a factory object capable of creating an ACXCIRCUIT on demand.

A driver can register one or more ACXFACTORYCIRCUIT with ACX, this action will let ACX know that the driver is capable of creating ACXCIRCUITs of a well defined type.

ACX invokes the ACXFACTORYCIRCUIT's callbacks when it detects that an audio path requires one of the factory provided ACXCIRCUITs.

An AcxFactoryCircuit has a dedicated WDF queue. For more information about WDF queues, see [Framework Queue Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-queue-objects).

### Example

Example usage is shown below.

```cpp
EVT_ACX_FACTORY_CIRCUIT_CREATE_CIRCUIT Dsp_EvtAcxFactoryCircuitCreateCircuit;

NTSTATUS
Dsp_EvtAcxFactoryCircuitCreateCircuit(
    _In_ WDFDEVICE                          Parent,
    _In_ WDFDEVICE                          Device,
    _In_ ACXFACTORYCIRCUIT                  Factory,
    _In_ PACX_FACTORY_CIRCUIT_ADD_CIRCUIT   CircuitConfig,
    _In_ PACXCIRCUIT_INIT                   CircuitInit
)
{
    ACXOBJECTBAG circuitProperties;

    PAGED_CODE();

    NTSTATUS status = STATUS_SUCCESS;

    // Create object bag from the CompositeProperties
    ACX_OBJECTBAG_CONFIG propConfig;
    ACX_OBJECTBAG_CONFIG_INIT(&propConfig);
    propConfig.Handle = CircuitConfig->CircuitProperties;
    propConfig.Flags |= AcxObjectBagConfigOpenWithHandle;

    WDF_OBJECT_ATTRIBUTES attributes;
    WDF_OBJECT_ATTRIBUTES_INIT(&attributes);

    RETURN_NTSTATUS_IF_FAILED(AcxObjectBagOpen(&attributes, &propConfig, &circuitProperties));

    auto cleanupPropConfig = scope_exit([=]() {
        WdfObjectDelete(circuitProperties);
        }
    );

    // Retrieve the intended Circuit ID from the object bag
    GUID circuitId;
    RETURN_NTSTATUS_IF_FAILED(Dsp_DetermineCircuitGuidFromVendorProperties(circuitProperties, &circuitId));

    AcxCircuitInitSetComponentId(CircuitInit, &circuitId);

    // Call the appropriate CreateCircuitDevice based on the Circuit ID
    if (IsEqualGUID(circuitId, DSP_CIRCUIT_MICROPHONE_GUID) || IsEqualGUID(circuitId, DSP_CIRCUIT_UNIVERSALJACK_CAPTURE_GUID))
    {
        return DspC_EvtAcxFactoryCircuitCreateCircuit(Parent, Device, Factory, CircuitConfig, CircuitInit);
    }
    else if (IsEqualGUID(circuitId, DSP_CIRCUIT_SPEAKER_GUID) || IsEqualGUID(circuitId, DSP_CIRCUIT_UNIVERSALJACK_RENDER_GUID))
    {
        return DspR_EvtAcxFactoryCircuitCreateCircuit(Parent, Device, Factory, CircuitConfig, CircuitInit);
    }

    status = STATUS_NOT_SUPPORTED;
    return status;
}
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)