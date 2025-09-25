# SetupDiGetDriverInfoDetailA function

## Description

The **SetupDiGetDriverInfoDetail** function retrieves driver information detail for a device information set or a particular device information element in the device information set.

## Parameters

### `DeviceInfoSet` [in]

A handle to a [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains a driver information element for which to retrieve driver information.

### `DeviceInfoData` [in, optional]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that specifies a device information element that represents the device for which to retrieve driver information. This parameter is optional and can be **NULL**. If this parameter is specified, **SetupDiGetDriverInfoDetail** retrieves information about a driver in a driver list for the specified device. If this parameter is **NULL**, **SetupDiGetDriverInfoDetail** retrieves information about a driver that is a member of the global class driver list for *DeviceInfoSet*.

### `DriverInfoData` [in]

A pointer to an [SP_DRVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_drvinfo_data_v1_a) structure that specifies the driver information element that represents the driver for which to retrieve details. If *DeviceInfoData* is specified, the driver must be a member of the driver list for the device that is specified by *DeviceInfoData*. Otherwise, the driver must be a member of the global class driver list for *DeviceInfoSet*.

### `DriverInfoDetailData` [in, out]

A pointer to an [SP_DRVINFO_DETAIL_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_drvinfo_detail_data_a) structure that receives detailed information about the specified driver. If this parameter is not specified, *DriverInfoDetailDataSize* must be zero. If this parameter is specified, *DriverInfoDetailData.***cbSize** must be set to the value of **sizeof(**SP_DRVINFO_DETAIL_DATA**)** before it calls **SetupDiGetDriverInfoDetail**.

**Note** *DriverInfoDetailData.***cbSize** must not be set to the value of the *DriverInfoDetailDataSize*  parameter*.*

### `DriverInfoDetailDataSize` [in]

The size, in bytes, of the *DriverInfoDetailData* buffer.

### `RequiredSize` [out, optional]

A pointer to a variable that receives the number of bytes required to store the detailed driver information. This value includes both the size of the structure and the additional bytes required for the variable-length character buffer at the end that holds the hardware ID list and the compatible ID list. The lists are in REG_MULTI_SZ format. For information about hardware and compatible IDs, see [Device Identification Strings](https://learn.microsoft.com/windows-hardware/drivers/install/device-identification-strings).

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved by making a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the specified driver information member and the caller-supplied buffer are both valid, this function is guaranteed to fill in all static fields in the SP_DRVINFO_DETAIL_DATA structure and as many IDs as possible in the variable-length buffer at the end while still maintaining REG_MULTI_SZ format. In this case, the function returns **FALSE** and a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_INSUFFICIENT_BUFFER. If specified, *RequiredSize* contains the total number of bytes required for the structure with all IDs.

> [!NOTE]
> The setupapi.h header defines SetupDiGetDriverInfoDetail as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SetupDiEnumDriverInfo](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdienumdriverinfoa)

[SetupDiGetSelectedDriver](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetselecteddrivera)