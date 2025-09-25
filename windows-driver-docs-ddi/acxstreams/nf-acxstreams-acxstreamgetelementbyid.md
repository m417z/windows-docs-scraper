## Description

The **AcxStreamGetElementById** function returns the ACXELEMENT Object handle for the requested element ID. For more information about ACX Objects, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Parameters

### `Stream`

An existing ACXSTREAM Object. An ACXSTREAM object represents an audio stream created by a circuit.

### `ElementId`

The Id of the requested element.

## Return value

The ACXELEMENT Object handle of the requested element, or NULL if the ACXSTREAM doesn't have an ACXELEMENT with the given Id.

## Remarks

### Example

Example usage is shown below.

```cpp
    ULONGLONG               index       = GetMessageContext(Event); // Context is an index.
    ACXELEMENT              element     = nullptr;
    //
    // Get the ACX element.
    //
    element = AcxStreamGetElementById(Stream, (ULONG)index);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)