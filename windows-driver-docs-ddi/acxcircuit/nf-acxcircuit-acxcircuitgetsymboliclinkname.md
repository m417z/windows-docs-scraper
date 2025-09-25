## Description

The **AcxCircuitGetSymbolicLinkName** function retrieves the symbolic link name for the specified circuit object.

## Parameters

### `Circuit` [in]

The circuit object for which to get the symbolic link name.

## Return value

Returns a string containing the symbolic link name for the object specified by the *Circuit* parameter.

## Remarks

The symbolic link is valid:

1. After the driver adds the circuit to the device, for single-circuit endpoints.
1. When the ACX manager invokes ACX circuit initialization, for multi-circuit endpoints.

### Example

Example usage is shown below.

```cpp
...
    _In_ ACXCIRCUIT Circuit,
...

    WDFSTRING wdfLink = AcxCircuitGetSymbolicLinkName(Circuit);
```

### ACX requirements

**Minimum ACX version:** 1.1

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)