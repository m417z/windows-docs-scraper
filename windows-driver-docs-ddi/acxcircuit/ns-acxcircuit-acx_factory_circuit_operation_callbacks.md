## Description

The **ACX_FACTORY_CIRCUIT_OPERATION_CALLBACKS** structure identifies the driver callbacks for ACX factory operations.

## Members

### `Size`

The length, in bytes, of this structure.

### `EvtAcxFactoryCircuitCreateCircuitDevice`

The [EVT_ACX_FACTORY_CIRCUIT_CREATE_CIRCUITDEVICE callback](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nc-acxcircuit-evt_acx_factory_circuit_create_circuitdevice).

### `EvtAcxFactoryCircuitDeleteCircuitDevice`

The [ACX_FACTORY_CIRCUIT_DELETE_CIRCUITDEVICE callback](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nc-acxcircuit-evt_acx_factory_circuit_delete_circuitdevice).

### `EvtAcxFactoryCircuitCreateCircuit`

The [EVT_ACX_FACTORY_CIRCUIT_CREATE_CIRCUIT callback](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nc-acxcircuit-evt_acx_factory_circuit_create_circuit).

## Remarks

### Example

Example usage is shown below.

```cpp
    ACX_FACTORY_CIRCUIT_OPERATION_CALLBACKS         operationCallbacks;

    //
    // Assign the circuit's operation-callbacks.
    //
    ACX_FACTORY_CIRCUIT_OPERATION_CALLBACKS_INIT(&operationCallbacks);
    operationCallbacks.EvtAcxFactoryCircuitCreateCircuitDevice = SdcaXu_EvtAcxFactoryCircuitCreateCircuitDevice;
    operationCallbacks.EvtAcxFactoryCircuitCreateCircuit = SdcaXu_EvtAcxFactoryCircuitCreateCircuit;

    AcxFactoryCircuitInitSetOperationCallbacks(factoryInit, &operationCallbacks);

```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)