# SetupDiDeleteDeviceInterfaceRegKey function

## Description

The **SetupDiDeleteDeviceInterfaceRegKey** function deletes the registry subkey that is used by applications and drivers to store interface-specific information.

## Parameters

### `DeviceInfoSet` [in]

A pointer to a [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains the interface for which to delete interface-specific information in the registry. The device information set must not contain remote elements.

### `DeviceInterfaceData` [in]

A pointer to an [SP_DEVICE_INTERFACE_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_device_interface_data) structure that specifies the device interface in *DeviceInfoSet*. This pointer is possibly returned by [SetupDiCreateDeviceInterface](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicreatedeviceinterfacea) or [SetupDiEnumDeviceInterfaces](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdienumdeviceinterfaces).

### `Reserved`

Reserved. Must be zero.

## Return value

**SetupDiDeleteDeviceInterfaceRegKey** returns **TRUE** if it is successful; otherwise, it returns **FALSE** and the logged error can be retrieved with a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The caller of this function must be a member of the Administrators group.

**SetupDiDeleteDeviceInterfaceRegKey** deletes the subkey used by drivers and applications to store information about the device interface instance. This subkey was created by [SetupDiCreateDeviceInterfaceRegKey](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicreatedeviceinterfaceregkeya) or by the driver's call to an associated [I/O manager routine](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#io-manager-routines). **SetupDiDeleteDeviceInterfaceRegKey** does not affect the main registry key for the device interface instance nor any other subkeys that may have been created.

The *DeviceInfoSet* must only contain elements on the local computer.

## See also

[SetupDiCreateDeviceInterface](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicreatedeviceinterfacea)

[SetupDiCreateDeviceInterfaceRegKey](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicreatedeviceinterfaceregkeya)