## Description

The **AcxTargetStreamGetWdfIoTarget** function will return a WDFIOTARGET WDF object that is associated with the specified stream.

## Parameters

### `TargetStream`

An existing ACXTARGETSTREAM Object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Return value

Returns the WDFIOTARGET WDF object that is associated with the specified target stream.

## Remarks

### Example

```cpp
WDFIOTARGET
Aggregator_GetTarget(
    _In_ ACXTARGETSTREAM Stream
)
{
    PAGED_CODE();
    return AcxTargetStreamGetWdfIoTarget(Stream);
}
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxtargets.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxtargets/)