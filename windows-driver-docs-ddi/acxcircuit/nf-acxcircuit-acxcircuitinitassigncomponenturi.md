## Description

The **AcxCircuitInitAssignComponentUri** function assigns an URI string as ID for the ACXCIRCUIT.

## Parameters

### `CircuitInit`

The ACXCIRCUIT_INIT structure that defines the circuit initialization. ACXCIRCUIT_INIT is an opaque object used for circuit initialization. Use [AcxCircuitInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxcircuitinitallocate) to initialize the ACXCIRCUIT_INIT structure.

### `ComponentUri`

A unicode string describing the URI that uniquely identifies the ACXCIRCUIT.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

The driver must initialize the circuit's identity by setting its URI and/or its ID (AcxCircuitInitSetComponentId).

### Example

Example usage is shown below.

```cpp
    DECLARE_CONST_UNICODE_STRING(CODEC_CIRCUIT_CAPTURE_URI, L"acx:test:acxcodectestdriver:codec0:circuit0:microphone0");

    // Get a CircuitInit structure.
    //
    circuitInit = AcxCircuitInitAllocate(Device);

    //
    // Add circuit identifiers.
    //
    status = AcxCircuitInitAssignComponentUri(circuitInit, &CODEC_CIRCUIT_CAPTURE_URI);

```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)