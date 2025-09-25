# SetupDiInstallDeviceInterfaces function

## Description

The **SetupDiInstallDeviceInterfaces** function is the default handler for the [DIF_INSTALLINTERFACES](https://learn.microsoft.com/windows-hardware/drivers/install/dif-installinterfaces) installation request.

## Parameters

### `DeviceInfoSet` [in]

A pointer to the [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains a device information element that represents the device for which to install interfaces. The device information set must contain only elements for the local system.

### `DeviceInfoData` [in]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that specifies the device information element in *DeviceInfoSet*.

## Return value

**SetupDiInstallDeviceInterfaces** returns **TRUE** if the function completed without error. If the function completed with an error, **FALSE** is returned and the error code for the failure can be retrieved by calling [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**SetupDiInstallDeviceInterfaces** processes each **AddInterface** entry in the *DDInstall*.**Interfaces** section of a device INF file and creates each interface by calling [SetupDiCreateDeviceInterface](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicreatedeviceinterfacea).

The caller of **SetupDiInstallDeviceInterfaces** must be a member of the Administrators group.

**Note** Only a [class installer](https://learn.microsoft.com/windows-hardware/drivers/) should call **SetupDiInstallDeviceInterfaces** and only in those situations where the class installer must perform device interface installation operations after **SetupDiInstallDeviceInterfaces** completes the default device interface installation operation. In such situations, the class installer must directly call **SetupDiInstallDeviceInterfaces** when the installer processes a DIF_INSTALLINTERFACES request. For more information about calling the default handler, see [Calling Default DIF Code Handlers](https://learn.microsoft.com/windows-hardware/drivers/install/calling-the-default-dif-code-handlers).

For information about INF file format, see [INF File Sections and Directives](https://learn.microsoft.com/windows-hardware/drivers/install/inf-file-sections-and-directives).

## See also

[DIF_INSTALLINTERFACES](https://learn.microsoft.com/windows-hardware/drivers/install/dif-installinterfaces)

[SetupDiCreateDeviceInterface](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicreatedeviceinterfacea)