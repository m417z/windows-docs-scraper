## Description

**AcxStreamAddEvents** adds events to an existing stream using an ACXEVENT object. For more information about ACX Objects, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Parameters

### `Stream`

An existing ACXSTREAM Object. An ACXSTREAM object represents an audio stream created by a circuit. The stream is composed of a list of elements created based on the parent circuit's elements.

### `Events`

A pointer to the ACXEVENT Objects to be added to the Stream. An ACXEVENT object represents an asynchronous notification available at the driver level. Events can be added to AcxCircuits, AcxStreams, AcxElements and AcxPins. Internally they are exposed as KS events to upper layers. For more information about ACX Objects, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `EventsCount`

A count of the events. This is a one based count.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

Example usage is shown below.

```cpp
    ACXEVENT event;
    ...
    AcxStreamAddEvents(Stream, &event, 1);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)