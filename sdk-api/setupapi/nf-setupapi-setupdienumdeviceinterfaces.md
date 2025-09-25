# SetupDiEnumDeviceInterfaces function

## Description

The **SetupDiEnumDeviceInterfaces** function enumerates the device interfaces that are contained in a device information set.

## Parameters

### `DeviceInfoSet` [in]

A pointer to a [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains the device interfaces for which to return information. This handle is typically returned by [SetupDiGetClassDevs](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassdevsw).

### `DeviceInfoData` [in, optional]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that specifies a device information element in *DeviceInfoSet*. This parameter is optional and can be **NULL**. If this parameter is specified, **SetupDiEnumDeviceInterfaces** constrains the enumeration to the interfaces that are supported by the specified device. If this parameter is **NULL**, repeated calls to **SetupDiEnumDeviceInterfaces** return information about the interfaces that are associated with all the device information elements in *DeviceInfoSet*. This pointer is typically returned by [SetupDiEnumDeviceInfo](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdienumdeviceinfo).

### `InterfaceClassGuid` [in]

A pointer to a GUID that specifies the device interface class for the requested interface.

### `MemberIndex` [in]

A zero-based index into the list of interfaces in the device information set. The caller should call this function first with *MemberIndex* set to zero to obtain the first interface. Then, repeatedly increment *MemberIndex* and retrieve an interface until this function fails and [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_NO_MORE_ITEMS.

If *DeviceInfoData* specifies a particular device, the *MemberIndex* is relative to only the interfaces exposed by that device.

### `DeviceInterfaceData` [out]

A pointer to a caller-allocated buffer that contains, on successful return, a completed [SP_DEVICE_INTERFACE_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_device_interface_data) structure that identifies an interface that meets the search parameters. The caller must set *DeviceInterfaceData*.**cbSize** to **sizeof**(SP_DEVICE_INTERFACE_DATA) before calling this function.

## Return value

**SetupDiEnumDeviceInterfaces** returns **TRUE** if the function completed without error. If the function completed with an error, **FALSE** is returned and the error code for the failure can be retrieved by calling [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Repeated calls to this function return an [SP_DEVICE_INTERFACE_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_device_interface_data) structure for a different device interface. This function can be called repeatedly to get information about interfaces in a device information set that are associated with a particular device information element or that are associated with all device information elements.

*DeviceInterfaceData* points to a structure that identifies a requested device interface. To get detailed information about an interface, call [SetupDiGetDeviceInterfaceDetail](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceinterfacedetaila). The detailed information includes the name of the device interface that can be passed to a Win32 function such as [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) (described in Microsoft Windows SDK documentation) to get a handle to the interface.

See [Overview of Device Interface Classes](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-interface-classes) for more info.

## See also

[SetupDiEnumDeviceInfo](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdienumdeviceinfo)

[SetupDiGetClassDevs](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassdevsw)

[SetupDiGetDeviceInterfaceDetail](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceinterfacedetaila)