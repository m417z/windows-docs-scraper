## Description

The **AcxTargetPinRetrieveModeDataFormatList** function given an existing ACXTARGETPIN object, returns the ACXDATAFORMATLIST associated to the specified signal-processing-mode data format list.

## Parameters

### `TargetPin`

An existing ACXTARGETPIN Object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `SignalProcessingMode`

A GUID identifying the signal processing mode to which the specified data format list belong.

### `DataFormatList`

Pointer to a location receiving an ACXDATAFORMATLIST handle. For more information about signal processing modes, [Audio Signal Processing Modes](https://learn.microsoft.com/windows-hardware/drivers/audio/audio-signal-processing-modes).

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxtargets.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxtargets/)