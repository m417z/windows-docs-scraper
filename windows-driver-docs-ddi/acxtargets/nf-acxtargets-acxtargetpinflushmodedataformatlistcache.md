## Description

The **AcxTargetPinFlushModeDataFormatListCache** function flushes the mode data format list cache for the specified target pin.

## Parameters

### `TargetPin` [in]

The target pin for which to flush the mode data format list cache.

### `SignalProcessingMode` [in, optional]

The optional signal processing mode of the TargetPin.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

Example usage is shown below.

```cpp
...
    _In_    ACXTARGETCIRCUIT TargetCircuit,
    _In_    ULONG            TargetPinId
    )

...

    //
    // Flush the target data-format cache.
    //
    AcxTargetPinFlushModeDataFormatListCache(
        AcxTargetCircuitGetTargetPin(TargetCircuit, TargetPinId),
        NULL);
```

### ACX requirements

**Minimum ACX version:** 1.1

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxtargets.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxtargets/)