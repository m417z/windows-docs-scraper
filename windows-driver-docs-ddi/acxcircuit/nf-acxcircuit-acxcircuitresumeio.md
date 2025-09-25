## Description

The **AcxCircuitResumeIo** function is used to resume circuit I/O after it has been temporarily stopped.

## Parameters

### `Circuit`

An existing ACXCIRCUIT object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Remarks

It is not recommended to use this version of the stop IO call, but rather [AcxCircuitResumeIoWithTag macro](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxcircuitresumeiowithtag) as it provides additional diagnostic information by using a Tag.

### Example

Example usage is shown below.

```cpp

    BOOLEAN                         stoppedIo = FALSE;
    circuit = AcxPinGetCircuit(pin);

    //
    // Temporarily disable this circuit's I/Os while we are updating the
    // formats. This thread cannot be an I/O dispatched thread else we deadlock.
    //
    status = AcxCircuitStopIo(circuit, AcxStopIoNoFlags);
    if (!NT_SUCCESS(status))
    {
        HDTrace(TRACE_LEVEL_ERROR, FLAG_INFO,
                "Failed to stop I/O on circuit %p, %!STATUS!",
                circuit, status);
        ASSERT(FALSE);
        goto exit;
    }
    stoppedIo = TRUE;

   // Code to update format list not shown here

...

    if (stoppedIo)
    {
        AcxCircuitResumeIo(circuit);
        stoppedIo = FALSE;
    }
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [AcxCircuitResumeIoWithTag macro](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxcircuitresumeiowithtag)
- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)