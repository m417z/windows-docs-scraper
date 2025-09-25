## Description

The **ACX_DATAFORMAT_LIST_CONFIG** structure is used to configure a new ACX data format list object.

## Members

### `Size`

The size of all of the data in the **ACX_DATAFORMAT_LIST_CONFIG** structure in bytes. This field is set by the [ACX_DATAFORMAT_LIST_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/nf-acxdataformat-acx_dataformat_list_config_init) function.

### `Flags`

A combination of values from the [ACX_DATAFORMAT_LIST_CONFIG_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/ne-acxdataformat-acx_dataformat_list_config_flags) enum that describe the data format list.

## Remarks

Instances of the **ACX_DATAFORMAT_LIST_CONFIG** structure must be initialized by calling the [ACX_DATAFORMAT_LIST_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/nf-acxdataformat-acx_dataformat_list_config_init) function.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACX_DATAFORMAT_LIST_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/nf-acxdataformat-acx_dataformat_list_config_init)
- [ACX_DATAFORMAT_LIST_CONFIG_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/ne-acxdataformat-acx_dataformat_list_config_flags)
- [acxdataformat.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/)