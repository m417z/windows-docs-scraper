# DiUninstallDriverW function

## Description

The **DiUninstallDriver** function removes a driver package from any devices it is installed on by installing those devices with another matching driver package, if available, or the null driver if no other matching driver package is available. Then the specified driver package is removed from the [driver store.](https://learn.microsoft.com/windows-hardware/drivers/install/driver-store)

## Parameters

### `hwndParent` [in, optional]

A handle to the top-level window that **DiUninstallDriver** should use to display any user interface component that is associated with uninstalling the driver. This parameter is optional and can be set to **NULL**.

### `InfPath` [in]

A pointer to a NULL-terminated string that supplies the fully qualified path of the INF file for the [driver package](https://learn.microsoft.com/windows-hardware/drivers/install/driver-packages).

### `Flags` [in]

A value of type DWORD that specifies zero or one or more of the following flags: DIURFLAG_NO_REMOVE_INF. Typically, this flag should be set to zero.

If this flag is zero, **DiUninstallDriver** removes the driver package from any devices it is installed on by installing those devices with another matching driver package, if available, or the null driver if no other matching driver package is available. However, if this flag is set to DIURFLAG_NO_REMOVE_INF, **DiUninstallDriver** removes the driver package from any devices it is installed on, but does not remove the driver package from the Driver Store.

**Caution:** Forcing the uninstallation of the driver package can result in replacing a more compatible or newer driver package with a less compatible or older driver.

For information about how Windows selects a driver package for a device, see [How Windows Selects Drivers](https://learn.microsoft.com/windows-hardware/drivers/install/how-setup-selects-drivers).

### `NeedReboot` [out, optional]

A pointer to a value of type BOOL that **DiUninstallDriver** sets to indicate whether a system restart is required to complete the uninstallation. This parameter is optional and can be **NULL**. If the parameter is supplied and a system restart is required to complete the uninstallation, **DiUninstallDriver** sets the value to **TRUE**. In this case, the caller must prompt the user to restart the system. If this parameter is supplied and a system restart is not required to complete the uninstallation, **DiUninstallDriver** sets the value to **FALSE**. If the parameter is **NULL** and a system restart is required to complete the uninstallation, **DiUninstallDriver** displays a system restart dialog box. For more information about this parameter, see the following **Remarks** section.

## Return value

**DiUninstallDriver** returns **TRUE** if the function successfully removes the [driver package](https://learn.microsoft.com/windows-hardware/drivers/install/driver-packages) from any devices it is installed on and is successfully removed from the driver store of the system. If the driver package is not successfully uninstalled from the driver store, **DiUninstallDriver** returns **FALSE** and the logged error can be retrieved by making a call to **GetLastError**. Some of the more common error values that **GetLastError** might return are as follows:

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The caller does not have Administrator privileges. By default, Windows requires that the caller have Administrator privileges to uninstall a [driver package](https://learn.microsoft.com/windows-hardware/drivers/install/driver-packages) from the [driver store](https://learn.microsoft.com/windows-hardware/drivers/install/driver-store). |
| **ERROR_FILE_NOT_FOUND** | The path of the specified INF file does not exist. |
| **ERROR_INVALID_FLAGS** | The value specified for *Flags* is not equal to zero or DIURFLAG_NO_REMOVE_INF. |
| **ERROR_IN_WOW64** | The calling application is a 32-bit application that is attempting to execute in a 64-bit environment, which is not allowed. For more information, see [Installing Devices on 64-Bit Systems](https://learn.microsoft.com/windows-hardware/drivers/install/device-installations-on-64-bit-systems). |

## Remarks

In general, an uninstallation application should set *NeedReboot* to **NULL** to direct **DiUninstallDriver** to prompt the user to restart the system if a restart is required to complete the removal. An application should supply a *NeedReboot* pointer only in the following cases:

* The application must call **DiUninstallDriver** several times to complete an uninstallation. In this case, the application should record whether a **TRUE** *NeedReboot* value is returned by any of the calls to **DiUninstallDriver** and, if so, prompt the user to restart the system after the final call to **DiUninstallDriver** returns.
* The application must perform required operations, other than calling **DiUninstallDriver**, before a system restart should occur. If a system restart is required, the application should finish the required operations and then prompt the user to restart the system.

## See also

[DiUninstallDevice](https://learn.microsoft.com/windows/desktop/api/newdev/nf-newdev-diinstalldevice)