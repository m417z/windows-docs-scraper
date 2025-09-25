## Description

The **ACX_CIRCUIT_COMPOSITE_CALLBACKS_INIT** function initializes a [ACX_CIRCUIT_COMPOSITE_CALLBACKS structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/ns-acxcircuit-acx_circuit_composite_callbacks). No inputs are used with this function.

## Parameters

### `CompositeCallbacks`

A pointer to an initialized [ACX_CIRCUIT_COMPOSITE_CALLBACKS structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/ns-acxcircuit-acx_circuit_composite_callbacks).

## Remarks

### Example

Example usage is shown below.

```cpp
    // Assign the circuit's composite callbacks.
    //
    {
        ACX_CIRCUIT_COMPOSITE_CALLBACKS compositeCallbacks;
        ACX_CIRCUIT_COMPOSITE_CALLBACKS_INIT(&compositeCallbacks);
        compositeCallbacks.EvtAcxCircuitCompositeCircuitInitialize = CodecR_EvtCircuitCompositeCircuitInitialize;
        compositeCallbacks.EvtAcxCircuitCompositeInitialize = CodecR_EvtCircuitCompositeInitialize;
        AcxCircuitInitSetAcxCircuitCompositeCallbacks(CircuitInit, &compositeCallbacks);
    }
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)