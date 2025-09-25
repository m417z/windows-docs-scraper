## Description

The **AcxTargetElementGetNameTag** function given an existing ACXTARGETELEMENT object returns, returns its name-tag in the form of a GUID.

## Parameters

### `TargetElement`

An existing ACXTARGETELEMENT Object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Return value

A name-tag in the form of a GUID.

## Remarks

### Example

```cpp

    GUID elementNameTag;
...

    elementNameTag = AcxTargetElementGetNameTag(targetElement);

```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxtargets.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxtargets/)