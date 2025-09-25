## Description

When provided a valid ElementID number, the **AcxCircuitGetElementById** function returns the corresponding ACXELEMENT object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Parameters

### `Circuit`

An existing ACXCIRCUIT object.

### `ElementId`

A valid Element ID number.

## Return value

The requested ACXELEMENT object associated with the provided element ID number.

## Remarks

### Example

Example usage is shown below.

```cpp
    ACXELEMENT              element     = nullptr;
    ULONGLONG               index       = GetMessageContext(Event); // Context is an index.

    element = AcxCircuitGetElementById(Circuit, (ULONG)index);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)