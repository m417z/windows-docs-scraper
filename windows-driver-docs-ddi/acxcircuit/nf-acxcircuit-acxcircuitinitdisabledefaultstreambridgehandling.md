## Description

The **AcxCircuitInitDisableDefaultStreamBridgeHandling** function disables the ACX default stream bridge handling in a multi-circuit environment.

## Parameters

### `CircuitInit`

The ACXCIRCUIT_INIT structure that defines the circuit initialization. ACXCIRCUIT_INIT is an opaque object used for circuit initialization. Use [AcxCircuitInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxcircuitinitallocate) to initialize the ACXCIRCUIT_INIT structure.

## Remarks

When the driver invokes this method and the stream doesn't have an associated ACXSTREAMBRIDGE, ACX will not attempt to create a default stream bridge to forward the stream and its states to the next circuit.

This function doesn't have any effect when called on a single-circuit endpoint or on the last circuit of a multi-circuit endpoint.

### Example

Example usage is shown below.

```cpp
    //
    // Get a CircuitInit structure.
    //
    PACXCIRCUIT_INIT circuitInit = NULL;
    circuitInit = AcxCircuitInitAllocate(Device);

    //
    // Disable default Stream Bridge handling in ACX
    // Create stream handler will add Stream Bridge
    // to support Object-bag forwarding
    //
    AcxCircuitInitDisableDefaultStreamBridgeHandling(circuitInit);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)