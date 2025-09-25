# SetupDiGetDeviceInstallParamsA function

## Description

The **SetupDiGetDeviceInstallParams** function retrieves device installation parameters for a device information set or a particular device information element.

## Parameters

### `DeviceInfoSet` [in]

A handle to the [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains the device installation parameters to retrieve.

### `DeviceInfoData` [in, optional]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that specifies the device information element in *DeviceInfoSet*. This parameter is optional and can be **NULL**. If this parameter is specified, **SetupDiGetDeviceInstallParams** retrieves the installation parameters for the specified device. If this parameter is **NULL**, the function retrieves the global device installation parameters that are associated with *DeviceInfoSet*.

### `DeviceInstallParams` [out]

A pointer to an [SP_DEVINSTALL_PARAMS](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinstall_params_a) structure that receives the device install parameters. *DeviceInstallParams*.**cbSize** must be set to the size, in bytes, of the structure before calling this function.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved by making a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data)

[SP_DEVINSTALL_PARAMS](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinstall_params_a)

[SetupDiSetDeviceInstallParams](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetdeviceinstallparamsa)

## Remarks

> [!NOTE]
> The setupapi.h header defines SetupDiGetDeviceInstallParams as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).