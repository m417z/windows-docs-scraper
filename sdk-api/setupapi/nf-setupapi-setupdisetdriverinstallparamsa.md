# SetupDiSetDriverInstallParamsA function

## Description

The **SetupDiSetDriverInstallParams** function sets driver installation parameters for a driver information element.

## Parameters

### `DeviceInfoSet` [in]

A handle to a [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains a driver information element that represents the driver for which to set installation parameters.

### `DeviceInfoData` [in, optional]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that specifies a device information element in *DeviceInfoSet*. This parameter is optional and can be set to **NULL**. If this parameter is specified, **SetupDiSetDriverInstallParams** sets the driver installation parameters for the specified device. If this parameter is **NULL**, **SetupDiSetDriverInstallParams** sets driver installation parameters for *DeviceInfoSet*.

### `DriverInfoData` [in]

A pointer to an [SP_DRVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_drvinfo_data_v1_a) structure that specifies the driver for which installation parameters are set. If *DeviceInfoData* is specified, this driver must be a member of a driver list that is associated with *DeviceInfoData*. If *DeviceInfoData* is **NULL**, this driver must be a member of the global class driver list for *DeviceInfoSet*.

### `DriverInstallParams` [in]

A pointer to an [SP_DRVINSTALL_PARAMS](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_drvinstall_params) structure that specifies the new driver install parameters.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved by a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[SetupDiGetDriverInstallParams](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdriverinstallparamsa)

## Remarks

> [!NOTE]
> The setupapi.h header defines SetupDiSetDriverInstallParams as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).