## Description

The **AcxTargetPinGetId** function given an existing ACXTARGETPIN object returns its associated ID value.

## Parameters

### `TargetPin`

An existing ACXTARGETPIN Object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Return value

Returns the ID associated with the specified target pin.

## Remarks

### Example

```cpp

     ACXTARGETPIN targetPin = AcxTargetCircuitGetTargetPin(TargetCircuit, pinIndex);
     ULONG pinId = AcxTargetPinGetId(targetPin);

```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxtargets.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxtargets/)