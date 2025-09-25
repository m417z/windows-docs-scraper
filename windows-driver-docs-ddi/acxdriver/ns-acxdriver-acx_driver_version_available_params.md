## Description

The **ACX_DRIVER_VERSION_AVAILABLE_PARAMS** structure is passed as a parameter to the [AcxDriverIsVersionAvailable](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdriver/nf-acxdriver-acxdriverisversionavailable) function.

## Members

### `Size`

This field is set by the [ACX_DRIVER_VERSION_AVAILABLE_PARAMS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdriver/nf-acxdriver-acx_driver_version_available_params_init) function.

### `MajorVersion`

The major version of the audio driver for which to check.

### `MinorVersion`

The minor version of the audio driver for which to check.

## Remarks

Instances of this structure must be initialized by calling the [ACX_DRIVER_VERSION_AVAILABLE_PARAMS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdriver/nf-acxdriver-acx_driver_version_available_params_init) function. A pointer to an **ACX_DRIVER_VERSION_AVAILABLE_PARAMS** structure is passed as a parameter to the [AcxDriverIsVersionAvailable](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdriver/nf-acxdriver-acxdriverisversionavailable) function.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

* [ACX_DRIVER_VERSION_AVAILABLE_PARAMS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdriver/nf-acxdriver-acx_driver_version_available_params_init)
* [AcxDriverIsVersionAvailable](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdriver/nf-acxdriver-acxdriverisversionavailable)
* [acxdriver.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdriver/)