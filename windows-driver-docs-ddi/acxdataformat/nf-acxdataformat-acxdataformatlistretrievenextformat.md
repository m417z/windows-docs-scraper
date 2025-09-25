## Description

The **AcxDataFormatListRetrieveNextFormat** function gets the next ACX data format when iterating an ACX data format list.

## Parameters

### `AcxDataFormatList` [in]

The ACX data format list from which to get the next [ACXDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/) object.

### `Iterator` [in, out]

Pointer to the [ACX_DATAFORMAT_LIST_ITERATOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/ns-acxdataformat-acx_dataformat_list_iterator) structure used to iterate *AcxDataFormatList*.

### `Format` [out]

Pointer to the next [ACXDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/) object in *AcxDataFormatList*.

## Return value

The method returns **STATUS_SUCCESS** if the operation succeeds. Otherwise, this method might return an appropriate **[NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values)** error code.

## Remarks

After **AcxDataFormatListRetrieveNextFormat** returns, *Iterator* is updated to point to the next data format in the list after *Format*.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACXDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/)
- [ACX_DATAFORMAT_LIST_ITERATOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/ns-acxdataformat-acx_dataformat_list_iterator)
- [AcxDataFormatListBeginIteration](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/nf-acxdataformat-acxdataformatlistbeginiteration)
- [AcxDataFormatListEndIteration](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/nf-acxdataformat-acxdataformatlistenditeration)
- [AcxDataFormatListRemoveDataFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/nf-acxdataformat-acxdataformatlistremovedataformat)
- [AcxDataFormatListRetrieveDefaultDataFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/nf-acxdataformat-acxdataformatlistretrievedefaultdataformat)
- [acxdataformat.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/)