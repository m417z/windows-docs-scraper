## Description

The **AcxDataFormatListRetrieveDefaultDataFormat** gets the default ACX data format from the specified ACX data format list.

## Parameters

### `AcxDataFormatList` [in]

The ACX data format list from which to get the default ACX data format.

### `AcxDataFormat` [out]

Pointer to the default [ACXDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/) object for the *AcxDataFormatList*.

## Return value

The method returns **STATUS_SUCCESS** if the operation succeeds. Otherwise, this method might return an appropriate **[NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values)** error code.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACXDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/)
- [KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat)
- [acxdataformat.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/)