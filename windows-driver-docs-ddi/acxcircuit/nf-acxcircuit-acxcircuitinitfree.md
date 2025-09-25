## Description

The **AcxCircuitInitFree** function deletes the circuit initialization object.

## Parameters

### `CircuitInit`

The ACXCIRCUIT_INIT structure that defines the circuit initialization. ACXCIRCUIT_INIT is an opaque object used for circuit initialization. Use [AcxCircuitInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxcircuitinitallocate) to initialize the ACXCIRCUIT_INIT structure.

## Remarks

This function does not return a value.

The driver is responsible for deleting the ACXCIRCUIT_INIT object using this DDI if the AcxCircuitCreate is not invoked or returns an error.

### Example

Example usage is shown below.

```cpp

    //
    // Get a CircuitInit structure.
    //
    PACXCIRCUIT_INIT circuitInit = NULL;
    circuitInit = AcxCircuitInitAllocate(Device);

// Later in the code on an exit close down process...

exit:
    if (!NT_SUCCESS(status))
    {
        if (circuitInit)
        {
            AcxCircuitInitFree(circuitInit);
        }
    }

```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)