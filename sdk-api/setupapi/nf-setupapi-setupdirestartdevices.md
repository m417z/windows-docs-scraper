# SetupDiRestartDevices function

## Description

The **SetupDiRestartDevices** function restarts a specified device or, if necessary, restarts all devices that are operated by the same function and filter drivers that operate the specified device.

## Parameters

### `DeviceInfoSet` [in]

A handle to a [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains the device information element that represents the device to restart.

### `DeviceInfoData` [in, out]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure for the device information member that represents the device to restart. This parameter is also an output parameter because **SetupDiRestartDevices** updates the device installation parameters for this device information member and the status and problem code of the corresponding device instance. For more information about these updates, see the following **Remarks** section.

## Return value

If the operation succeeds, **SetupDiRestartDevices** returns **TRUE**; otherwise, the function returns **FALSE** and the logged error can be retrieved by a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**SetupDiRestartDevices** should be called only by a class installer when a class installer is handling a DIF_INSTALLDEVICE request and only in rare situations where the class installer must perform operations after all default installation operations, except for starting a device, have completed . For more information about calling **SetupDiRestartDevices** in these situations, see [DIF_INSTALLDEVICE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-installdevice).

**SetupDiRestartDevices** restarts only the specified device if the restart can be performed without affecting the installation of other devices that are operated by the same function driver or filter drivers that operate the device. Specifically, if the restart of the specified device does not copy new files or modify any files that were previously installed for the device, **SetupDiRestartDevices** restarts only the specified device. Otherwise, the function restarts all devices that are operated by the same function and filter drivers that operate the specified device.

**SetupDiRestartDevices** updates the device installation parameters and device status to reflect the result of the attempted restart operation. For example:

* If the device is started, **SetupDiRestartDevices** sets the device status to DN_STARTED.
* If a system restart is necessary to start a device, **SetupDiRestartDevices** sets the DI_NEEDREBOOT flag in the **Flags** member of the SP_DEVINSTALL_PARAMETER structure that is associated with the device information element and sets the problem code for the device to CM_PROB_NEED_RESTART.

The [CM_Get_DevNode_Status](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_devnode_status) function retrieves the status and problem code for a device instance and the [SetupDiGetDeviceInstallParams](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceinstallparamsa) function retrieves the device installation parameters for the device information element that represents the device instance.

## See also

[CM_Get_DevNode_Status](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_devnode_status)

[DIF_INSTALLDEVICE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-installdevice)

[SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data)

[SetupDiGetDeviceInstallParams](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceinstallparamsa)