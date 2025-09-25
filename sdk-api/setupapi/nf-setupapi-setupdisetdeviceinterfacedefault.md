# SetupDiSetDeviceInterfaceDefault function

## Description

The **SetupDiSetDeviceInterfaceDefault** function sets a device interface as the default interface for a device interface class.

## Parameters

### `DeviceInfoSet` [in]

A handle to the [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains the device interface to set as the default for a device interface class.

### `DeviceInterfaceData` [in, out]

A pointer to an [SP_DEVICE_INTERFACE_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_device_interface_data) structure that specifies the device interface in *DeviceInfoSet*.

### `Flags` [in]

Not used, must be zero.

### `Reserved`

Reserved for future use, must be **NULL**.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved with a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

A caller must have Administrator privileges to set the default interface for a device interface class. However, if the requested default interface is the same as the currently set default interface, the function returns **TRUE** regardless of whether the caller has Administrator privileges.

If the function successfully sets the specified device interface as the default for the device class, it updates the Flags member of the supplied SP_DEVICE_INTERFACE_DATA structure.

Call [SetupDiGetClassDevs](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassdevsw) to obtain a *DevInfoSet* handle to a device information set that contains the device interface to set as the default for a device interface class. To obtain the *DeviceInterfaceData*  pointer to the device interface element, call [SetupDiEnumDeviceInterfaces](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdienumdeviceinterfaces) to enumerate the interfaces in the device information set. To retrieve information about an enumerated interface, call [SetupDiGetDeviceInterfaceDetail](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceinterfacedetaila).

## See also

[SetupDiEnumDeviceInterfaces](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdienumdeviceinterfaces)

[SetupDiGetClassDevs](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassdevsw)

[SetupDiGetDeviceInterfaceDetail](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceinterfacedetaila)