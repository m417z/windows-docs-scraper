# SetupDiDeleteDeviceInterfaceData function

## Description

The **SetupDiDeleteDeviceInterfaceData** function deletes a device interface from a device information set.

## Parameters

### `DeviceInfoSet` [in]

A pointer to the [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains the interface to delete. This handle is typically returned by [SetupDiGetClassDevs](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassdevsw).

### `DeviceInterfaceData` [in]

A pointer to an [SP_DEVICE_INTERFACE_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_device_interface_data) structure that specifies the interface in *DeviceInfoSet* to delete. This structure is typically returned by [SetupDiEnumDeviceInterfaces](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdienumdeviceinterfaces).

## Return value

**SetupDiDeleteDeviceInterfaceData** returns **TRUE** if the function completed without error. If the function completed with an error, it returns **FALSE** and the error code for the failure can be retrieved by calling [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**SetupDiDeleteDeviceInterfaceData** deletes a device interface element from a device information set. This function has no effect on the device interface or the underlying device.

## See also

[SetupDiEnumDeviceInterfaces](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdienumdeviceinterfaces)

[SetupDiGetClassDevs](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassdevsw)

[SetupDiOpenDeviceInterface](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiopendeviceinterfacea)

[SetupDiRemoveDeviceInterface](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiremovedeviceinterface)