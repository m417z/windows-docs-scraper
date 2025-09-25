# SetupDiDestroyDriverInfoList function

## Description

The **SetupDiDestroyDriverInfoList** function deletes a driver list.

## Parameters

### `DeviceInfoSet` [in]

A handle to a [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains the driver list to delete.

### `DeviceInfoData` [in, optional]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that specifies the device information element in *DeviceInfoSet*. This parameter is optional and can be set to **NULL**. If this parameter is specified, **SetupDiDestroyDriverInfoList** deletes the driver list for the specified device. If this parameter is **NULL**, **SetupDiDestroyDriverInfoList** deletes the global class driver list that is associated with *DeviceInfoSet*.

### `DriverType` [in]

The type of driver list to delete, which must be one of the following values:

#### SPDIT_CLASSDRIVER

Delete a list of class drivers. If *DeviceInfoData* is **NULL**, this driver list type must be specified.

#### SPDIT_COMPATDRIVER

Delete a list of compatible drivers for the specified device. *DeviceInfoData* must be specified if this driver list type is specified.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved with a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the currently selected driver is a member of the list being deleted, the selection is reset.

If a class driver list is being deleted, the DI_FLAGSEX_DIDINFOLIST and DI_DIDCLASS flags are reset for the corresponding device information set or device information element. The DI_MULTMFGS flags is also reset.

If a compatible driver list is being destroyed, the DI_FLAGSEX_DIDCOMPATINFO and DI_DIDCOMPAT flags are reset for the corresponding device information element.

## See also

[SetupDiBuildDriverInfoList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdibuilddriverinfolist)