# UpdateDriverForPlugAndPlayDevicesA function

## Description

Given an INF file and a [hardware ID](https://learn.microsoft.com/windows-hardware/drivers/install/hardware-ids), the **UpdateDriverForPlugAndPlayDevices** function installs updated drivers for devices that match the hardware ID.

## Parameters

### `hwndParent` [in, optional]

A handle to the top-level window to use for any UI related to installing devices.

### `HardwareId` [in]

A pointer to a NULL-terminated string that supplies the hardware identifier to match existing devices on the computer. The maximum length of a NULL-terminated hardware identifier is MAX_DEVICE_ID_LEN. For more information about hardware identifiers, see [Device Identification Strings](https://learn.microsoft.com/windows-hardware/drivers/install/device-identification-strings).

### `FullInfPath` [in]

A pointer to a NULL-terminated string that supplies the full path file name of an INF file. The files should be on the distribution media or in a vendor-created directory, not in a system location such as *%SystemRoot%\inf*. **UpdateDriverForPlugAndPlayDevices** copies driver files to the appropriate system locations if the installation is successful.

### `InstallFlags` [in]

A caller-supplied value created by using OR to combine zero or more of the following bit flags:

#### INSTALLFLAG_FORCE

If this flag is set and the function finds a device that matches the *HardwareId*  value, the function installs new drivers for the device whether better drivers already exist on the computer.

**Important** Use this flag only with extreme caution. Setting this flag can cause an older driver to be installed over a newer driver, if a user runs the vendor's application after newer drivers are available.

#### INSTALLFLAG_READONLY

If this flag is set, the function will not copy, rename, or delete any installation files. Use of this flag should be limited to environments in which file access is restricted or impossible, such as an "embedded" operating system.

#### INSTALLFLAG_NONINTERACTIVE

If this flag is set, the function will return **FALSE** when any attempt to display UI is detected. Set this flag only if the function will be called from a component (such as a service) that cannot display UI.

**Note** If this flag is set and a UI display is attempted, the device can be left in an indeterminate state.

The *InstallFlags* parameter is typically zero.

### `bRebootRequired` [out, optional]

A pointer to a BOOL-typed variable that indicates whether a restart is required and who should prompt for it. This pointer is optional and can be **NULL**.

If the pointer is **NULL**, **UpdateDriverForPlugAndPlayDevices** prompts for a restart after installing drivers, if necessary. If the pointer is supplied, the function returns a BOOLEAN value that is **TRUE** if the system should be restarted. It is then the caller's responsibility to prompt for a restart.

For more information, see the following **Remarks** section.

## Return value

The function returns **TRUE** if a device was upgraded to the specified driver.

Otherwise, it returns **FALSE** and the logged error can be retrieved with a call to **GetLastError**. Possible error values returned by **GetLastError** are included in the following table.

| Return code | Description |
| --- | --- |
| **ERROR_FILE_NOT_FOUND** | The path that was specified for *FullInfPath* does not exist. |
| **ERROR_IN_WOW64** | The calling application is a 32-bit application attempting to execute in a 64-bit environment, which is not allowed. |
| **ERROR_INVALID_FLAGS** | The value specified for *InstallFlags* is invalid. |
| **ERROR_NO_SUCH_DEVINST** | The value specified for *HardwareId* does not match any device on the system. That is, the device is not plugged in. |
| **ERROR_NO_MORE_ITEMS** | The function found a match for the *HardwareId* value, but the specified driver was not a better match than the current driver and the caller did not specify the INSTALLFLAG_FORCE flag. |

## Remarks

**UpdateDriverForPlugAndPlayDevices** scans the devices on the system and attempts to install the drivers specified by *FullInfPath* for any devices that match the specified *HardwareId* value.

The default behavior is to only install the specified drivers if they are better match than the currently installed drivers and the specified drivers are also a better match than any drivers in %*SystemRoot*%\*inf*. For more information, see [How Windows Selects Drivers](https://learn.microsoft.com/windows-hardware/drivers/install/how-setup-selects-drivers).

**UpdateDriverForPlugAndPlayDevices** can also be used to determine whether the device with the specified *HardwareId* value is plugged in. For more information, see [Writing a Device Installation Application](https://learn.microsoft.com/windows-hardware/drivers/install/writing-a-device-installation-application).

**UpdateDriverForPlugAndPlayDevices** sends an [IRP_MN_QUERY_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-remove-device) request to the specified device, all the children of the device, and all other devices that are recursively part of the removal relations for the device. If any of these devices fail a query remove request, **UpdateDriverForPlugAndPlayDevices** sets the DI_NEEDREBOOT flag in the **Flags** member of the [SP_DEVINSTALL_PARAMS](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinstall_params_a) structure for the device. For information about removal relations, see the [IRP_MN_QUERY_DEVICE_RELATIONS](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-device-relations) request.

Generally, [device installation applications](https://learn.microsoft.com/windows-hardware/drivers/) should supply **NULL** for *bRebootRequired*. So, the system will initiate a restart if necessary. An application should specify a pointer value *only* in the following cases:

* The application must call **UpdateDriverForPlugAndPlayDevices** several times to complete an installation.
* The application must perform other operations before the restart (if required) occurs.
* The application is a class installer, which should set DI_NEEDREBOOT in [SP_DEVINSTALL_PARAMS](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinstall_params_a) if a restart is needed.

If the application must call **UpdateDriverForPlugAndPlayDevices** several times, it should save any **TRUE** restart status value received and then prompt for a restart after the final call has returned.

If the function returns ERROR_IN_WOW64 in a 32-bit application, the application is executing on a 64-bit system, which is not allowed. For more information, see [Installing Devices on 64-Bit Systems](https://learn.microsoft.com/windows-hardware/drivers/install/device-installations-on-64-bit-systems).