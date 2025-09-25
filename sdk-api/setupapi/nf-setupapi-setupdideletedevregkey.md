# SetupDiDeleteDevRegKey function

## Description

The **SetupDiDeleteDevRegKey** function deletes specified user-accessible registry keys that are associated with a device information element.

## Parameters

### `DeviceInfoSet` [in]

A handle to the [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains a device information element that represents the device for which to delete registry keys. The device information set must not contain remote elements.

### `DeviceInfoData` [in]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that specifies the device information element in *DeviceInfoSet*.

### `Scope` [in]

The scope of the registry key to delete. The scope indicates where the information is located. The key can be global or hardware profile-specific. Can be one of the following values:

#### DICS_FLAG_GLOBAL

Delete the key that stores global configuration information.

#### DICS_FLAG_CONFIGSPECIFIC

Delete the key that stores hardware profile-specific configuration information.

### `HwProfile` [in]

If *Scope* is set to DICS_FLAG_CONFIGSPECIFIC, the *HwProfile* parameter specifies the hardware profile for which to delete the registry key. If *HwProfile* is 0, the key for the current hardware profile is deleted. If *HwProfile* is 0xFFFFFFFF, the registry key for all hardware profiles is deleted.

### `KeyType` [in]

The type of registry storage key to delete. Can be one of the following values:

#### DIREG_DEV

Delete the device's [hardware key](https://learn.microsoft.com/windows-hardware/drivers/).

#### DIREG_DRV

Delete the device's [software key](https://learn.microsoft.com/windows-hardware/drivers/).

#### DIREG_BOTH

Delete both the hardware and software keys for the device.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved with a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The caller of this function must be a member of the Administrators group.

The *DeviceInfoSet* must only contain elements on the local computer.

## See also

[SetupDiCreateDevRegKey](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicreatedevregkeya)

[SetupDiGetHwProfileList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigethwprofilelist)