# SetupDiSetSelectedDriverA function

## Description

The **SetupDiSetSelectedDriver** function sets, or resets, the selected driver for a device information element or the selected class driver for a device information set.

## Parameters

### `DeviceInfoSet` [in]

A handle to the [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains the driver list from which to select a driver for a device information element or for the device information set.

### `DeviceInfoData` [in, out]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that specifies the device information element in *DeviceInfoSet*. This parameter is optional and can be **NULL**. If this parameter is specified, **SetupDiSetSelectedDriver** sets, or resets, the selected driver for the specified device. If this parameter is **NULL**, **SetupDiSetSelectedDriver** sets, or resets, the selected class driver for *DeviceInfoSet*.

### `DriverInfoData` [in, out]

A pointer to an [SP_DRVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_drvinfo_data_v1_a) structure that specifies the driver to be selected. This parameter is optional and can be **NULL**. If this parameter and *DeviceInfoData* are supplied, the specified driver must be a member of a driver list that is associated with *DeviceInfoData*. If this parameter is specified and *DeviceInfoData* is **NULL**, the driver must be a member of the global class driver list for *DeviceInfoSet*. If this parameter is **NULL**, the selected driver is reset for the device information element, if *DeviceInfoData* is specified, or the device information set, if *DeviceInfoData* is **NULL**.

If the *DriverInfoData.***Reserved** is **NULL**, the caller is requesting a search for a driver node with the specified parameters (**DriverType**, **Description**, and **ProviderName**). If a match is found, that driver node is selected. The **Reserved** field is updated on output to reflect the actual driver node where the match was found. If a match is not found, the function fails and a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_INVALID_PARAMETER.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved with a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the caller of **SetupDiSetSelectedDriver** is a member of the Administrators group, the class of the device is set to the class of the selected driver, provided that the two classes are different.

If *DriverInfoData* is **NULL**, **SetupDiSetSelectedDriver** resets the selected driver. As a result, there is no selected driver.

> [!NOTE]
> The setupapi.h header defines SetupDiSetSelectedDriver as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SetupDiGetSelectedDriver](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetselecteddrivera)