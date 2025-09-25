## Description

The **AcxStreamAddConnections** function adds explicit connections to a new ACX stream during [EvtAcxCircuitCreateStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nc-acxcircuit-evt_acx_circuit_create_stream)

## Parameters

### `Stream`

An existing ACXSTREAM stream object. For more information, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Connections`

An [ACX_CONNECTION structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_connection) that contains information about the connections to add the stream.

### `ConnectionsCount`

The number of connections that are in the stream. This is a 1 based count.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

If the driver does not call AcxStreamAddConnections during EvtAcxCircuitCreateStream, the ACX framework will automatically assign connections between any ACXELEMENT objects that were added to the ACXSTREAM.

### Example

Example usage is shown below.

```cpp
    //
    // Explicitly connect the elements of the stream. Note that the driver doesn't
    // need to perform this step when elements are connected in the same order
    // as they were added to the stream.
    //

    const int numElements = 2;
    const int numConnections = numElements + 1;

    ACXSTREAM                      Stream;

    ACX_CONNECTION connections[numConnections];
    ACX_CONNECTION_INIT(&connections[0], Stream, Elements[ElementCount - 2]);
    ACX_CONNECTION_INIT(&connections[1], Elements[ElementCount - 2], Elements[ElementCount - 1]);
    ACX_CONNECTION_INIT(&connections[2], Elements[ElementCount - 1], Stream);

    //
    // Add the connections linking stream to elements.
    //
    status = AcxStreamAddConnections(Stream, connections, SIZEOF_ARRAY(connections));
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)