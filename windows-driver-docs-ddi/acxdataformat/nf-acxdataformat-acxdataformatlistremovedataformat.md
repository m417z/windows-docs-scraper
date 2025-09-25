## Description

The **AcxDataFormatListRemoveDataFormat** function removes the specified ACX data format from an ACX data format list.

## Parameters

### `AcxDataFormatList` [in]

The ACX data format list from which to remove *AcxDataFormat*.

### `AcxDataFormat` [in]

The [ACXDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/) object to remove from *AcxDataFormatList*.

## Return value

The method returns **STATUS_SUCCESS** if the operation succeeds. Otherwise, this method might return an appropriate **[NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values)** error code.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [AcxDataFormatListAddDataFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/nf-acxdataformat-acxdataformatlistadddataformat)
- [AcxDataFormatListRemoveDataFormats](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/nf-acxdataformat-acxdataformatlistremovedataformats)
- [KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat)
- [acxdataformat.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/)