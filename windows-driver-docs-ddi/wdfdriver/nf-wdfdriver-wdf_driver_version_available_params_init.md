# WDF_DRIVER_VERSION_AVAILABLE_PARAMS_INIT function

## Description

[Applies to KMDF and UMDF]

The WDF_DRIVER_VERSION_AVAILABLE_PARAMS_INIT function initializes a [WDF_DRIVER_VERSION_AVAILABLE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/ns-wdfdriver-_wdf_driver_version_available_params) structure.

## Parameters

### `Params` [out]

A pointer to a [WDF_DRIVER_VERSION_AVAILABLE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/ns-wdfdriver-_wdf_driver_version_available_params) structure.

### `MajorVersion` [in]

A numeric value that represents the Kernel-Mode Driver Framework library's major version number.

### `MinorVersion` [in]

A numeric value that represents the Kernel-Mode Driver Framework library's minor version number.

## Remarks

The WDF_DRIVER_VERSION_AVAILABLE_PARAMS_INIT function zeros the [WDF_DRIVER_VERSION_AVAILABLE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/ns-wdfdriver-_wdf_driver_version_available_params) structure that the *Params* parameter points to and sets the structure's **Size** member. Then, this function sets the structure's **MajorVersion** and **MinorVersion** members to the specified values.

#### Examples

For a code example that uses WDF_DRIVER_VERSION_AVAILABLE_PARAMS_INIT, see [WdfDriverIsVersionAvailable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdriverisversionavailable).

## See also

[WDF_DRIVER_VERSION_AVAILABLE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/ns-wdfdriver-_wdf_driver_version_available_params)