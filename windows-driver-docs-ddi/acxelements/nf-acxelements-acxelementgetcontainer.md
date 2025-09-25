## Description

The **AcxElementGetContainer** function retrieves the associated container for the given ACX element. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Parameters

### `Element`

An existing, initialized, ACXELEMENT object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Return value

Returns the ACXOBJECT object that is the container for the specified ACX element.

## Remarks

### Example

Example usage is shown below.

```cpp
    ACXCIRCUIT circuit = (ACXCIRCUIT)AcxElementGetContainer((ACXELEMENT)Mute);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)