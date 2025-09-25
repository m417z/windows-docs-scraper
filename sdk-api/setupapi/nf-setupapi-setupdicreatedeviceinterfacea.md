# SetupDiCreateDeviceInterfaceA function

## Description

The **SetupDiCreateDeviceInterface** function registers a device interface on a local system or a remote system.

## Parameters

### `DeviceInfoSet` [in]

A handle to a [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets). This set contains a device information element that represents the device for which to register an interface. This handle is typically returned by [SetupDiGetClassDevs](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassdevsw).

### `DeviceInfoData` [in]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that specifies the device information element in *DeviceInfoSet*.

### `InterfaceClassGuid` [in]

A pointer to a class GUID that specifies the interface class for the new interface.

### `ReferenceString` [in, optional]

A pointer to a NULL-terminated string that supplies a reference string. This pointer is optional and can be **NULL**. Reference strings are used only by a few bus drivers that use device interfaces as placeholders for software devices that are created on demand.

### `CreationFlags` [in]

Reserved. Must be zero.

### `DeviceInterfaceData` [out, optional]

A pointer to a caller-initialized [SP_DEVICE_INTERFACE_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_device_interface_data) structure to receive information about the new device interface. This pointer is optional and can be **NULL**. If the structure is supplied, the caller must set the **cbSize** member of this structure to **sizeof(**SP_DEVICE_INTERFACE_DATA**)** before calling this function. For more information, see the following **Remarks** section.

## Return value

**SetupDiCreateDeviceInterface** returns **TRUE** if the function completed without error. If the function completed with an error, it returns **FALSE** and the error code for the failure can be retrieved by calling [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The caller of this function must be a member of the Administrators group.

**SetupDiCreateDeviceInterface** registers an interface for a device. If a device has more than one interface, call this function once for each interface being registered.

If this function successfully registers an interface for the device that corresponds to the specified device information element, it also adds the interface to the interface list that is associated with the device information element in the specified device information set.

Before a registered interface can be used by applications and other system components the interface must be enabled by the driver for the device.

This function creates a registry key for the new device interface. Callers of this function can access nonvolatile storage under this key using [SetupDiOpenDeviceInterfaceRegKey](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiopendeviceinterfaceregkey).

If **SetupDiCreateDeviceInterface** successfully creates a new device interface, but the caller-supplied buffer in the *DeviceInterfaceData* parameter is invalid, this function will return **FALSE** and a subsequent call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) will return ERROR_INVALID_USER_BUFFER. However, the function does create and register the new device interface.

> [!NOTE]
> The setupapi.h header defines SetupDiCreateDeviceInterface as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SetupDiOpenDeviceInterfaceRegKey](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiopendeviceinterfaceregkey)

[SetupDiRemoveDeviceInterface](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiremovedeviceinterface)