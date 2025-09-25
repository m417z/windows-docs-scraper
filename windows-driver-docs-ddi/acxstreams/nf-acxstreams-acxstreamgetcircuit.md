## Description

The **AcxStreamGetCircuit** function returns the ACXCIRCUIT Object associated with the stream. For more information about ACX Objects, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Parameters

### `Stream`

An existing ACXSTREAM Object. An ACXSTREAM object represents an audio stream created by a circuit.

## Return value

The handle to the ACXCIRCUIT Object associated with the stream.

## Remarks

### Example

Example usage is shown below.

```cpp
    ACXCIRCUIT circuit = AcxStreamGetCircuit(stream);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)