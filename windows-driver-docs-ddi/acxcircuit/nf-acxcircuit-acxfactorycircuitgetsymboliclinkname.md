## Description

The **AcxFactoryCircuitGetSymbolicLinkName** function retrieves the symbolic link name for the specified ACX factory circuit.

## Parameters

### `Circuit` [in]

The ACX factory circuit for which to retrieve the symbolic link name.

## Return value

Returns a string containing the symbolic link name for the ACX factory circuit object specified by the *Circuit* parameter.

## Remarks

The symbolic link is valid:

1. After the driver adds the circuit to the device, for single-circuit endpoints.
1. When the ACX manager invokes ACX circuit initialization, for multi-circuit endpoints.

### ACX requirements

**Minimum ACX version:** 1.1

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)