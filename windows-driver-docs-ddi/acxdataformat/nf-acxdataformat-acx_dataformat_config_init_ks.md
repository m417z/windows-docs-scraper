## Description

The **ACX_DATAFORMAT_CONFIG_INIT_KS** function initializes an [ACX_DATAFORMAT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/ns-acxdataformat-acx_dataformat_config) structure using a KS data format.

## Parameters

### `Config` [out]

A pointer to the [ACX_DATAFORMAT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/ns-acxdataformat-acx_dataformat_config) structure to initialize.

### `Format` [in]

A pointer to the [KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat).

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACX_DATAFORMAT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/ns-acxdataformat-acx_dataformat_config)
- [KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat)
- [ACX_DATAFORMAT_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/nf-acxdataformat-acx_dataformat_config_init)
- [acxdataformat.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/)