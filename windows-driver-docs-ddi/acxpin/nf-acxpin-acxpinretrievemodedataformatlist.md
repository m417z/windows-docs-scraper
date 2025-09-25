## Description

The **AcxPinRetrieveModeDataFormatList** function gets the mode data format list for the specified pin.

## Parameters

### `AcxPin` [in]

The pin for which to retrieve the mode data format list.

### `SignalProcessingMode` [in]

The GUID of the signal processing mode for which to retrieve the data format list.

### `DataFormatList` [out]

Pointer to an ACXDATAFORMATLIST to receive the data format list object handle.

## Return value

The method returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [AcxPinRemoveModeDataFormatList](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/nf-acxpin-acxpinremovemodedataformatlist)
- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)