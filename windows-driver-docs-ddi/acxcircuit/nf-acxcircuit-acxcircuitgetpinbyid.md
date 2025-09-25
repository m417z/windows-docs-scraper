## Description

When provided a valid PinID number, the **AcxCircuitGetPinById** function returns the AcxCircuitGetPinById function returns the corresponding ACXPIN object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Parameters

### `Circuit`

An existing *ACXCIRCUIT* object.

### `PinId`

A valid Pin ID number.

## Return value

A reference to an existing *ACXPIN* object.

## Remarks

### Example

Example usage is shown below.

```cpp
    const ULONG _BRIDGE_PIN_ID = 1;
    ACXPIN bridgePin = NULL;

    bridgePin = AcxCircuitGetPinById(Circuit, _BRIDGE_PIN_ID);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)