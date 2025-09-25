# SetupDiOpenDevRegKey function

## Description

The **SetupDiOpenDevRegKey** function opens a registry key for device-specific configuration information.

## Parameters

### `DeviceInfoSet` [in]

A handle to the [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains a device information element that represents the device for which to open a registry key.

### `DeviceInfoData` [in]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that specifies the device information element in *DeviceInfoSet*.

### `Scope` [in]

The scope of the registry key to open. The scope determines where the information is stored. The scope can be global or specific to a hardware profile. The scope is specified by one of the following values:

#### DICS_FLAG_GLOBAL

Open a key to store global configuration information. This information is not specific to a particular hardware profile. This opens a key that is rooted at **HKEY_LOCAL_MACHINE.** The exact key opened depends on the value of the *KeyType* parameter.

#### DICS_FLAG_CONFIGSPECIFIC

Open a key to store hardware profile-specific configuration information. This key is rooted at one of the hardware-profile specific branches, instead of **HKEY_LOCAL_MACHINE**. The exact key opened depends on the value of the *KeyType* parameter.

### `HwProfile` [in]

A hardware profile value, which is set as follows:

* If *Scope* is set to DICS_FLAG_CONFIGSPECIFIC, *HwProfile* specifies the hardware profile of the key that is to be opened.
* If *HwProfile* is 0, the key for the current hardware profile is opened.
* If *Scope* is DICS_FLAG_GLOBAL, *HwProfile* is ignored.

### `KeyType` [in]

The type of registry storage key to open, which can be one of the following values:

#### DIREG_DEV

Open a [hardware key](https://learn.microsoft.com/windows-hardware/drivers/) for the device.

#### DIREG_DRV

Open a [software key](https://learn.microsoft.com/windows-hardware/drivers/) for the device.

For more information about a device's hardware and software keys, see [Registry Trees and Keys for Devices and Drivers](https://learn.microsoft.com/windows-hardware/drivers/install/registry-trees-and-keys).

### `samDesired` [in]

The registry security access that is required for the requested key. For information about registry security access values of type REGSAM, see the Microsoft Windows SDK documentation.

## Return value

If the function is successful, it returns a handle to an opened registry key where private configuration data about this device instance can be stored/retrieved.

If the function fails, it returns INVALID_HANDLE_VALUE. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Depending on the value that is passed in the *samDesired* parameter, it might be necessary for the caller of this function to be a member of the Administrators group.

Close the handle returned from this function by calling [RegCloseKey](https://learn.microsoft.com/windows/win32/api/winreg/nf-winreg-regclosekey).

The specified device instance must be registered before this function is called. However, be aware that the operating system automatically registers PnP device instances. For information about how to register non-PnP device instances, see [SetupDiRegisterDeviceInfo](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiregisterdeviceinfo).

## See also

[SetupDiCreateDevRegKey](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicreatedevregkeya)

[SetupDiCreateDeviceInfo](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicreatedeviceinfoa)

[SetupDiGetHwProfileList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigethwprofilelist)

[SetupDiRegisterDeviceInfo](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiregisterdeviceinfo)