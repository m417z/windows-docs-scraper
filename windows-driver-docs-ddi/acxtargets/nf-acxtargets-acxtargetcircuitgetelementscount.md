## Description

The **AcxTargetCircuitGetElementsCount** function returns the count of ACX elements on the remote target.

## Parameters

### `TargetCircuit`

An ACXTARGETCIRCUIT handle. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Return value

Returns the number of elements for the specified target circuit.

## Remarks

### Example

```cpp
    ULONG elementCount;

    elementCount = AcxTargetCircuitGetElementsCount(targetCircuit);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxtargets.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxtargets/)