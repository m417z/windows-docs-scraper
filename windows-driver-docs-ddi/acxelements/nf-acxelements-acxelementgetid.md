## Description

The **AcxElementGetId** function retrieves the number that represents the element ID for a given ACX element object.

## Parameters

### `Element`

An existing, initialized, ACXELEMENT object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Return value

Returns the ULONG value that represents the element ID for the specified ACXELEMENT object. Will return AcxElementIdNone if the object has no element ID.

## Remarks

### Example

Example usage is shown below.

```cpp
 ULONG id = AcxElementGetId((ACXELEMENT)Mute);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)