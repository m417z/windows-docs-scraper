# SetupDiSetSelectedDevice function

## Description

The **SetupDiSetSelectedDevice** function sets a device information element as the selected member of a device information set. This function is typically used by an installation wizard.

## Parameters

### `DeviceInfoSet` [in]

A handle to the [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains the device information element to set as the selected member of the device information set.

### `DeviceInfoData` [in]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that specifies the device information element in *DeviceInfoSet* to set as the selected member of *DeviceInfoSet*.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved with a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[SetupDiGetSelectedDevice](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetselecteddevice)