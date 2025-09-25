## Description

The **AcxDataFormatListAddDataFormat** function adds an [ACXDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/) object to a data format list.

## Parameters

### `AcxDataFormatList` [in]

The data format list to which *AcxDataFormat* is added.

### `AcxDataFormat` [in]

The [ACXDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/) object to add to *AcxDataFormatList*.

## Return value

The method returns **STATUS_SUCCESS** if the operation succeeds. Otherwise, this method might return an appropriate **[NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values)** error code.

## Remarks

If the data format list doesn't have a default data format, this data format becomes the default data format for that list.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [AcxDataFormatListRemoveDataFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/nf-acxdataformat-acxdataformatlistremovedataformat)
- [KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat)
- [acxdataformat.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/)