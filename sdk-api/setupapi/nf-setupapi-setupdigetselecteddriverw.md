# SetupDiGetSelectedDriverW function

## Description

The **SetupDiGetSelectedDriver** function retrieves the selected driver for a device information set or a particular device information element.

## Parameters

### `DeviceInfoSet` [in]

A handle to the [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) for which to retrieve a selected driver.

### `DeviceInfoData` [in, optional]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that specifies a device information element that represents the device in *DeviceInfoSet* for which to retrieve the selected driver. This parameter is optional and can be **NULL**. If this parameter is specified, **SetupDiGetSelectedDriver** retrieves the selected driver for the specified device. If this parameter is **NULL**, **SetupDiGetSelectedDriver** retrieves the selected class driver in the global class driver list that is associated with *DeviceInfoSet*.

### `DriverInfoData` [out]

A pointer to an [SP_DRVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_drvinfo_data_v1_a) structure that receives information about the selected driver.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved with a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror). If a driver has not been selected for the specified device instance, the logged error is ERROR_NO_DRIVER_SELECTED.

## See also

[SetupDiSetSelectedDriver](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetselecteddrivera)

## Remarks

> [!NOTE]
> The setupapi.h header defines SetupDiGetSelectedDriver as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).