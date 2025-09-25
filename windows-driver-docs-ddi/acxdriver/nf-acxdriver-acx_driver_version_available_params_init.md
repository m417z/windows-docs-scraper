## Description

The **ACX_DRIVER_VERSION_AVAILABLE_PARAMS_INIT** function initializes an [ACX_DRIVER_VERSION_AVAILABLE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdriver/ns-acxdriver-acx_driver_version_available_params) structure before calling the [AcxDriverIsVersionAvailable](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdriver/nf-acxdriver-acxdriverisversionavailable) function.

## Parameters

### `Params`

Pointer to an [ACX_DRIVER_VERSION_AVAILABLE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdriver/ns-acxdriver-acx_driver_version_available_params) structure.

### `MajorVersion`

The major version of the audio driver for which to check.

### `MinorVersion`

The minor version of the audio driver for which to check.

## Remarks

### Example

```cpp
ACX_DRIVER_VERSION_AVAILABLE_PARAMS ver;
ACX_DRIVER_VERSION_AVAILABLE_PARAMS_INIT(&ver, 1, 0);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

* [ACX_DRIVER_VERSION_AVAILABLE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdriver/ns-acxdriver-acx_driver_version_available_params)
* [AcxDriverIsVersionAvailable](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdriver/nf-acxdriver-acxdriverisversionavailable)
* [acxdriver.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdriver/)