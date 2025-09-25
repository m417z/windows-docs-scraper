# SetupDiOpenDeviceInterfaceA function

## Description

The **SetupDiOpenDeviceInterface** function retrieves information about a device interface and adds the interface to the specified device information set for a local system or a remote system.

## Parameters

### `DeviceInfoSet` [in]

A pointer to a [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains, or will contain, a device information element that represents the device that supports the interface to open.

### `DevicePath` [in]

A pointer to a NULL-terminated string that supplies the name of the device interface to be opened. This name is a Win32 device path that is typically received in a PnP notification structure or obtained by a previous call to [SetupDiEnumDeviceInterfaces](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdienumdeviceinterfaces) and its related functions.

### `OpenFlags` [in]

Flags that determine how the device interface element is to be opened. The only valid flag is as follows:

#### DIODI_NO_ADD

Specifies that the device information element for the underlying device will not be created if that element is not already present in the specified [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets). For more information, see the following **Remarks** section.

### `DeviceInterfaceData` [out, optional]

A pointer to a caller-initialized [SP_DEVICE_INTERFACE_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_device_interface_data) structure that receives the requested interface data. This pointer is optional and can be **NULL**. If a buffer is supplied, the caller must set the **cbSize** member of the structure to **sizeof(**SP_DEVICE_INTERFACE_DATA**)** before calling **SetupDiOpenDeviceInterface**. For more information, see the following **Remarks** section.

## Return value

**SetupDiOpenDeviceInterface** returns **TRUE** if the function completed without error. If the function completed with an error, it returns **FALSE** and the error code for the failure can be retrieved by calling [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If a device interface element for the interface already exists in *DeviceInfoSet*, **SetupDiOpenDeviceInterface** updates the flags. Therefore, this function can be used to update the flags for a device interface. For example, an interface might have been inactive when it was first opened, but has subsequently become active. If the device information element for the underlying device is not already present in *DeviceInfoSet*, this function creates one and adds it to *DeviceInfoSet*.

If the function successfully opens the new device interface but the caller did not supply a valid structure in the *DeviceInterfaceData* parameter, the function will return **FALSE** and a subsequent call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) will return ERROR_INVALID_USER_BUFFER. However, in this situation, **SetupDiOpenDeviceInterface** does add the requested interface to the device information set.

If the new device interface is successfully opened, but the caller-supplied *DeviceInterfaceData* buffer is invalid, this function returns **FALSE** and [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_INVALID_USER_BUFFER. The caller's buffer error does not prevent the interface from being opened.

If the DIODI_NO_ADD flag is specified for the *OpenFlags* parameter, and a device information element for the underlying device is not already present in the specified [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets), this function returns **FALSE** and [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_NO_SUCH_DEVICE_INTERFACE.

When the application has finished using the information that **SetupDiOpenDeviceInterface** retrieved**,** the application must call [SetupDiDeleteDeviceInterfaceData](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdideletedeviceinterfacedata).

[MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_SYMBOLIC_LINK](https://learn.microsoft.com/windows/desktop/medfound/mf-devsource-attribute-source-type-vidcap-symbolic-link) attribute can be passed in as the value of the *DevicePath* argument of the **SetupDiOpenDeviceInterface** function.

> [!NOTE]
> The setupapi.h header defines SetupDiOpenDeviceInterface as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SetupDiDeleteDeviceInterfaceData](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdideletedeviceinterfacedata)

[SetupDiEnumDeviceInterfaces](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdienumdeviceinterfaces)