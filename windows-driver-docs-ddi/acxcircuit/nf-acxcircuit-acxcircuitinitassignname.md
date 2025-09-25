## Description

The AcxCircuitInitAssignName function assigns a friendly name for the ACXCIRCUIT.

## Parameters

### `CircuitInit`

The ACXCIRCUIT_INIT structure that defines the circuit initialization. ACXCIRCUIT_INIT is an opaque object used for circuit initialization. Use [AcxCircuitInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxcircuitinitallocate) to initialize the ACXCIRCUIT_INIT structure.

### `CircuitName`

A unicode string with the circuit name, such as *Microphone0*.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

The CircuitName string must match the INF string that identifies the audio interface.

### Example

Example usage is shown below.

```cpp
    // Circuit Name
    DECLARE_CONST_UNICODE_STRING(circuitName, L"Microphone0");

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