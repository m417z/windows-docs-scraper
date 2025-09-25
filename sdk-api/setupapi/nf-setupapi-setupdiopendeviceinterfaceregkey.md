# SetupDiOpenDeviceInterfaceRegKey function

## Description

The **SetupDiOpenDeviceInterfaceRegKey** function opens the registry subkey that is used by applications and drivers to store information that is specific to a device interface.

## Parameters

### `DeviceInfoSet` [in]

A pointer to a [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains the device interface for which to open a registry subkey.

### `DeviceInterfaceData` [in]

A pointer to an [SP_DEVICE_INTERFACE_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_device_interface_data) structure that specifies the device interface. This pointer can be returned by [SetupDiCreateDeviceInterface](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicreatedeviceinterfacea) or [SetupDiEnumDeviceInterfaces](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdienumdeviceinterfaces).

### `Reserved`

Reserved. Must be zero.

### `samDesired` [in]

The requested registry security access to the registry subkey. For information about registry security access values of type REGSAM, see the Microsoft Windows SDK documentation.

## Return value

**SetupDiOpenDeviceInterfaceRegKey** returns a handle to the opened registry key. If the function fails, it returns INVALID_HANDLE_VALUE. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Depending on the value that is passed in the *samDesired* parameter, it might be necessary for the caller of this function to be a member of the Administrators group.

Close the handle returned from by function by calling [RegCloseKey](https://learn.microsoft.com/windows/win32/api/winreg/nf-winreg-regclosekey).

## See also

[SetupDiCreateDeviceInterface](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicreatedeviceinterfacea)

[SetupDiCreateDeviceInterfaceRegKey](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicreatedeviceinterfaceregkeya)

[SetupDiEnumDeviceInterfaces](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdienumdeviceinterfaces)