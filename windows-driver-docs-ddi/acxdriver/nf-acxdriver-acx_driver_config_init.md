## Description

The **ACX_DRIVER_CONFIG_INIT** function initializes an [ACX_DRIVER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdriver/ne-acxdriver-acx_driver_config_flags) structure before calling the [AcxDriverInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdriver/nf-acxdriver-acxdriverinitialize) function.

## Parameters

### `Config`

Pointer to an [ACX_DRIVER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdriver/ne-acxdriver-acx_driver_config_flags) structure.

## Remarks

### Example

```cpp
ACX_DRIVER_CONFIG acxCfg;
ACX_DRIVER_CONFIG_INIT(&acxCfg);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

* [ACX_DRIVER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdriver/ne-acxdriver-acx_driver_config_flags)
* [AcxDriverInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdriver/nf-acxdriver-acxdriverinitialize)
* [acxdriver.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdriver/)