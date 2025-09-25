# SetupDiGetSelectedDevice function

## Description

The **SetupDiGetSelectedDevice** function retrieves the selected device information element in a device information set.

## Parameters

### `DeviceInfoSet` [in]

A handle to the [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) for which to retrieve the selected device information element.

### `DeviceInfoData` [out]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that receives information about the selected device information element for *DeviceInfoSet*. The caller must set *DeviceInfoData.***cbSize** to **sizeof**(SP_DEVINFO_DATA). If a device is currently not selected, the function fails and a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_NO_DEVICE_SELECTED.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved with a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**SetupDiGetSelectedDevice** is usually used by an installation wizard.

## See also

[SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data)

[SetupDiSetSelectedDevice](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetselecteddevice)