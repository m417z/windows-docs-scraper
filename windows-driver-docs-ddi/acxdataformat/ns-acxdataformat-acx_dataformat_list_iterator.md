## Description

The **ACX_DATAFORMAT_LIST_ITERATOR** structure holds the state of iteration over an ACX data format list.

## Members

### `Size`

The size of all of the data in the **ACX_DATAFORMAT_LIST_ITERATOR** structure in bytes. This field is set by the [ACX_DATAFORMAT_LIST_ITERATOR_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/nf-acxdataformat-acx_dataformat_list_iterator_init) function.

### `Flags`

A combination of values from the [ACX_DATAFORMAT_LIST_ITERATOR_CONFIG_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/ne-acxdataformat-acx_dataformat_list_iterator_config_flags) enum that describe the data format list iterator.

### `Reserved`

Reserved.

## Remarks

This structure should not be directly updated. Instances of the **ACX_DATAFORMAT_LIST_ITERATOR** structure must be initialized by calling the [ACX_DATAFORMAT_LIST_ITERATOR_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/nf-acxdataformat-acx_dataformat_list_iterator_init) function.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACX_DATAFORMAT_LIST_ITERATOR_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/nf-acxdataformat-acx_dataformat_list_iterator_init)
- [ACX_DATAFORMAT_LIST_ITERATOR_CONFIG_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/ne-acxdataformat-acx_dataformat_list_iterator_config_flags)
- [acxdataformat.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/)