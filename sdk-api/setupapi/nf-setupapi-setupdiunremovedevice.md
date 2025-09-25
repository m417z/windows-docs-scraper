# SetupDiUnremoveDevice function

## Description

The **SetupDiUnremoveDevice** function is the default handler for the [DIF_UNREMOVE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-unremove) installation request.

## Parameters

### `DeviceInfoSet` [in]

A handle to a [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) for the local system that contains a device information element that represents a device to restore and to restart.

### `DeviceInfoData` [in, out]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that specifies the device information element in *DeviceInfoSet*. This is an IN-OUT parameter because *DeviceInfoData.***DevInst** might be updated with a new handle value on return.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved by a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**SetupDiUnremoveDevice** restores a device to a hardware profile. This function starts the device, if possible, or it sets a flag in the device install parameters that eventually causes the user to be prompted to shut down the system.

**Note** Only a class installer should call **SetupDiUnremoveDevice** and only in those situations where the class installer must perform device unremove operations after **SetupDiUnremoveDevice** completes the default device unremove operation. In such situations, the class installer must directly call **SetupDiUnremoveDevice** when the installer processes a DIF_UNREMOVE request. For more information about calling the default handler, see [Calling Default DIF Code Handlers](https://learn.microsoft.com/windows-hardware/drivers/install/calling-the-default-dif-code-handlers).

The device being restored must have class install parameters for [DIF_UNREMOVE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-unremove) or the function fails and [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_NO_CLASSINSTALL_PARAMS.

The *DeviceInfoSet* must only contain elements on the local computer.

The caller of **SetupDiUnremoveDevice** must be a member of the Administrators group.

## See also

[DIF_UNREMOVE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-unremove)

[SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data)

[SetupDiRemoveDevice](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiremovedevice)