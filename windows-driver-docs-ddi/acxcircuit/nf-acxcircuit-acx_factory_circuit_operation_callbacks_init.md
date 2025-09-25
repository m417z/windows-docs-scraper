## Description

The **ACX_FACTORY_CIRCUIT_OPERATION_CALLBACKS_INIT** function initializes a
[ACX_FACTORY_CIRCUIT_OPERATION_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/ns-acxcircuit-acx_factory_circuit_operation_callbacks) config structure. No inputs are used with this function.

## Parameters

### `Config`

An initialized [ACX_FACTORY_CIRCUIT_OPERATION_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/ns-acxcircuit-acx_factory_circuit_operation_callbacks) config structure that is used to store circuit factory operation callbacks information.

## Remarks

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