# DiShowUpdateDevice function

## Description

The **DiShowUpdateDevice** function displays the Hardware Update wizard for a specified device.

## Parameters

### `hwndParent` [in, optional]

A handle to the top-level window that **DiShowUpdateDevice** uses to display any user interface components that are associated with updating the specified device. This parameter is optional and can be set to **NULL**.

### `DeviceInfoSet` [in]

A handle to the [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains a device information element that represents the device for which to show the Hardware Update wizard.

### `DeviceInfoData` [in]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that represents the device for which to show the Hardware Update wizard.

### `Flags` [in]

This parameter must be set to zero.

### `NeedReboot` [out, optional]

A pointer to a value of type BOOL that **DiShowUpdateDevice** sets to indicate whether a system restart is required to complete the driver update. This parameter is optional and can be **NULL**. If the parameter is supplied and a system restart is required to complete the driver update, **DiShowUpdateDevice** sets the value to **TRUE**. In this case, the caller must prompt the user to restart the system. If this parameter is supplied and a system restart is not required to complete the installation, **DiShowUpdateDevice** sets the value to **FALSE**. If the parameter is **NULL** and a system restart is required to complete the driver update, **DiShowUpdateDevice** displays a system restart dialog box. For more information about this parameter, see the following **Remarks** section.

## Return value

**DiShowUpdateDevice** returns **TRUE** if the Hardware Update wizard successfully updated the driver for the specified device. Otherwise, **DiShowUpdateDevice** returns **FALSE** and the logged error can be retrieved by making a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror). Some of the more common error values that [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) might return are as follows:

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The caller does not have Administrator privileges. By default, Windows requires that the calling process have Administrator privileges to update a [driver package](https://learn.microsoft.com/previous-versions/windows/hardware/difxapi/driverpackagepreinstall). |
| **ERROR_CANCELLED** | The user canceled the Hardware Update wizard. |
| **ERROR_IN_WOW64** | The calling application is a 32-bit application that is attempting to execute in a 64-bit environment, which is not allowed. For more information, see [Installing Devices on 64-Bit Systems](https://learn.microsoft.com/windows-hardware/drivers/install/device-installations-on-64-bit-systems). |
| **ERROR_INVALID_FLAGS** | The value specified for *Flags* is not equal to zero. |

## Remarks

**DiShowUpdateDevice** displays the Hardware Update wizard for the specified device instance. For information about how to update device drivers by using the Hardware Update wizard, see Help and Support Center.

In general, installation applications should set *NeedReboot* to **NULL** so that the system will automatically initiate a system restart if a restart is required to complete a hardware update. An application should supply a *NeedReboot* pointer only in the following cases:

* The installation application must call **DiShowUpdateDevice** several times to complete hardware updates. In this case, the application should record whether a **TRUE***NeedReboot* value is returned by any of the calls to **DiShowUpdateDevice** and, if so, prompt the user to restart the system after the final call to **DiShowUpdateDevice** returns.
* The application must perform required operations, other than calling **DiShowUpdateDevice**, before a system restart should occur. If a system restart is required, the application should finish the required operations and then prompt the user to restart the system.

To roll back a driver for a device instead of invoking the Hardware Update wizard, call [DiRollbackDriver](https://learn.microsoft.com/windows/desktop/api/newdev/nf-newdev-dirollbackdriver).

To install a new driver for a device instead of invoking the Hardware Update wizard, call [DiInstallDriver](https://learn.microsoft.com/windows/desktop/api/newdev/nf-newdev-diinstalldrivera) or [UpdateDriverForPlugAndPlayDevices](https://learn.microsoft.com/windows/desktop/api/newdev/nf-newdev-updatedriverforplugandplaydevicesa).

## See also

[DiInstallDriver](https://learn.microsoft.com/windows/desktop/api/newdev/nf-newdev-diinstalldrivera)

[DiRollbackDriver](https://learn.microsoft.com/windows/desktop/api/newdev/nf-newdev-dirollbackdriver)

[UpdateDriverForPlugAndPlayDevices](https://learn.microsoft.com/windows/desktop/api/newdev/nf-newdev-updatedriverforplugandplaydevicesa)