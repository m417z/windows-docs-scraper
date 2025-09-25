# SetupDiEnumDriverInfoW function

## Description

The **SetupDiEnumDriverInfo** function enumerates the members of a driver list.

## Parameters

### `DeviceInfoSet` [in]

A handle to the [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains the driver list to enumerate.

### `DeviceInfoData` [in, optional]

 A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that specifies a device information element in *DeviceInfoSet*. This parameter is optional and can be **NULL**. If this parameter is specified, **SetupDiEnumDriverInfo** enumerates a driver list for the specified device. If this parameter is **NULL**, **SetupDiEnumDriverInfo** enumerates the global class driver list that is associated with *DeviceInfoSet* (this list is of type SPDIT_CLASSDRIVER).

### `DriverType` [in]

The type of driver list to enumerate, which must be one of the following values:

#### SPDIT_CLASSDRIVER

Enumerate a class driver list. This driver list type must be specified if *DeviceInfoData* is not specified.

#### SPDIT_COMPATDRIVER

Enumerate a list of compatible drivers for the specified device. This driver list type can be specified only if *DeviceInfoData* is also specified.

### `MemberIndex` [in]

The zero-based index of the driver information member to retrieve.

### `DriverInfoData` [out]

A pointer to a caller-initialized [SP_DRVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_drvinfo_data_v2_w) structure that receives information about the enumerated driver. The caller must set *DriverInfoData.***cbSize** to **sizeof(**SP_DRVINFO_DATA**)** before calling **SetupDiEnumDriverInfo**. If the **cbSize** member is not properly set, **SetupDiEnumDriverInfo** will return **FALSE**.

##### - DriverType.SPDIT_CLASSDRIVER

Enumerate a class driver list. This driver list type must be specified if *DeviceInfoData* is not specified.

##### - DriverType.SPDIT_COMPATDRIVER

Enumerate a list of compatible drivers for the specified device. This driver list type can be specified only if *DeviceInfoData* is also specified.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved with a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To enumerate driver information set members, an installer should first call **SetupDiEnumDriverInfo** with the *MemberIndex* parameter set to 0. It should then increment *MemberIndex* and call **SetupDiEnumDriverInfo** until there are no more values. When there are no more values, the function fails and a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_NO_MORE_ITEMS.

If you do not properly initialize the **cbSize** member of the SP_DRVINFO_DATA structure that is supplied by the pointer *DriverInfoData*, the function will fail and log the error ERROR_INVALID_USER_BUFFER.

To build a list of drivers associated with a specific device or with the global class driver list for a device information set first use [SetupDiBuildDriverInfoList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdibuilddriverinfolist) then pass that list to **SetupDiEnumDriverInfo**.

> [!NOTE]
> The setupapi.h header defines SetupDiEnumDriverInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SetupDiBuildDriverInfoList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdibuilddriverinfolist)