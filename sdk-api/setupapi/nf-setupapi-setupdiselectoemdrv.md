# SetupDiSelectOEMDrv function

## Description

The **SetupDiSelectOEMDrv** function selects a driver for a device information set or a particular device information element that uses an OEM path supplied by the user.

## Parameters

### `hwndParent` [in, optional]

A window handle that will be the parent of any dialogs created during the processing of this function. This parameter can be used to override the **hwndParent** field in the installation parameters block of the specified device information set or element.

### `DeviceInfoSet` [in]

A handle to the [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) for which to select a driver.

### `DeviceInfoData` [in, out]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that specifies a device information element in *DeviceInfoSet*. This parameter is optional and can be **NULL**. If this parameter is specified, **SetupDiSelectOEMDrv** associates the selected driver with the specified device. If this parameter is **NULL**, **SetupDiSelectOEMDrv** associates the selected driver with the global class driver list for *DeviceInfoSet*.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved by a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**SetupDiSelectOEMDrv**  is primarily designed to select an OEM driver for a device on a local computer before installing the device on that computer. Although **SetupDiSelectOEMDrv** will not fail if the device information set is for a remote computer, the result is of limited use because the device information set cannot subsequently be used with DIF_*Xxx* installation requests or **SetupDi***Xxx* functions that do not support operations on a remote computer. In particular, the device information set cannot be used as input with a DIF_INSTALLDEVICE installation request to install a device on a remote computer.

**SetupDiSelectOEMDrv** prompts the user for the OEM path and then calls the class installer to select a driver from the OEM path.

## See also

[SetupDiAskForOEMDisk](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiaskforoemdisk)