## Description

The **AcxDriverInitialize** function initializes the specified audio driver.

## Parameters

### `Driver`

The **WDFDRIVER** object representing the audio driver to initialize.

### `DriverConfig`

Pointer to a [ACX_DRIVER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdriver/ns-acxdriver-acx_driver_config) structure that was previously initialized by calling the [ACX_DRIVER_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdriver/nf-acxdriver-acx_driver_config_init) function.

## Return value

**AcxDriverInitialize** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) error code.

## Remarks

### Example

```cpp
ACX_DRIVER_CONFIG acxCfg;
WDFDRIVER         driver;
NTSTATUS          status;

// Code to initialize the WDFDRIVER object...

// Initialize the audio driver configuration
ACX_DRIVER_CONFIG_INIT(&acxCfg);

// Initialize the audio driver
status = AcxDriverInitialize(driver, &acxCfg);

if (!NT_SUCCESS(status))
{
    // Log error...

    goto exit;
}
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACX_DRIVER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdriver/ns-acxdriver-acx_driver_config)
- [ACX_DRIVER_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdriver/nf-acxdriver-acx_driver_config_init)
- [acxdriver.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdriver/)