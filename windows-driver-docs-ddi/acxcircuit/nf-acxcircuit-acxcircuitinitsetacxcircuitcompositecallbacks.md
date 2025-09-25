## Description

The **AcxCircuitInitSetAcxCircuitCompositeCallbacks** function sets the driver's composite callbacks for the ACXCIRCUIT.

## Parameters

### `CircuitInit`

The ACXCIRCUIT_INIT structure that defines the circuit initialization. ACXCIRCUIT_INIT is an opaque object used for circuit initialization. Use [AcxCircuitInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxcircuitinitallocate) to initialize the ACXCIRCUIT_INIT structure.

### `EvtCompositeCallbacks`

A pointer to an initialized [ACX_CIRCUIT_COMPOSITE_CALLBACKS structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/ns-acxcircuit-acx_circuit_composite_callbacks) that contains the callbacks to be used for the circuit.

## Remarks

This function does not return a value.

### Example

Example usage is shown below.

```cpp
    //
    // Assign the circuit's composite callbacks.
    //
    {
        ACX_CIRCUIT_COMPOSITE_CALLBACKS compositeCallbacks;
        ACX_CIRCUIT_COMPOSITE_CALLBACKS_INIT(&compositeCallbacks);
        compositeCallbacks.EvtAcxCircuitCompositeCircuitInitialize = CodecR_EvtCircuitCompositeCircuitInitialize;
        compositeCallbacks.EvtAcxCircuitCompositeInitialize = CodecR_EvtCircuitCompositeInitialize;
        compositeCallbacks.EvtAcxCircuitCompositeDeinitialize = CodecR_EvtCircuitCompositeDeinitialize;
        AcxCircuitInitSetAcxCircuitCompositeCallbacks(circuitInit, &compositeCallbacks);
    }
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)