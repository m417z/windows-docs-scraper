# _WDF_DRIVER_VERSION_AVAILABLE_PARAMS structure

## Description

[Applies to KMDF and UMDF]

The WDF_DRIVER_VERSION_AVAILABLE_PARAMS structure specifies major and minor version numbers for the Kernel-Mode Driver Framework's library.

## Members

### `Size`

The size, in bytes, of this structure.

### `MajorVersion`

A numeric value that represents the Kernel-Mode Driver Framework library's major version number.

### `MinorVersion`

A numeric value that represents the Kernel-Mode Driver Framework library's minor version number.

## Remarks

The WDF_DRIVER_VERSION_AVAILABLE_PARAMS structure is used as input to the [WdfDriverIsVersionAvailable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdriverisversionavailable) method. Drivers should call [WDF_DRIVER_VERSION_AVAILABLE_PARAMS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdf_driver_version_available_params_init) to initialize this structure before calling **WdfDriverIsVersionAvailable**.

## See also

[WDF_DRIVER_VERSION_AVAILABLE_PARAMS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdf_driver_version_available_params_init)

[WdfDriverIsVersionAvailable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdriverisversionavailable)