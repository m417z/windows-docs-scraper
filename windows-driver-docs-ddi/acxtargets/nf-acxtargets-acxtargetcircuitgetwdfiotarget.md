## Description

The **AcxTargetCircuitGetWdfIoTarget** function will return the associated WDFIOTARGET object.

## Parameters

### `TargetCircuit`

An ACXTARGETCIRCUIT handle. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Return value

Returns a WDFIOTARGET Object that is associated with the specified circuit.

## Remarks

### Example

This example code shows the use of AcxTargetCircuitGetWdfIoTarget.

```cpp
    WDFIOTARGET ioTarget;

    ioTarget = AcxTargetCircuitGetWdfIoTarget(targetCircuit);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxtargets.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxtargets/)