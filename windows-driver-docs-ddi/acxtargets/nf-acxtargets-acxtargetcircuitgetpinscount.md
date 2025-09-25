## Description

The **AcxTargetCircuitGetPinsCount** function returns the count of ACX pins on the remote target.

## Parameters

### `TargetCircuit`

An AXTARGETCIRCUIT handle. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Return value

Returns the number of ACX pins on the remote target.

## Remarks

### Example

```cpp
    ULONG pinCount;

    pinCount = AcxTargetCircuitGetPinsCount(targetCircuit);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxtargets.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxtargets/)