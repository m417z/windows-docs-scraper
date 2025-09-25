# SetupDiSelectBestCompatDrv function

## Description

The **SetupDiSelectBestCompatDrv** function is the default handler for the [DIF_SELECTBESTCOMPATDRV](https://learn.microsoft.com/windows-hardware/drivers/install/dif-selectbestcompatdrv) installation request.

## Parameters

### `DeviceInfoSet` [in]

A handle to a [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains a device information element that represents the device for which to select the best compatible driver.

### `DeviceInfoData` [in, out]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that specifies the device information element in *DeviceInfoSet*. **SetupDiSelectBestCompatDrv** selects the best driver for a device information element from the compatible driver list for the specified device.

## Return value

If the operation succeeds, **SetupDiSelectBestCompatDrv** returns **TRUE**. Otherwise, the function returns **FALSE** and the logged error can be retrieved by a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the caller of **SetupDiSelectBestCompatDrv** is a member of the Administrators group and the class of the device is different that the class of the selected driver, **SetupDiSelectBestCompatDrv** sets the class of the device to the class of the driver. If this behavior is not desired, call this function at a lower privilege level.

**Note** Only a class installer should call **SetupDiSelectBestCompatDrv** and only in those situations where the class installer must perform driver selection operations after **SetupDiSelectBestCompatDrv** completes the default driver selection operation. In such situations, the class installer must directly call **SetupDiSelectBestCompatDrv** when the installer processes a DIF_SELECTBESTCOMPATDRV request. For more information about calling the default handler, see [Calling Default DIF Code Handlers](https://learn.microsoft.com/windows-hardware/drivers/install/calling-the-default-dif-code-handlers).

**SetupDiSelectBestCompatDrv**  is primarily designed to select the best compatible driver for a device information element on a local computer. Although **SetupDiSelectBestCompatDrv**  will not fail if the device information set is for a remote computer, the result is of limited use because the device information set cannot subsequently be used as input with DIF_*Xxx* installation requests or **SetupDi***Xxx* functions that do not support operations for a remote computer. In particular, the device information set cannot subsequently be used as input with a DIF_INSTALLDEVICE installation request to install a device on a remote computer.

For information about how the best driver is selected, see [How Windows Selects Drivers](https://learn.microsoft.com/windows-hardware/drivers/install/how-setup-selects-drivers).

To get the selected driver for a device, call [SetupDiGetSelectedDriver](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetselecteddrivera).

## See also

[DIF_SELECTBESTCOMPATDRV](https://learn.microsoft.com/windows-hardware/drivers/install/dif-selectbestcompatdrv)

[SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data)