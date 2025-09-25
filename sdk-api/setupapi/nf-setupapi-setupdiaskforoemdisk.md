# SetupDiAskForOEMDisk function

## Description

The **SetupDiAskForOEMDisk** function displays a dialog that asks the user for the path of an OEM installation disk.

## Parameters

### `DeviceInfoSet` [in]

A handle to a [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) for the local computer. This set contains a device information element that represents the device that is being installed.

### `DeviceInfoData` [in, optional]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that specifies the device information element in *DeviceInfoSet*. This parameter is optional and can be **NULL**. If this parameter is specified, **SetupDiAskForOEMDisk** associates the driver with the device that is being installed. If this parameter is **NULL**, **SetupDiAskForOEMDisk** associates the driver with the global class driver list for *DeviceInfoSet*.

## Return value

The function returns **TRUE** if it is successful and the **DriverPath** field of the SP_DEVINSTALLPARAMS structure is updated to reflect the new path. If the user cancels the dialog, the function returns **FALSE** and a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_CANCELLED.

## Remarks

**SetupDiAskForOEMDisk** allows the user to browse local and network drives for OEM installation files. However, **SetupDiAskForOEMDisk** is primarily designed to obtain the path of an OEM driver on a local computer before selecting and installing the driver for a device on that computer.

Although this function will not fail if the device information set if for a remote computer, the result is of limited use because the device information set cannot subsequently be used with DIF_*Xxx* installation requests or **SetupDi***Xxx* functions that do not support operations on a remote computer.

In particular, the device information set cannot be used as input with a DIF_SELECTDEVICE installation request to select a driver for a device, followed by a DIF_INSTALLDEVICE installation request to install a device on a remote computer.

## See also

[SetupDiSelectOEMDrv](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiselectoemdrv)