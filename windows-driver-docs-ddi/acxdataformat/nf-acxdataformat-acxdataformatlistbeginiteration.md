## Description

The **AcxDataFormatListBeginIteration** function initializes an [ACX_DATAFORMAT_LIST_ITERATOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/ns-acxdataformat-acx_dataformat_list_iterator) to use for iterating through the specified data format list.

## Parameters

### `AcxDataFormatList` [in]

The data format list to iterate.

### `Iterator` [in, out]

A pointer to an [ACX_DATAFORMAT_LIST_ITERATOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/ns-acxdataformat-acx_dataformat_list_iterator) structure to use for iterating the specified *AcxDataFormatList*.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACX_DATAFORMAT_LIST_ITERATOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/ns-acxdataformat-acx_dataformat_list_iterator)
- [acxdataformat.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/)