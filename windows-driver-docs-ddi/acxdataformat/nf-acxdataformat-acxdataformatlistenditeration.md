## Description

The **AcxDataFormatListEndIteration** function ends the iteration process on an ACX data format list.

## Parameters

### `AcxDataFormatList` [in]

The data format list being iterated.

### `Iterator` [in, out]

Pointer to the [ACX_DATAFORMAT_LIST_ITERATOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/ns-acxdataformat-acx_dataformat_list_iterator) structure being used for iteration on *AcxDataFormatList*.

## Remarks

The memory for the *Iterator* is zeroed out by this function and cannot be recovered.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACX_DATAFORMAT_LIST_ITERATOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/ns-acxdataformat-acx_dataformat_list_iterator)
- [acxdataformat.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/)