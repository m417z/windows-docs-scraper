## Description

The **ACX_DRIVER_CONFIG** structure provides configuration information to the class extension.

## Members

### `Size`

This field is set by the [ACX_DRIVER_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdriver/nf-acxdriver-acx_driver_config_init) function.

### `Flags`

An [ACX_DRIVER_CONFIG_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdriver/ne-acxdriver-acx_driver_config_flags) value.

## Remarks

Instances of this structure must be initialized by calling the [ACX_DRIVER_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdriver/nf-acxdriver-acx_driver_config_init) function. A pointer to an **ACX_DRIVER_CONFIG** structure is passed as a parameter to the [AcxDriverInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdriver/nf-acxdriver-acxdriverinitialize) function.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

* [ACX_DRIVER_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdriver/nf-acxdriver-acx_driver_config_init)
* [ACX_DRIVER_CONFIG_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdriver/ne-acxdriver-acx_driver_config_flags)
* [AcxDriverInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdriver/nf-acxdriver-acxdriverinitialize)
* [acxdriver.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdriver/)