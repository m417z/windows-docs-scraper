# SetupDiInstallDriverFiles function

## Description

The **SetupDiInstallDriverFiles** function is the default handler for the [DIF_INSTALLDEVICEFILES](https://learn.microsoft.com/windows-hardware/drivers/install/dif-installdevicefiles) installation request.

## Parameters

### `DeviceInfoSet` [in]

A handle to the [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains the device information element that represents the device for which to install files. The device information set must not contain remote elements.

### `DeviceInfoData` [in]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that specifies the device information element in *DeviceInfoSet*.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved with a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The caller of **SetupDiInstallDriverFiles** must be a member of the Administrators group if this function is being used to install files. However, if this function is being used to build up a file queue, membership in the Administrators group is not required.

**Note** Only a class installer should call **SetupDiInstallDriverFiles** and only in those situations where the class installer must perform driver file installation operations after **SetupDiInstallDriverFiles** completes the default driver file installation operation. In such situations, the class installer must directly call **SetupDiInstallDriverFiles** when the installer processes a DIF_INSTALLDEVICEFILES request. For more information about calling the default handler, see [Calling Default DIF Code Handlers](https://learn.microsoft.com/windows-hardware/drivers/install/calling-the-default-dif-code-handlers).

The operation of **SetupDiInstallDriverFiles** is similar to the [SetupDiInstallDevice](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiinstalldevice) function. However, this function performs only the file copy operations that are performed by **SetupDiInstallDevice**.

A driver must be selected for the specified device information set or element before this function is called.

This function processes the **CopyFiles**, **Delfiles**, and **Renfiles** entries in the selected INF file.

The *DeviceInfoSet* must only contain elements on the local computer.

## See also

[SetupDiCallClassInstaller](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicallclassinstaller)

[SetupDiInstallDevice](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiinstalldevice)