## Description

The **AcxFactoryCircuitInitSetOperationCallbacks** sets the driver factory operation callbacks for the ACXFACTORYCIRCUIT.

## Parameters

### `FactoryInit`

An ACXFACTORYCIRCUIT_INIT structure that is used for circuit factory initialization. This is an opaque structure that is used to store ACX Circuit factory initialization information and associate the factory with a WDF device.

Use the [AcxFactoryCircuitInitAllocate function](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxfactorycircuitinitallocate) to initialize the ACXFACTORYCIRCUIT_INIT structure.

### `EvtOperationCallbacks`

An [ACX_FACTORY_CIRCUIT_OPERATION_CALLBACKS structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/ns-acxcircuit-acx_factory_circuit_operation_callbacks) that identifies the driver callbacks for ACX factory operations.

## Remarks

ACX invokes these callbacks to ask the factory to create or remove circuits.

### Example

Example usage is shown below.

```cpp
    //
    // Get a FactoryCircuitInit structure.
    //
    PACXFACTORYCIRCUIT_INIT factoryInit = NULL;
    factoryInit = AcxFactoryCircuitInitAllocate(Device);

    //
    // Add factory identifiers.
    //
    RETURN_NTSTATUS_IF_FAILED(AcxFactoryCircuitInitAssignComponentUri(factoryInit, &dspFactoryUri));
    RETURN_NTSTATUS_IF_FAILED(AcxFactoryCircuitInitAssignName(factoryInit, &dspFactoryName));

    //
    // Assign the circuit's operation-callbacks.
    //
    ACX_FACTORY_CIRCUIT_OPERATION_CALLBACKS operationCallbacks;
    ACX_FACTORY_CIRCUIT_OPERATION_CALLBACKS_INIT(&operationCallbacks);

    operationCallbacks.EvtAcxFactoryCircuitCreateCircuitDevice = Dsp_EvtAcxFactoryCircuitCreateCircuitDevice;
    operationCallbacks.EvtAcxFactoryCircuitCreateCircuit = Dsp_EvtAcxFactoryCircuitCreateCircuit;
    AcxFactoryCircuitInitSetOperationCallbacks(factoryInit, &operationCallbacks);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)