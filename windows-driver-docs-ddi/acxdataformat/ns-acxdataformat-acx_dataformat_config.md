## Description

The **ACX_DATAFORMAT_CONFIG** structure is used to configure a new ACX data format object.

## Members

### `Size`

The size of all of the data in the **ACX_DATAFORMAT_CONFIG** structure in bytes. This field is set by the [ACX_DATAFORMAT_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/nf-acxdataformat-acx_dataformat_config_init) function.

### `Flags`

A combination of values from the [ACX_DATAFORMAT_CONFIG_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/ne-acxdataformat-acx_dataformat_config_flags) enum that describe the data format.

### `Type`

An [ACX_DATAFORMAT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/ne-acxdataformat-acx_dataformat_type) enum value that specifies the type of the data format.

### `u`

Union of pointers to supported data formats.

### `u.KsFormat`

Pointer to the [KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat) for this ACX data format.

## Remarks

Instances of the **ACX_DATAFORMAT_CONFIG** structure must be initialized by calling the [ACX_DATAFORMAT_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/nf-acxdataformat-acx_dataformat_config_init) function.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACX_DATAFORMAT_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/nf-acxdataformat-acx_dataformat_config_init)
- [ACX_DATAFORMAT_CONFIG_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/ne-acxdataformat-acx_dataformat_config_flags)
- [ACX_DATAFORMAT_CONFIG_INIT_KS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/nf-acxdataformat-acx_dataformat_config_init_ks)
- [acxdataformat.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/)