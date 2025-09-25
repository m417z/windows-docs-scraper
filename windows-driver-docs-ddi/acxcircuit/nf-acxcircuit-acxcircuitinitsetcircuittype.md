## Description

The **AcxCircuitInitSetCircuitType** function is used to set the circuit type of the ACXCIRCUIT.

## Parameters

### `CircuitInit`

The ACXCIRCUIT_INIT structure that defines the circuit initialization. ACXCIRCUIT_INIT is an opaque object used for circuit initialization. Use [AcxCircuitInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxcircuitinitallocate) to initialize the ACXCIRCUIT_INIT structure.

### `CircuitType`

An [ACX_CIRCUIT_TYPE enum](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/ne-acxcircuit-acx_circuit_type) that is used to define the circuit type. For example, AcxCircuitTypeRender, AcxCircuitTypeCapture or AcxCircuitTypeOther.

## Remarks

### Example

Example usage is shown below.

```cpp
   ACX_CIRCUIT_TYPE                circuitType     = AcxCircuitTypeRender;

        // The driver uses this DDI to specify the circuit type. The
        // circuit type can be AcxCircuitTypeRender, AcxCircuitTypeCapture,
        // AcxCircuitTypeOther, or AcxCircuitTypeMaximum (for validation).
        //
        AcxCircuitInitSetCircuitType(circuitInit, AcxCircuitTypeRender);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)