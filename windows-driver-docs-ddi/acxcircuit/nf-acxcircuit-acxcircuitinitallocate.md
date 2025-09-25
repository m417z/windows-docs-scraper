## Description

The **AcxCircuitInitAllocate** function is used to initialize the opaque ACXCIRCUIT_INIT structure that is used by the [AcxCircuitCreate function](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxcircuitcreate).

## Parameters

### `Device`

A WDFDEVICE object (described in [Summary of Framework Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/summary-of-framework-objects)) that is associated with the ACX circuit.

## Return value

## Remarks

The driver is responsible for deleting the ACXCIRCUIT_INIT object using AcxCircuitInitFree if the AcxCircuitCreate is not invoked or returns an error.

### Example

Example usage is shown below.

```cpp
    PACXCIRCUIT_INIT    circuitInit = NULL;

    circuitInit = AcxCircuitInitAllocate(Device);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)