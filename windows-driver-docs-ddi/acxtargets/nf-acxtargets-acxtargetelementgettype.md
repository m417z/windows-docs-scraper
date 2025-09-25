## Description

The **AcxTargetElementGetType** function given an existing ACXTARGETELEMENT object, returns its corresponding element type in the form of a GUID.

## Parameters

### `TargetElement`

An existing ACXTARGETELEMENT Object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Return value

An element type as a GUID.

## Remarks

### Example

```cpp

    ACXTARGETELEMENT targetElement = AcxTargetCircuitGetTargetElement(TargetCircuit, elementIndex);
    GUID elementType = AcxTargetElementGetType(targetElement);

```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxtargets.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxtargets/)