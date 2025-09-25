# SetupDiSetDeviceInstallParamsW function

## Description

The **SetupDiSetDeviceInstallParams** function sets device installation parameters for a device information set or a particular device information element.

## Parameters

### `DeviceInfoSet` [in]

A handle to the [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) for which to set device installation parameters.

### `DeviceInfoData` [in, optional]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that specifies a device information element in *DeviceInfoSet*. This parameter is optional and can be set to **NULL**. If this parameter is specified, **SetupDiSetDeviceInstallParams** sets the installation parameters for the specified device. If this parameter is **NULL**, **SetupDiSetDeviceInstallParams** sets the installation parameters that are associated with the global class driver list for *DeviceInfoSet*.

### `DeviceInstallParams` [in]

A pointer to an [SP_DEVINSTALL_PARAMS](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinstall_params_a) structure that contains the new values of the parameters. The *DeviceInstallParams.***cbSize** must be set to the size, in bytes, of the structure before this function is called.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved with a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

All parameters are validated before any changes are made. Therefore, a return value of **FALSE** indicates that no parameters were modified.

> [!NOTE]
> The setupapi.h header defines SetupDiSetDeviceInstallParams as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SetupDiGetDeviceInstallParams](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceinstallparamsa)