# SetupDiCreateDevRegKeyA function

## Description

The **SetupDiCreateDevRegKey** function creates a registry key for device-specific configuration information and returns a handle to the key.

## Parameters

### `DeviceInfoSet` [in]

A handle to a [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains a device information element that represents the device for which to create a registry key.

### `DeviceInfoData` [in]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that specifies the device information element in *DeviceInfoSet*.

### `Scope` [in]

The scope of the registry key to be created. The scope determines where the information is stored. The key created can be global or hardware profile-specific. Can be one of the following values:

#### DICS_FLAG_GLOBAL

Create a key to store global configuration information. This information is not specific to a particular hardware profile. On NT-based operating systems this creates a key that is rooted at **HKEY_LOCAL_MACHINE**. The exact key opened depends on the value of the *KeyType* parameter.

#### DICS_FLAG_CONFIGSPECIFIC

Create a key to store hardware profile-specific configuration information. This key is rooted at one of the hardware-profile specific branches, instead of **HKEY_LOCAL_MACHINE**.

### `HwProfile` [in]

The hardware profile for which to create a key if *HwProfileFlags* is set to SPDICS_FLAG_CONFIGSPECIFIC. If *HwProfile* is 0, the key for the current hardware profile is created. If *HwProfileFlags* is SPDICS_FLAG_GLOBAL, *HwProfile* is ignored.

### `KeyType` [in]

The type of registry storage key to create. Can be one of the following values:

#### DIREG_DEV

Create a [hardware key](https://learn.microsoft.com/windows-hardware/drivers/) for the device.

#### DIREG_DRV

Create a [software key](https://learn.microsoft.com/windows-hardware/drivers/) for the device.

### `InfHandle` [in, optional]

The handle to an open INF file that contains an [INF DDInstall section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-ddinstall-section) to be executed for the newly created key. This parameter is optional and can be **NULL**. If this parameter is specified, *InfSectionName* must be specified as well.

### `InfSectionName` [in, optional]

The name of an INF *DDInstall* section in the INF file specified by *InfHandle*. This section is executed for the newly created key. This parameter is optional and can be **NULL**. If this parameter is specified, *InfHandle* must be specified as well.

## Return value

If **SetupDiCreateDevRegKey** succeeds, the function returns a handle to the specified registry key in which device-specific configuration data can be stored and retrieved. If **SetupDiCreateDevRegKey** fails, the function returns INVALID_HANDLE_VALUE. Call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) to get extended error information.

## Remarks

The caller of **SetupDiCreateDevRegKey** must be a member of the Administrators group.

Close the handle returned from **SetupDiCreateDevRegKey** by calling [RegCloseKey](https://learn.microsoft.com/windows/win32/api/winreg/nf-winreg-regclosekey).

If the specified key already exists, **SetupDiCreateDevRegKey** returns a handle to that key. Otherwise, **SetupDiCreateDevRegKey** creates the specified key and returns a handle to the new key. For Windows Server 2003 and later versions of Windows, the key handle has KEY_READ and KEY_WRITE access only. For previous Windows versions, this handle has KEY_ALL_ACCESS access.

The specified device instance must be registered before **SetupDiCreateDevRegKey** is called. Note, however, that the operating system automatically registers PnP device instances. For information about how to register non-PnP device instances, see [SetupDiRegisterDeviceInfo](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiregisterdeviceinfo).

For installations that use layout files (specified by the **LayoutFile** entry in an [INF Version section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-version-section)), the layout file must be opened by a call to **SetupOpenAppendInfFile** (described in the Microsoft Windows SDK documentation) before **SetupDiCreateDevRegKey** is called.

If the supplied device information set contains device information elements for a remote system, and *InfHandle* and *InfSectionName* are also specified, the create request will fail, and a subsequent call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) will return ERROR_REMOTE_REQUEST_UNSUPPORTED.

> [!NOTE]
> The setupapi.h header defines SetupDiCreateDevRegKey as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SetupDiCreateDeviceInfo](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicreatedeviceinfoa)

[SetupDiGetHwProfileList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigethwprofilelist)

[SetupDiOpenDevRegKey](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiopendevregkey)

[SetupDiRegisterDeviceInfo](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiregisterdeviceinfo)