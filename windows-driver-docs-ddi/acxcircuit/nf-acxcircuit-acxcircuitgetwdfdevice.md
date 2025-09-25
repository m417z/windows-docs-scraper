## Description

Given an existing ACX Circuit object, the **AcxCircuitGetWdfDevice** function returns the associated WDFDEVICE object.

## Parameters

### `Circuit`

An existing ACXCIRCUIT object. For more information, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Return value

A WDFDEVICE object (described in [Summary of Framework Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/summary-of-framework-objects)) that is associated with the ACX circuit object.
## Remarks

### Example

Example usage is shown below.

```cpp
    ACXCIRCUIT  circuit = (ACXCIRCUIT)DriverContext;
    WDFDEVICE   device = nullptr;

    device = AcxCircuitGetWdfDevice(circuit);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)