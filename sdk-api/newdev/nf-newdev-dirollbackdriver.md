# DiRollbackDriver function

## Description

The **DiRollbackDriver** function rolls back the driver that is installed on a specified device.

## Parameters

### `DeviceInfoSet` [in]

A handle to the [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains a device information element that represents the device for which driver rollback is performed.

### `DeviceInfoData` [in]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that represents the specific device in the specified device information set for which driver rollback is performed.

### `hwndParent` [in, optional]

A handle to the top-level window that **DiRollbackDriver** uses to display any user interface component that is associated with a driver rollback for the specified device. This parameter is optional and can be set to **NULL**.

### `Flags` [in]

A value of type DWORD that can be set to zero or ROLLBACK_FLAG_NO_UI.

Typically, this flag should be set to zero, in which case **DiRollbackDriver** does not suppress the default user interface components that are associated with a driver rollback. However, if this flag is set to ROLLBACK_FLAG_NO_UI, **DiRollbackDriver** suppresses the display of user interface components that are associated with a driver rollback.

### `NeedReboot` [out, optional]

A pointer to a value of type BOOL that **DiRollbackDriver** sets to indicate whether a system restart is required to complete the rollback. This parameter is optional and can be **NULL**.

If the parameter is supplied and a system restart is required to complete the rollback, **DiRollbackDriver** sets the value to **TRUE**. In this case, the caller must prompt the user to restart the system. If this parameter is supplied and a system restart is not required to complete the installation, **DiRollbackDriver** sets the value to **FALSE**.

If the parameter is **NULL** and a system restart is required to complete the rollback, **DiRollbackDriver** displays a system restart dialog box.

For more information about this parameter, see the following **Remarks** section.

## Return value

**DiRollbackDriver** returns **TRUE** if the function successfully rolled back the driver for the device; otherwise, **DiRollbackDriver** returns **FALSE** and the logged error can be retrieved by making a call to **GetLastError**. Some of the more common error values that **GetLastError** might return are as follows:

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The caller does not have Administrator privileges. By default, Windows requires that the caller have Administrator privileges to roll back a [driver package](https://learn.microsoft.com/previous-versions/windows/hardware/difxapi/driverpackagepreinstall). |
| **ERROR_IN_WOW64** | The calling application is a 32-bit application that is attempting to execute in a 64-bit environment, which is not allowed. For more information, see [Installing Devices on 64-Bit Systems](https://learn.microsoft.com/windows-hardware/drivers/install/device-installations-on-64-bit-systems). |
| **ERROR_INVALID_FLAGS** | The value specified for *Flags* is not equal to zero or ROLLBACK_FLAG_NO_UI. |
| **ERROR_NO_MORE_ITEMS** | A backup driver is not set for the device. |

## Remarks

If a previously installed backup driver is set for a device, a driver rollback for the device replaces the driver that is currently installed on the device with the backup driver. Windows maintains at most one backup driver for a device. Windows sets a driver as the backup driver for a device immediately after the driver is successfully installed on the device and Windows determines that the device is functioning correctly. However, if a driver does not install successfully on a device or the device does not function correctly after the installation, Windows does not set the driver as the backup driver for the device. For more information about driver rollback, see information about Device Manager in Help and Support Center.

If the specified device has a backup driver, **DiRollbackDriver** performs the following operations:

1. If *Flags* is set to zero, **DiRollbackDriver** prompts the user to confirm whether the backup driver should be installed. Otherwise, if *Flags* is set to ROLLBACK_FLAG_NO_UI, **DiRollbackDriver** installs the backup driver without prompting the user to confirm the installation of the backup driver.
2. **DiRollbackDriver** installs the backup driver. The driver is installed whether the backup driver is a better match for the device than the driver that is currently installed on the device.
3. If the driver that is replaced by the backup driver is not an inbox driver and is not installed on any other devices in the system, **DiRollbackDriver** removes the driver from the system. **DiRollbackDriver** removes the driver from the system because it is assumed that a user will replace a driver only if there is a problem with the driver.

If the specified device does not have a backup driver, **DiRollbackDriver** calls **SetLastError** to set the error ERROR_NO_MORE_ITEMS, does not remove the currently installed driver, and returns **FALSE**.

In general, installation applications should set *NeedReboot* to **NULL** so that the system will automatically initiate a system restart if a restart is required to complete the rollback. An application should supply a *NeedReboot* pointer only in the following cases:

* The application must call **DiRollbackDriver** several times to complete an installation. In this case, the application should record whether a **TRUE***NeedReboot* value is returned by any of the calls to **DiRollbackDriver** and, if so, prompt the user to restart the system after the final call to **DiRollbackDriver** returns.
* The application must perform required operations, other than calling **DiRollbackDriver**, before a system restart should occur. If a system restart is required, the application should finish the required operations and then prompt the user to restart the system.

To install a new driver for a device instead of rolling back the driver for the device, call [DiInstallDriver](https://learn.microsoft.com/windows/desktop/api/newdev/nf-newdev-diinstalldrivera) or [UpdateDriverForPlugAndPlayDevices](https://learn.microsoft.com/windows/desktop/api/newdev/nf-newdev-updatedriverforplugandplaydevicesa).

## See also

[DiInstallDriver](https://learn.microsoft.com/windows/desktop/api/newdev/nf-newdev-diinstalldrivera)

[UpdateDriverForPlugAndPlayDevices](https://learn.microsoft.com/windows/desktop/api/newdev/nf-newdev-updatedriverforplugandplaydevicesa)