# SetupDiRemoveDeviceInterface function

## Description

The **SetupDiRemoveDeviceInterface** function removes a registered device interface from the system.

## Parameters

### `DeviceInfoSet` [in]

A pointer to the [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains the device interface to remove. This handle is typically returned by **SetupDiGetClassDevs**.

### `DeviceInterfaceData` [in, out]

A pointer to an [SP_DEVICE_INTERFACE_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_device_interface_data) structure that specifies the device interface in *DeviceInfoSet* to remove. This pointer is typically returned by [SetupDiEnumDeviceInterfaces](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdienumdeviceinterfaces).

After the interface is removed, this function sets the SPINT_REMOVED flag in *DeviceInterfaceData***.Flags**. It also clears the SPINT_ACTIVE flag, but be aware that this flag should have already been cleared before this function was called.

## Return value

**SetupDiRemoveDeviceInterface** returns **TRUE** if the function completed without error. If the function completed with an error, it returns **FALSE** and the error code for the failure can be retrieved by calling [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The caller of this function must be a member of the Administrators group.

**SetupDiRemoveDeviceInterface** removes the specified device interface from the system. This includes deleting the associated registry key.

Call [SetupDiDeleteDeviceInterfaceData](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdideletedeviceinterfacedata) to delete the interface from a device information list.

A device interface must be disabled to be removed. If the interface is enabled, this function fails and [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_DEVICE_INTERFACE_ACTIVE. Disable an interface by using whatever interface-specific mechanism is provided (for example, an IOCTL). If the caller has no way to disable an interface and the interface must be removed, the caller must stop the underlying device by using [SetupDiChangeState](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdichangestate). Stopping the device disables all the interfaces exposed by the device.

## See also

[SetupDiChangeState](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdichangestate)

[SetupDiCreateDeviceInterface](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicreatedeviceinterfacea)

[SetupDiDeleteDeviceInterfaceData](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdideletedeviceinterfacedata)

[SetupDiEnumDeviceInterfaces](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdienumdeviceinterfaces)

[SetupDiGetClassDevs](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassdevsw)