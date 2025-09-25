## Description

The **AcxPinGetCircuit** function returns the circuit to which the specified pin is connected.

## Parameters

### `AcxPin` [in]

The pin for which to return the connected circuit.

## Return value

Returns the [ACXCIRCUIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/) object representing the circuit to which the *AcxPin* is connected.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACXCIRCUIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)
- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)