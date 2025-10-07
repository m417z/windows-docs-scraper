# InstallSelectedDriver function

The **InstallSelectedDriver** function is deprecated. For Windows Vista and later, use [**DiInstallDevice**](https://learn.microsoft.com/windows/win32/api/newdev/nf-newdev-diinstalldevice) instead.

## Parameters

*hwndParent* \[in\]
A handle to the top-level window that the **InstallSelectedDriver** function uses to display user interface components that are associated with installing the driver.

*DeviceInfoSet* \[in\]
A handle to a [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains a device information element that represents a selected device and a selected driver for the device. For more information about how to select a device and a driver for a device, see the following **Remarks** section.

*Reserved* \[in\]
This parameter must be set to **NULL**.

*Backup* \[in\]
A value of type BOOL that determines whether **InstallSelectedDriver** backs up the currently installed drivers for the selected device before the function installs the selected driver for the device. If the currently installed drivers are backed up and the user encounters a problem with the new driver, the user can roll back the installation of the new driver to the backed up driver. If the currently installed drivers are not backed up, the user cannot roll back the installation of the new driver to the previously installed driver. If *Backup* is set to **TRUE**, **InstallSelectedDriver** backs up the currently installed drivers; otherwise, the function does not back up the currently installed drivers. For more information about driver back up, see **DiRollbackDriver**.

*bReboot* \[out\]
A pointer to a variable of type DWORD that **InstallSelectedDriver** sets to indicate whether a system restart is required to complete the installation. If the variable is set to DI\_NEEDREBOOT, a system restart is required; otherwise, a system restart is not required. The caller is responsible for restarting the system.

## Return value

**InstallSelectedDriver** returns **TRUE** if the selected driver was installed on the selected device; otherwise, the function returns **FALSE** and the logged error can be retrieved by making a call to **GetLastError**.

Some of the more common error values that **GetLastError** might return are as follows:

| Return code | Description |
| --- | --- |
| **NO_ERROR** | The selected driver was a better match to the driver than the driver that was previously installed on the device. |
| **ERROR_IN_WOW64** | The calling application is a 32-bit application that is attempting to execute in a 64-bit environment, which is not allowed. For more information, see [Installing Devices on 64-Bit Systems](https://learn.microsoft.com/windows-hardware/drivers/install/device-installations-on-64-bit-systems). |

## Remarks

To access **InstallSelectedDriver**, call **LoadLibrary** to load *Newdev.dll* and then call **GetProcAddress** to obtain a function pointer to **InstallSelectedDriver**.

You should only call **InstallSelectedDriver** if it is necessary to install a specific driver on a specific device.

**Important** For Windows Vista and later versions of Windows, call [**DiInstallDevice**](https://learn.microsoft.com/windows/win32/api/newdev/nf-newdev-diinstalldevice) instead of **InstallSelectedDriver** to perform this type of operation.

Other than the special applications that require the installation of a specific driver on a specific device, an installation application should install the driver that is the best match for a device. To install the driver that is the best match for a device, call [**DiInstallDriver**](https://learn.microsoft.com/windows/win32/api/newdev/nf-newdev-diinstalldrivera) or [**UpdateDriverForPlugAndPlayDevices**](https://learn.microsoft.com/windows/win32/api/newdev/nf-newdev-updatedriverforplugandplaydevicesa). For more information about which of these functions to call to install a driver on a device, see [SetupAPI Functions that Simplify Driver Installation](https://learn.microsoft.com/windows-hardware/drivers/install/functions-that-simplify-driver-installation).

Before calling **InstallSelectedDriver**, the caller must obtain a device information set that contains the device, select the device in the set, and select a driver for the device.

To create a device information set that contains the device, do one of the following:

- Call [**SetupDiGetClassDevs**](https://learn.microsoft.com/windows/win32/api/setupapi/nf-setupapi-setupdigetclassdevsw) to retrieve a device information set that contains the device and then call [**SetupDiEnumDeviceInfo**](https://learn.microsoft.com/windows/win32/api/setupapi/nf-setupapi-setupdienumdeviceinfo) to enumerate the devices in the device information set. On each call, **SetupDiEnumDeviceInfo** returns an SP\_DEVINFO\_DATA structure that represents the enumerated device in the device information set. To obtain specific information about the enumerated device, call [**SetupDiGetDeviceRegistryProperty**](https://learn.microsoft.com/windows/win32/api/setupapi/nf-setupapi-setupdigetdeviceregistrypropertya) and supply the SP\_DEVINFO\_DATA structure that was returned by **SetupDiEnumDeviceInfo**.

    - OR -

- Call [**SetupDiOpenDeviceInfo**](https://learn.microsoft.com/windows/win32/api/setupapi/nf-setupapi-setupdiopendeviceinfoa) to add a device with a known device instance ID to the device information set. **SetupDiOpenDeviceInfo** returns an [**SP\_DEVINFO\_DATA**](https://learn.microsoft.com/windows/win32/api/setupapi/ns-setupapi-sp_devinfo_data) structure that represents the device in the device information set.

After obtaining the SP\_DEVINFO\_DATA structure for a device, call [**SetupDiSetSelectedDevice**](https://learn.microsoft.com/windows/win32/api/setupapi/nf-setupapi-setupdisetselecteddevice) to select the device in the device information set.

To retrieve a driver for a device, call [**SetupDiBuildDriverInfoList**](https://learn.microsoft.com/windows/win32/api/setupapi/nf-setupapi-setupdibuilddriverinfolist) to build a list of compatible drivers for the device and then call [**SetupDiEnumDriverInfo**](https://learn.microsoft.com/windows/win32/api/setupapi/nf-setupapi-setupdienumdriverinfoa) to enumerate the elements of the driver list for the device. For each enumerated driver, **SetupDiEnumDriverInfo** retrieves an SP\_DRVINFO\_DATA structure that represents the driver. [**SetupDiGetDriverInfoDetail**](https://learn.microsoft.com/windows/win32/api/setupapi/nf-setupapi-setupdigetdriverinfodetaila) can be called to retrieve additional details about an enumerated driver.

After obtaining an SP\_DRVINFO\_DATA structure for the driver, call [**SetupDiSetSelectedDriver**](https://learn.microsoft.com/windows/win32/api/setupapi/nf-setupapi-setupdisetselecteddrivera) to select the driver for the device.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Version | Available in Microsoft Windows 2000 and later versions of Windows. |
| Header | None (The **InstallSelectedDriver** function is not defined in a public header file. For more information, see the **Remarks** section. ) |
| Library | Newdev.lib |
| DLL | Newdev.dll |

## See also

[**DiInstallDevice**](https://learn.microsoft.com/windows/win32/api/newdev/nf-newdev-diinstalldevice)

[**DiInstallDriver**](https://learn.microsoft.com/windows/win32/api/newdev/nf-newdev-diinstalldrivera)

[**SetupDiBuildDriverInfoList**](https://learn.microsoft.com/windows/win32/api/setupapi/nf-setupapi-setupdibuilddriverinfolist)

[**SetupDiEnumDeviceInfo**](https://learn.microsoft.com/windows/win32/api/setupapi/nf-setupapi-setupdienumdeviceinfo)

[**SetupDiEnumDriverInfo**](https://learn.microsoft.com/windows/win32/api/setupapi/nf-setupapi-setupdienumdriverinfoa)

[**SetupDiGetClassDevs**](https://learn.microsoft.com/windows/win32/api/setupapi/nf-setupapi-setupdigetclassdevsw)

[**SetupDiGetDeviceRegistryProperty**](https://learn.microsoft.com/windows/win32/api/setupapi/nf-setupapi-setupdigetdeviceregistrypropertya)

[**SetupDiGetDriverInfoDetail**](https://learn.microsoft.com/windows/win32/api/setupapi/nf-setupapi-setupdigetdriverinfodetaila)

[**SetupDiOpenDeviceInfo**](https://learn.microsoft.com/windows/win32/api/setupapi/nf-setupapi-setupdiopendeviceinfoa)

[**SetupDiSetSelectedDevice**](https://learn.microsoft.com/windows/win32/api/setupapi/nf-setupapi-setupdisetselecteddevice)

[**SetupDiSetSelectedDriver**](https://learn.microsoft.com/windows/win32/api/setupapi/nf-setupapi-setupdisetselecteddrivera)

[**UpdateDriverForPlugAndPlayDevices**](https://learn.microsoft.com/windows/win32/api/newdev/nf-newdev-updatedriverforplugandplaydevicesa)