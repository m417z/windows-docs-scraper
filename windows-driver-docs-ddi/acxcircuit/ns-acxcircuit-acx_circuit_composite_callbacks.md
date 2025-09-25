## Description

The **ACX_CIRCUIT_COMPOSITE_CALLBACKS** structure identifies the driver callbacks for ACX composite circuit operations.

## Members

### `Size`

The length, in bytes, of this structure.

### `EvtAcxCircuitCompositeCircuitInitialize`

The [EVT_ACX_CIRCUIT_COMPOSITE_CIRCUIT_INITIALIZE callback](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nc-acxcircuit-evt_acx_circuit_composite_circuit_initialize).

### `EvtAcxCircuitCompositeInitialize`

The [EVT_ACX_CIRCUIT_COMPOSITE_INITIALIZE callback](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nc-acxcircuit-evt_acx_circuit_composite_initialize).

### `EvtAcxCircuitCompositeDeinitialize`

The [EVT_ACX_CIRCUIT_COMPOSITE_DEINITIALIZE callback](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nc-acxcircuit-evt_acx_circuit_composite_deinitialize).

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