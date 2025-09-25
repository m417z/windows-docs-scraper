# SetupDiSelectDevice function

## Description

The **SetupDiSelectDevice** function is the default handler for the [DIF_SELECTDEVICE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-selectdevice) request.

## Parameters

### `DeviceInfoSet` [in]

A handle to a [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains a device information element that represents the device for which to select a driver.

### `DeviceInfoData` [in, out]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that specifies the device information element. This parameter is optional and can be **NULL**. If this parameter is specified, **SetupDiSelectDevice** selects the driver for the specified device and sets *DeviceInfoData.***ClassGuid** to the GUID of the [device setup class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-setup-classes) for the selected driver. If this parameter is **NULL**, **SetupDiSelectDevice** sets the selected driver in the global class driver list for *DeviceInfoSet*.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved by a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**SetupDiSelectDevice** handles the user interface that allows the user to select a driver for the specified device, or a device information set if a device is not specified. By setting the **Flags** field of the [SP_DEVINSTALL_PARAMS](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinstall_params_a) structure for the device, or the device information set if a device is not specified, the caller can specify special handling of the user interface, for example, to allow users to select a driver from an OEM installation disk.

**Note** Only a class installer should call **SetupDiSelectDevice** and only in those situations where the class installer must perform driver selection operations after **SetupDiSelectDevice** completes the default driver selection operation. In such situations, the class installer must directly call **SetupDiSelectDevice** when the installer processes a DIF_SELECTDEVICE request. For more information about calling the default handler, see [Calling Default DIF Code Handlers](https://learn.microsoft.com/windows-hardware/drivers/install/calling-the-default-dif-code-handlers).

**SetupDiSelectDevice** is primarily designed to select a driver for a device on a local computer before installing the device. Although **SetupDiSelectDevice** will not fail if the device information set is for a remote computer, the result is of limited use because the device information set cannot subsequently be used with DIF_*Xxx* installation requests or **SetupDi***Xxx* functions that do not support operations on a remote computer. In particular, the device information set cannot be used as input with a DIF_INSTALLDEVICE installation request to install a device on a remote computer.

## See also

[SP_DEVINSTALL_PARAMS](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinstall_params_a)

[SetupDiCallClassInstaller](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicallclassinstaller)