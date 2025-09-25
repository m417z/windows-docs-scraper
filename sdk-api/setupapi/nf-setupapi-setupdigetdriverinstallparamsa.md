# SetupDiGetDriverInstallParamsA function

## Description

The **SetupDiGetDriverInstallParams** function retrieves driver installation parameters for a device information set or a particular device information element.

## Parameters

### `DeviceInfoSet` [in]

A handle to a [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains a driver information element that represents the driver for which to retrieve installation parameters.

### `DeviceInfoData` [in, optional]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that contains a device information element that represents the device for which to retrieve installation parameters. This parameter is optional and can be **NULL**. If this parameter is specified, **SetupDiGetDriverInstallParams** retrieves information about a driver that is a member of a driver list for the specified device. If this parameter is **NULL**, **SetupDiGetDriverInstallParams** retrieves information about a driver that is a member of the global class driver list for *DeviceInfoSet*.

### `DriverInfoData` [in]

A pointer to an [SP_DRVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_drvinfo_data_v1_a) structure that specifies the driver information element that represents the driver for which to retrieve installation parameters. If *DeviceInfoData* is supplied, the driver must be a member of the driver list for the device that is specified by *DeviceInfoData*. Otherwise, the driver must be a member of the global class driver list for *DeviceInfoSet*.

### `DriverInstallParams` [out]

A pointer to an [SP_DRVINSTALL_PARAMS](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_drvinstall_params) structure to receive the installation parameters for this driver.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved by a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[SetupDiSetDriverInstallParams](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetdriverinstallparamsa)

## Remarks

> [!NOTE]
> The setupapi.h header defines SetupDiGetDriverInstallParams as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).