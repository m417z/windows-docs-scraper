## Description

The **AcxPinRemoveModeDataFormatList** function deletes the mode data format list for the specified pin.

## Parameters

### `AcxPin` [in]

The pin for which to remove the mode data format list.

### `SignalProcessingMode` [in]

The GUID of the signal processing mode for which to remove the data format list.

### `DataFormatList` [out, optional]

Pointer to an ACXDATAFORMATLIST to receive the data format list object handle.

## Return value

The method returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.1

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [AcxPinRetrieveModeDataFormatList](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/nf-acxpin-acxpinretrievemodedataformatlist)
- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)