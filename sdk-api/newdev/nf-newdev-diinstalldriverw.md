# DiInstallDriverW function

## Description

The **DiInstallDriver** function preinstalls a driver in the [driver store](https://learn.microsoft.com/windows-hardware/drivers/install/driver-store) and then installs the driver on devices present in the system that the driver supports.

## Parameters

### `hwndParent` [in, optional]

A handle to the top-level window that **DiInstallDriver** uses to display any user interface component that is associated with installing the device. This parameter is optional and can be set to **NULL**.

### `InfPath` [in]

A pointer to a NULL-terminated string that supplies the fully qualified path of the INF file for the [driver package](https://learn.microsoft.com/windows-hardware/drivers/install/driver-packages).

### `Flags` [in]

A value of type DWORD that specifies zero or a combination of one or more flags as described here (*Flags* is typically set to zero).

If *Flags* is zero, **DiInstallDriver** only installs the specified driver on a device if the driver is a better match for a device than the driver that is currently installed on a device. For information about how Windows selects a driver for a device, see [How Windows Selects Drivers](https://learn.microsoft.com/windows-hardware/drivers/install/how-setup-selects-drivers).

If *Flags* includes DIIRFLAG_FORCE_INF, **DiInstallDriver** installs the specified driver on a matching device whether or not the driver is a better match for the device than the driver that is currently installed on the device. If DIIRFLAG_INSTALL_AS_SET is also specified, DIIRFLAG_FORCE_INF is ignored.

**Caution** Forcing the installation of the driver can result in replacing a more compatible or newer driver with a less compatible or older driver.

If *Flags* includes DIIRFLAG_INSTALL_AS_SET (supported on Windows 10 version 1709 and later), _InfPath_ should specify a directory instead of a fully qualified path to an INF file and **DiInstallDriver** will install all INF files in that directory with special behavior. All [driver packages](https://learn.microsoft.com/windows-hardware/drivers/install/driver-packages) will get staged into the [Driver Store](https://learn.microsoft.com/windows-hardware/drivers/install/driver-store) but will not be made available to be installed on devices yet. On next shutdown of the system, these driver packages will be made available to be installed on devices going forward and they will be installed on any devices they are the best match for such that the devices are ready on next boot of the system.

### `NeedReboot` [out, optional]

A pointer to a value of type BOOL that **DiInstallDriver** sets to indicate whether a system restart is required to complete the installation. This parameter is optional and can be **NULL**. If the parameter is supplied and a system restart is required to complete the installation, **DiInstallDriver** sets the value to **TRUE**. In this case, the caller must prompt the user to restart the system. If this parameter is supplied and a system restart is not required to complete the installation, **DiInstallDriver** sets the value to **FALSE**. If the parameter is **NULL** and a system restart is required to complete the installation, **DiInstallDriver** displays a system restart dialog box. For more information about this parameter, see the following **Remarks** section.

## Return value

**DiInstallDriver** returns **TRUE** if the function successfully preinstalled the specified [driver package](https://learn.microsoft.com/previous-versions/windows/hardware/difxapi/driverpackagepreinstall) in the [driver store](https://learn.microsoft.com/windows-hardware/drivers/install/driver-store). **DiInstallDriver** also returns **TRUE** if the function successfully installed the driver on one or more devices in the system. If the driver package is not successfully installed in the driver store, **DiInstallDriver** returns **FALSE** and the logged error can be retrieved by making call to **GetLastError**. Some of the more common error values that **GetLastError** might return are as follows:

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The caller does not have Administrator privileges. By default, Windows requires that the caller have Administrator privileges to preinstall a [driver package](https://learn.microsoft.com/previous-versions/windows/hardware/difxapi/driverpackagepreinstall) in the [driver store](https://learn.microsoft.com/windows-hardware/drivers/install/driver-store). |
| **ERROR_FILE_NOT_FOUND** | The path of the specified INF file does not exist. |
| **ERROR_INVALID_FLAGS** | The value specified for *Flags* is not equal to zero or DIIRFLAG_FORCE_INF. |
| **ERROR_IN_WOW64** | The calling application is a 32-bit application that is attempting to execute in a 64-bit environment, which is not allowed. For more information, see [Installing Devices on 64-Bit Systems](https://learn.microsoft.com/windows-hardware/drivers/install/device-installations-on-64-bit-systems). |

## Remarks

**DiInstallDriver** performs the following operations:

1. Preinstalls the [driver package](https://learn.microsoft.com/previous-versions/windows/hardware/difxapi/driverpackagepreinstall) in the [driver store](https://learn.microsoft.com/windows-hardware/drivers/install/driver-store). If there is an instance of the same driver package already preinstalled in the driver store, **DiInstallDriver** first removes that instance and then adds the new instance of the driver package to the driver store.
2. Enumerates devices that are present in the system.
3. If *Flags* is equal to zero, installs the driver on a device only if the specified driver is a better match for the device than the driver that is currently installed on the device.
4. If *Flags* is equal to DIIRFLAG_FORCE_INF, installs the driver on a device regardless of whether the [driver package](https://learn.microsoft.com/previous-versions/windows/hardware/difxapi/driverpackagepreinstall) is the better match to the device than the driver that is currently installed on the device.

In general, an installation application should set *NeedReboot* to **NULL** to direct **DiInstallDriver** to prompt the user to restart the system if a restart is required to complete the installation. An application should supply a *NeedReboot* pointer only in the following cases:

* The application must call **DiInstallDriver** several times to complete an installation. In this case, the application should record whether a **TRUE***NeedReboot* value is returned by any of the calls to **DiInstallDriver** and, if so, prompt the user to restart the system after the final call to **DiInstallDriver** returns.
* The application must perform required operations, other than calling **DiInstallDriver**, before a system restart should occur. If a system restart is required, the application should finish the required operations and then prompt the user to restart the system.
* The application is a class installer, in which case, the class installer should set the DI_NEEDREBOOT flag in the **Flags** member of the SP_DEVINSTALL_PARAMS structure for a device.

To install a selected driver on a selected device, call [DiInstallDevice](https://learn.microsoft.com/windows/desktop/api/newdev/nf-newdev-diinstalldevice). For more info, see [SetupAPI Functions that Simplify Driver Installation](https://learn.microsoft.com/windows-hardware/drivers/install/setupapi-functions-that-simplify-driver-installation).

> [!NOTE]
> The newdev.h header defines DiInstallDriver as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DiInstallDevice](https://learn.microsoft.com/windows/desktop/api/newdev/nf-newdev-diinstalldevice)