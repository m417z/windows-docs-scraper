# SetupDiRegisterCoDeviceInstallers function

## Description

The **SetupDiRegisterCoDeviceInstallers** function is the default handler for [DIF_REGISTER_COINSTALLERS](https://learn.microsoft.com/windows-hardware/drivers/install/dif-register-coinstallers).

## Parameters

### `DeviceInfoSet` [in]

A handle to the [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains a device information element that represents the device for which to register co-installers. The device information set must not contain any remote elements.

### `DeviceInfoData` [in]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that specifies the device information element in *DeviceInfoSet*.

## Return value

**SetupDiRegisterCoDeviceInstallers** returns **TRUE** if the function succeeds. If the function returns **FALSE**, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) for extended error information.

## Remarks

The caller of **SetupDiRegisterCoDeviceInstallers** must be a member of the Administrators group.

**Note** Only a class installer should call **SetupDiRegisterCoDeviceInstallers** and only in those situations where the class installer must perform co-installer registration operations after **SetupDiRegisterCoDeviceInstallers** completes the default co-installer registration operation. In such situations, the class installer must directly call **SetupDiRegisterCoDeviceInstallers** when the installer processes a DIF_REGISTER_COINSTALLERS request. For more information about calling the default handler, see [Calling Default DIF Code Handlers](https://learn.microsoft.com/windows-hardware/drivers/install/calling-the-default-dif-code-handlers).

**SetupDiRegisterCoDeviceInstallers** reads the INF file for the device specified by *DeviceInfoData* and creates registry entries to register any device-specific co-installers listed in the INF file. Co-installers are listed in an [INF DDInstall.CoInstallers section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-ddinstall-coinstallers-section). This function also copies the files for the co-installers, unless the DI_NOFILECOPY flag is set.

If there is no driver selected, or the device has an INF file for Windows 9x or Millennium Edition, this function does not register any co-installers.

Registering a new device-specific co-installer invalidates the Device Installer's current list of co-installers. After a successful registration, the Device Installer updates its list of co-installers.

This function only registers device-specific co-installers, not class co-installers.

For more information about how to write and register device-specific co-installers, see [Writing a Co-installer](https://learn.microsoft.com/windows-hardware/drivers/install/writing-a-co-installer).

The device information set specified by *DeviceInfoSet* must only contain elements on the local computer.

## See also

[DIF_REGISTER_COINSTALLERS](https://learn.microsoft.com/windows-hardware/drivers/install/dif-register-coinstallers)

[SetupDiCallClassInstaller](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicallclassinstaller)