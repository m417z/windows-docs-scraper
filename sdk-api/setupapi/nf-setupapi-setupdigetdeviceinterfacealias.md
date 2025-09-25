# SetupDiGetDeviceInterfaceAlias function

## Description

The **SetupDiGetDeviceInterfaceAlias** function returns an alias of a specified device interface.

## Parameters

### `DeviceInfoSet` [in]

A pointer to the [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains the device interface for which to retrieve an alias. This handle is typically returned by [SetupDiGetClassDevs](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassdevsw).

### `DeviceInterfaceData` [in]

A pointer to an [SP_DEVICE_INTERFACE_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_device_interface_data) structure that specifies the device interface in *DeviceInfoSet* for which to retrieve an alias. This pointer is typically returned by [SetupDiEnumDeviceInterfaces](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdienumdeviceinterfaces).

### `AliasInterfaceClassGuid` [in]

A pointer to a GUID that specifies the interface class of the alias to retrieve.

### `AliasDeviceInterfaceData` [out]

A pointer to a caller-allocated buffer that contains, on successful return, a completed [SP_DEVICE_INTERFACE_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_device_interface_data) structure that identifies the requested alias. The caller must set *AliasDeviceInterfaceData***.cbSize** to **sizeof**(SP_DEVICE_INTERFACE_DATA) before calling this function.

## Return value

**SetupDiGetDeviceInterfaceAlias** returns **TRUE** if the function completed without error. If the function completed with an error, **FALSE** is returned and the error code for the failure can be retrieved by calling [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

Possible errors returned by [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) are listed in the following table.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | Invalid *DeviceInfoSet* or invalid *DeviceInterfaceData* parameter. |
| **ERROR_NO_SUCH_INTERFACE_DEVICE** | There is no alias of class *AliasInterfaceClassGuid* for the specified device interface. |
| **ERROR_INVALID_USER_BUFFER** | Invalid *AliasDeviceInterfaceData* buffer. |

## Remarks

Device interfaces are considered aliases if they are of different interface classes but are supported by the same device and have identical reference strings.

**SetupDiGetDeviceInterfaceAlias** can be used to locate a device that exposes more than one interface. For example, consider a disk that can be part of a fault-tolerant volume and can contain encrypted data. The function driver for the disk device could register a fault-tolerant-volume interface and an encrypted-volume interface. These interfaces are device interface aliases if the function driver registers them with identical reference strings and they refer to the same device. (The reference strings will likely be **NULL** and therefore are equal.)

To locate such a multi-interface device, first locate all available devices that expose one of the interfaces, such as the fault-tolerant-volume interface, using [SetupDiGetClassDevs](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassdevsw) and [SetupDiEnumDeviceInterfaces](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdienumdeviceinterfaces). Then, pass a device with the first interface (fault-tolerant-volume) to **SetupDiGetDeviceInterfaceAlias** and request an alias of the other interface class (encrypted-volume).

If the requested alias exists but the caller-supplied *AliasDeviceInterfaceData* buffer is invalid, this function successfully adds the device interface element to *DevInfoSet* but returns **FALSE** for the return value. In this case, [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_INVALID_USER_BUFFER.

## See also

[SetupDiEnumDeviceInterfaces](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdienumdeviceinterfaces)

[SetupDiGetClassDevs](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassdevsw)