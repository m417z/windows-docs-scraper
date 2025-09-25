## Description

The **AcxPinAssignModeDataFormatList** function assigns a mode data format list to the specified pin.

## Parameters

### `AcxPin` [in]

The pin to which the mode data format list is assigned.

### `SignalProcessingMode` [in]

A GUID identifying the signal processing mode to which the specified data format list belong.

### `DataFormatList` [in]

The data format list to assign for the specified *SignalProcessingMode*.

## Return value

The method returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)