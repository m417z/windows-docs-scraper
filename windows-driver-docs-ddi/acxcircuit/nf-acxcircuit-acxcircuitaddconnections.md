## Description

The **AcxCircuitAddConnections** function adds connections to an ACXCIRCUIT.

## Parameters

### `Circuit`

An existing ACXCIRCUIT object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).
### `Connections`

A pointer to an [ACX_CONNECTION structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_connection) that describes the pin structure including the pin IDs.

### `ConnectionsCount`

The number of connections that will be added to the circuit. This is a one based count.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

Example usage is shown below.

```cpp
    //
    // Explicitly connect the circuit/elements. Note that driver doesn't
    // need to perform this step when circuit/elements are connected in the
    // same order as they were added to the circuit. By default ACX connects
    // the elements starting from the sink circuit pin and ending with the
    // source circuit pin for both render and capture devices.
    //
    // circuit.pin[default_sink]    -> 1st element.pin[default_in]
    // 1st element.pin[default_out] -> 2nd element.pin[default_in]
    // 2nd element.pin[default_out] -> circuit.pin[default_source]
    //

    const int numElements = 2;
    const int numConnections = numElements + 1;

    ACXCIRCUIT                      Circuit;

    ACX_CONNECTION connections[numConnections];
    ACX_CONNECTION_INIT(&connections[0], Circuit, Elements[ElementCount - 2]);
    ACX_CONNECTION_INIT(&connections[1], Elements[ElementCount - 2], Elements[ElementCount - 1]);
    ACX_CONNECTION_INIT(&connections[2], Elements[ElementCount - 1], Circuit);

    //
    // Add the connections linking circuit to elements.
    //
    status = AcxCircuitAddConnections(Circuit, connections, SIZEOF_ARRAY(connections));
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)