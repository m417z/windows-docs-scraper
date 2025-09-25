# SetupDiInstallDevice function

## Description

The **SetupDiInstallDevice** function is the default handler for the [DIF_INSTALLDEVICE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-installdevice) installation request.

## Parameters

### `DeviceInfoSet` [in]

A handle to the [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) for the local system that contains a device information element that represents the device to install.

### `DeviceInfoData` [in, out]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that specifies a device information element in *DeviceInfoSet*. This is an IN-OUT parameter because *DeviceInfoData.***DevInst** might be updated with a new handle value upon return.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved with a call to [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**SetupDiInstallDevice** installs a driver from the INF file. SetupAPI's definition of the "*driver*" is really a "[driver node](https://learn.microsoft.com/windows-hardware/drivers/)." Therefore, when this function installs a driver, it also installs the items in the following list:

* The service(s) for the device.
* The driver files.
* Device-specific co-installers (if any).
* Property-page providers (if any).
* Control-panel applets (if any).

This function also registers any required device interfaces.

A successful installation includes, but is not limited to, the following steps:

* Create a [driver key](https://learn.microsoft.com/windows-hardware/drivers/) in the registry and write appropriate entries (such as **InfPath** and **ProviderName**).
* Locate and process the [INF DDInstall section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-ddinstall-section) for the device. The section might be OS/architecture-specific. The *DDInstall* section's **AddReg** and **DelReg** entries are directed at the device's [software key](https://learn.microsoft.com/windows-hardware/drivers/). Locate and process the *DDInstall***.HW** section whose **AddReg** and **DelReg** entries are directed at the device's [hardware key](https://learn.microsoft.com/windows-hardware/drivers/). Locate and process the [INF DDInstall.LogConfigOverride section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-ddinstall-logconfigoverride-section), if present, to supply an [override configuration](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources) for the device. Locate and process the [INF DDInstall.Services section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-ddinstall-services-section) to add services for the device (and potentially remove any old services that are no longer necessary).
* Copy the INF file to the system INF directory.
* Possibly perform the other file operations, based on flag settings in the device installation parameters.

  If the DI_NOFILECOPY flag and the DI_NOVCP flag are *clear*, perform any file operations specified in the *DDInstall*  section. If the DI_NOVCP flag is set, queue any file operations.

  If the DI_NOFILECOPY flag is set, do not copy the files. This flag might be set if, for example, a [DIF_INSTALLDEVICEFILES](https://learn.microsoft.com/windows-hardware/drivers/install/dif-installdevicefiles) operation was already performed for this device installation.
* Load the drivers for the device. This includes the function driver and any upper or lower-filter drivers.
* Call the drivers' [AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nc-wdm-driver_add_device) routines.
* Start the device by sending an [IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device) I/O request packet (IRP).

Windows does not start the device if the DI_NEEDRESTART, DI_NEEDREBOOT, or DI_DONOTCALLCONFIGMG flag is set in the [SP_DEVINSTALL_PARAMS](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinstall_params_a) structure.

A class installer should return ERROR_DI_DO_DEFAULT or call this function when handling a [DIF_INSTALLDEVICE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-installdevice) request. This function performs many tasks for device installation and that list of tasks might be expanded in future releases. If a class installer performs device installation without calling this function, the class installer might not work correctly on future versions of the operating system.

If Windows cannot locate an INF file for the device, it will send DIF_INSTALLDEVICE in an attempt to install a [null driver](https://learn.microsoft.com/windows-hardware/drivers/). **SetupDiInstallDevice** installs a null driver only if the device supports [raw mode](https://learn.microsoft.com/windows-hardware/drivers/) or is a non-PnP device (reported by [IoReportDetectedDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntddk/nf-ntddk-ioreportdetecteddevice)). For more information, see [DIF_INSTALLDEVICE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-installdevice).

If the DI_FLAGSEX_SETFAILEDINSTALL flag is set in the [SP_DEVINSTALL_PARAMS](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinstall_params_a) structure, **SetupDiInstallDevice** just sets the FAILEDINSTALL flag in the device's **ConfigFlags** registry value.

**Note** Only a [class installer](https://learn.microsoft.com/windows-hardware/drivers/) should call **SetupDiInstallDevice** and only in those situations where the class installer must perform device installation operations after **SetupDiInstallDevice** completes the default device installation operation. In such situations, the class installer must directly call **SetupDiInstallDevice** when the installer processes a DIF_INSTALLDEVICE request. For more information about calling the default handler, see [Calling Default DIF Code Handlers](https://learn.microsoft.com/windows-hardware/drivers/install/calling-the-default-dif-code-handlers).

The caller of **SetupDiInstallDevice** must be a member of the Administrators group.

## See also

[DIF_INSTALLDEVICE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-installdevice)

[SetupDiCallClassInstaller](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicallclassinstaller)

[SetupDiInstallDriverFiles](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiinstalldriverfiles)