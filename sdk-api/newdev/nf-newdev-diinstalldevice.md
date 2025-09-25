# DiInstallDevice function

## Description

The **DiInstallDevice** function installs a specified driver that is preinstalled in the [driver store](https://learn.microsoft.com/windows-hardware/drivers/install/driver-store) on a specified device that is present in the system.

## Parameters

### `hwndParent` [in, optional]

A handle to the top-level window that **DiInstallDevice** uses to display any user interface component that is associated with installing the device. This parameter is optional and can be set to **NULL**.

### `DeviceInfoSet` [in]

A handle to a [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains a device information element that represents the specified device.

### `DeviceInfoData` [in]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that represents the specified device in the specified device information set.

### `DriverInfoData` [in, optional]

An pointer to an [SP_DRVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_drvinfo_data_v1_a) structure that specifies the driver to install on the specified device. This parameter is optional and can be set to **NULL**. If this parameter is **NULL**, **DiInstallDevice** searches the drivers preinstalled in the [driver store](https://learn.microsoft.com/windows-hardware/drivers/install/driver-store) for the driver that is the best match to the specified device, and, if one is found, installs the driver on the specified device.

### `Flags` [in]

A value of type **DWORD** that specifies zero or the following flag:

#### DIIDFLAG_SHOWSEARCHUI

If the caller does not specify a driver (*DriverInfoData* is set to **NULL**) and **DiInstallDevice** does not locate a preinstalled driver that matches the specified device. Instead, **DiInstallDevice** displays the Found New Hardware wizard for the device.

#### DIIDFLAG_NOFINISHINSTALLUI

**DiInstallDevice** does not start finish-install wizard pages or finish-install actions. The caller of **DiInstallDevice** must start these operations. The caller should only specify this flag if the caller requires that finish-install wizard pages be invoked in the context of a caller-supplied user interface component.

#### DIIDFLAG_INSTALLNULLDRIVER

**DiInstallDevice** attempts to install a [null driver](https://learn.microsoft.com/windows-hardware/drivers/) on the specified device. If this flag is set, **DiInstallDevice** does not use the *DriverInfoData* parameter. **DiInstallDevice** removes all device settings and, if the device cannot run in [raw mode](https://learn.microsoft.com/windows-hardware/drivers/), the function sets the status of the device to **CM_PROB_FAILED_INSTALL**. If **DiInstallDevice** cannot install a null driver, the resulting state of the device is the same as if the device was connected for the first time to the computer and Windows did not locate a driver for the device.

#### DIIDFLAG_INSTALLCOPYINFDRIVERS

Any additional INF file specified via a [CopyINF](https://learn.microsoft.com/windows-hardware/drivers/install/inf-copyinf-directive) directive will be installed on any device it is applicable to. Any failure in installing an additional INF will not cause the primary INF's installation to fail.

### `NeedReboot` [out, optional]

A pointer to a value of type **BOOL** that **DiInstallDevice** sets to indicate whether a system restart is required to complete the installation. This parameter is optional and can be set to **NULL**. If this parameter is supplied and a system restart is required to complete the installation, **DiInstallDevice** sets the value to **TRUE**. In this case, the caller is responsible for restarting the system. If this parameter is supplied and a system restart is not required, **DiInstallDevice** sets this parameter to **FALSE**. If this parameter is **NULL** and a system restart is required to complete the installation, **DiInstallDevice** displays a system restart dialog box.

## Return value

**DiInstallDevice** returns **TRUE** if the function successfully installed the specified driver on the specified device. Otherwise, **DiInstallDevice** returns **FALSE** and the logged error can be retrieved by making a call to **GetLastError**. Some of the more common error values that **GetLastError** might return are as follows:

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The caller does not have Administrator privileges. By default, Windows Vista and Windows Server 2008 require that a calling process have Administrator privileges to install a driver on a device. |
| **ERROR_INVALID_FLAGS** | The value that is specified for *Flags* is not zero or a bitwise OR of the valid flags. |
| **ERROR_IN_WOW64** | The calling application is a 32-bit application that is attempting to execute in a 64-bit environment, which is not allowed. For more information, see [Installing Devices on 64-Bit Systems](https://learn.microsoft.com/windows-hardware/drivers/install/device-installations-on-64-bit-systems). |

## Remarks

Only call **DiInstallDevice** if it is necessary to install a specific driver on a specific device. Otherwise, use [UpdateDriverForPlugAndPlayDevices](https://learn.microsoft.com/windows/desktop/api/newdev/nf-newdev-updatedriverforplugandplaydevicesa) or [DiInstallDriver](https://learn.microsoft.com/windows/desktop/api/newdev/nf-newdev-diinstalldrivera) to install a driver for a device. For more information about which of these functions to call to install a driver on a device, see [SetupAPI Functions that Simplify Driver Installation](https://learn.microsoft.com/windows-hardware/drivers/install/setupapi-functions-that-simplify-driver-installation).

Before calling **DiInstallDevice**, the caller must obtain an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure to specify the device and, optionally, an [SP_DRVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_drvinfo_data_v1_a) structure to specify a driver for the device.

To create a device information set that contains the specified device and to obtain an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure for the device, do one of the following:

* Call [SetupDiGetClassDevs](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassdevsw) to retrieve a device information set that contains the device and then call [SetupDiEnumDeviceInfo](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdienumdeviceinfo) to enumerate the devices in the device information set. On each call, **SetupDiEnumDeviceInfo** returns an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that represents the enumerated device in the device information set. To obtain specific information about the enumerated device, call [SetupDiGetDeviceProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdevicepropertyw) and supply the **SP_DEVINFO_DATA** structure that is returned by **SetupDiEnumDeviceInfo**.

  - OR -
* Call [SetupDiOpenDeviceInfo](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiopendeviceinfoa) to add a device with a known device instance ID to the device information set. **SetupDiOpenDeviceInfo** returns an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that represents the device in the device information set.

To retrieve an [SP_DRVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_drvinfo_data_v1_a) structure for a selected driver, call [SetupDiBuildDriverInfoList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdibuilddriverinfolist) to build a list of drivers for the device and then call [SetupDiEnumDriverInfo](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdienumdriverinfoa) to enumerate the elements of the driver list for the device. For each enumerated driver, **SetupDiEnumDriverInfo** retrieves an **SP_DRVINFO_DATA** structure that identifies the driver. [SetupDiGetDriverInfoDetail](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdriverinfodetaila) can also be called to retrieve additional detail about an enumerated driver.

In general, an installation application should set *NeedReboot* to **NULL**. This ensures that **DiInstallDevice** prompts the user to restart the system if a restart is required to complete the installation. An application should supply a *NeedReboot* pointer only in the following cases:

* The application must call **DiInstallDevice** several times to complete an installation. In this case, the application should record whether a **TRUE***NeedReboot* value is returned by any of the calls to **DiInstallDevice**  and, if so, prompt the user to restart the system after the final call to **DiInstallDevice** returns.
* The application must perform required operations, other than calling **DiInstallDevice**, before a system restart should occur. If a system restart is required, the application should finish the required operations and then prompt the user to restart the system.
* The application is a class installer, in which case, the class installer should set the **DI_NEEDREBOOT** flag in the **Flags** member of the [SP_DEVINSTALL_PARAMS](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinstall_params_a) structure for a device.

## See also

[DiInstallDriver](https://learn.microsoft.com/windows/desktop/api/newdev/nf-newdev-diinstalldrivera)

[SetupDiBuildDriverInfoList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdibuilddriverinfolist)

[SetupDiEnumDeviceInfo](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdienumdeviceinfo)

[SetupDiEnumDriverInfo](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdienumdriverinfoa)

[SetupDiGetClassDevs](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassdevsw)

[SetupDiGetDeviceProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdevicepropertyw)

[SetupDiGetDriverInfoDetail](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdriverinfodetaila)

[SetupDiOpenDeviceInfo](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiopendeviceinfoa)

[UpdateDriverForPlugAndPlayDevices](https://learn.microsoft.com/windows/desktop/api/newdev/nf-newdev-updatedriverforplugandplaydevicesa)