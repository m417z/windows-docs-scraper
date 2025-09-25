# DiUninstallDevice function

## Description

The **DiUninstallDevice** function uninstalls a device and removes its device node ([devnode](https://learn.microsoft.com/windows-hardware/drivers/)) from the system. This differs from using [SetupDiCallClassInstaller](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicallclassinstaller) with the [DIF_REMOVE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-remove) code because it attempts to uninstall the device node in addition to child devnodes that are present at the time of the call.

Prior to Windows 8 any child devices that are not present at the time of the call will not be uninstalled. However, beginning with Windows 8, any child devices that are not present at the time of the call will be uninstalled.

## Parameters

### `hwndParent` [in]

A handle to the top-level window that is used to display any user interface component that is associated with the uninstallation request for the device. This parameter is optional and can be set to **NULL**.

### `DeviceInfoSet` [in]

A handle to the [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains a device information element. This element represents the device to be uninstalled through this call.

### `DeviceInfoData` [in]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that represents the specified device in the specified device information set for which the uninstallation request is performed.

### `Flags` [in]

A value of type DWORD that specifies device uninstallation flags. Starting with Windows 7, this parameter must be set to zero.

### `NeedReboot` [out, optional]

A pointer to a value of type BOOL that **DiUninstallDevice** sets to indicate whether a system restart is required to complete the device uninstallation request. This parameter is optional and can be set to **NULL**.

If the parameter is given and a system restart is required, **DiUninstallDevice** sets the value to **TRUE**. In this case, the application must prompt the user to restart the system. If this parameter is supplied and a system restart is not required, **DiUninstallDevice** sets the value to **FALSE**.

If this parameter is **NULL** and a system restart is required to complete the device uninstallation, **DiUninstallDevice** displays a system restart dialog box.

For more information about this parameter, see the **Remarks** section.

## Return value

**DiUninstallDevice** returns **TRUE** if the function successfully uninstalled the top-level device node that represents the device. Otherwise, **DiUninstallDevice** returns **FALSE**, and the logged error can be retrieved by making a call to [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following list shows some of the more common error values that **GetLastError** might return for this API:

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The caller does not have Administrator privileges. By default, Windows requires that the caller have Administrator privileges to uninstall devices. |
| **ERROR_INVALID_FLAGS** | The value that is specified for the *Flags* parameter is not equal to zero. |

**Note** The return value does not indicate that the removal of all child devnodes has succeeded or failed. Starting with Windows Vista, information about the status of the removal of child devnodes is available in the *Setupapi.dev.log* file. For more information about this file, see [SetupAPI Text Logs](https://learn.microsoft.com/windows-hardware/drivers/install/setupapi-text-logs).

## Remarks

**DiUninstallDevice** performs the same function as [SetupDiCallClassInstaller](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicallclassinstaller) when used with the [DIF_REMOVE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-remove) code. The key difference is that child devnodes for the top-level device are also deleted. **DiUninstallDevice** only returns failure if the top-level device node failed to be uninstalled, which is consistent with the behavior of **SetupDiCallClassInstaller** when used with the **DIF_REMOVE** code. Detailed information about whether child devnode uninstallation succeeded is available in the Setupapi.dev.log file.

The device to be uninstalled is specified by providing a [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that includes the referenced device, and a [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure for the specific device. These are provided in the *DeviceInfoSet* and *DeviceInfoData* parameters.

To create a device information set that contains the specified device and to obtain an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure for the device, complete one of the following tasks:

* Call [SetupDiGetClassDevs](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassdevsw) to retrieve a device information set that contains the device and then call [SetupDiEnumDeviceInfo](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdienumdeviceinfo) to enumerate the devices in the device information set. On each call, **SetupDiEnumDeviceInfo** returns an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that represents the enumerated device in the device information set.

  To obtain specific information about the enumerated device, call [SetupDiGetDeviceProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdevicepropertyw) and supply the [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that is returned by [SetupDiEnumDeviceInfo](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdienumdeviceinfo).
* Call [SetupDiEnumDeviceInfo](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdienumdeviceinfo) to add a device with a known device instance ID to the device information set. [SetupDiOpenDeviceInfo](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiopendeviceinfoa) returns an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that represents the device in the device information set.

In case the device uninstallation request requires a restart of the computer, **DiUninstallDevice** prompts the user to restart the system if the *NeedReboot* parameter is set to **NULL**. If there is any user interface window that the application is using, the *hwndParent* parameter should be set to the value of that window's handle.

However, if the application manages the notification of a required system restart, it must set the *NeedReboot* parameter to a non-**NULL** value. **DiUninstallDevice** sets the *NeedReboot* parameter to **TRUE** or **FALSE**, depending on whether a system restart is required.

The following list shows examples of why the application might manage the system restart:

* The application has to uninstall several devices. After all the devices are uninstalled, the application should prompt the user to restart the system if any call to **DiUninstallDevice** returned **TRUE** in the *NeedReboot* parameter.
* The application requires some other operations to occur before the system can be restarted. If a system restart is required, the application should finish the required operations and then prompt the user to restart the system.
* The application is a class installer. In this case, the class installer should set the **DI_NEEDREBOOT** flag in the **Flags** member of the [SP_DEVINSTALL_PARAMS](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinstall_params_a) structure for a device.

## See also

[DIF_REMOVE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-remove)

[Device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets)

[SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data)

[SP_DEVINSTALL_PARAMS](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinstall_params_a)

[SetupDiCallClassInstaller](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicallclassinstaller)

[SetupDiEnumDeviceInfo](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdienumdeviceinfo)

[SetupDiGetClassDevs](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassdevsw)

[SetupDiGetDeviceProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdevicepropertyw)