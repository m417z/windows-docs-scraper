## Description

The **AcxCircuitInitSetComponentId** function sets the component ID for the ACXCIRCUIT.

## Parameters

### `CircuitInit`

The ACXCIRCUIT_INIT structure that defines the circuit initialization. ACXCIRCUIT_INIT is an opaque object used for circuit initialization. Use [AcxCircuitInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxcircuitinitallocate) to initialize the ACXCIRCUIT_INIT structure.

### `ComponentId`

A pointer to a defined GUID that serves as the component ID for the circuit.

## Remarks

The driver must initialize the circuit's identity by setting its URI (AcxCircuitInitAssignComponentUri) and/or its ID (this DDI).

### Example

Example usage is shown below.

```cpp
DEFINE_GUID(COMPONENT_GUID,
0xf55ba68e, 0x4384, 0x4030, 0x97, 0x19, 0xec, 0xa4, 0xbe, 0x27, 0x6c, 0xc8);

    //
    // Add circuit identifiers.
    //
    AcxCircuitInitSetComponentId(CircuitInit, &COMPONENT_GUID);

    AcxCircuitInitAssignName(CircuitInit, &circuitName);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)