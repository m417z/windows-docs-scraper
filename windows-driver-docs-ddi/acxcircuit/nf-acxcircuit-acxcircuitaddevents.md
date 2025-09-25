## Description

The **AcxCircuitAddEvents** function adds one or more events to an ACXCIRCUIT.

## Parameters

### `Circuit`

An existing ACXCIRCUIT object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Events`

An existing ACXEVENT object containing one or more events.

### `EventsCount`

The number of events that will be added to the circuit. This is a one based count.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

An AcxEvent represents an asynchronous notification available at the driver level. Events can be added to AcxCircuits, AcxStreams, AcxElements and AcxPins. They are exposed as KS events to clients (upper user-mode layers).

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)