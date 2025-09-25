## Description

The **AcxCircuitAddPhysicalConnections** function adds physical connections to an ACXCIRCUIT.

## Parameters

### `Circuit`

An existing ACXCIRCUIT object. For more information, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Connections`

A pointer to an [ACX_CONNECTION structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_connection) that describes the pin structure including the pin IDs.

### `ConnectionsCount`

The number of physical connections that will be added to the circuit. This is a one based count.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

At this time this DDI is reserved. See DDIs of ACXMANAGER, ACXCIRCUITTEMPLATE and ACXCOMPOSITEMPLATE on how to link multiple ACXCIRCUITs together.

### Example

Example usage is shown below.

```cpp

```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)