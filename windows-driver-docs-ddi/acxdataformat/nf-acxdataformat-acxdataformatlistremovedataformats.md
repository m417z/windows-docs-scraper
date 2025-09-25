## Description

The **AcxDataFormatListRemoveDataFormats** function removes all data formats from the specified ACX data format list.

## Parameters

### `AcxDataFormatList` [in]

The data format list from which to delete all data formats.

## Return value

The method returns **STATUS_SUCCESS** if the operation succeeds. Otherwise, this method might return an appropriate **[NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values)** error code.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.1

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [AcxDataFormatListRemoveDataFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/nf-acxdataformat-acxdataformatlistremovedataformat)
- [AcxDataFormatListAddDataFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/nf-acxdataformat-acxdataformatlistadddataformat)
- [KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat)
- [acxdataformat.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/)