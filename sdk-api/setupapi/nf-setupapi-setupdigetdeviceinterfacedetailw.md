# SetupDiGetDeviceInterfaceDetailW function

## Description

The **SetupDiGetDeviceInterfaceDetail** function returns details about a device interface.

## Parameters

### `DeviceInfoSet` [in]

A pointer to the [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains the interface for which to retrieve details. This handle is typically returned by [SetupDiGetClassDevs](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassdevsw).

### `DeviceInterfaceData` [in]

A pointer to an [SP_DEVICE_INTERFACE_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_device_interface_data) structure that specifies the interface in *DeviceInfoSet* for which to retrieve details. A pointer of this type is typically returned by [SetupDiEnumDeviceInterfaces](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdienumdeviceinterfaces).

### `DeviceInterfaceDetailData` [out, optional]

A pointer to an [SP_DEVICE_INTERFACE_DETAIL_DATA](https://learn.microsoft.com/windows/win32/api/setupapi/ns-setupapi-sp_device_interface_detail_data_a) structure to receive information about the specified interface. This parameter is optional and can be **NULL**. This parameter must be **NULL** if *DeviceInterfaceDetailSize* is zero. If this parameter is specified, the caller must set *DeviceInterfaceDetailData***.cbSize** to **sizeof**(SP_DEVICE_INTERFACE_DETAIL_DATA) before calling this function. The **cbSize** member always contains the size of the fixed part of the data structure, not a size reflecting the variable-length string at the end.

### `DeviceInterfaceDetailDataSize` [in]

The size of the *DeviceInterfaceDetailData* buffer. The buffer must be at least (**offsetof**(SP_DEVICE_INTERFACE_DETAIL_DATA, **DevicePath**) + **sizeof**(TCHAR)) bytes, to contain the fixed part of the structure and a single **NULL** to terminate an empty MULTI_SZ string.

This parameter must be zero if *DeviceInterfaceDetailData* is **NULL**.

### `RequiredSize` [out, optional]

A pointer to a variable of type DWORD that receives the required size of the *DeviceInterfaceDetailData* buffer. This size includes the size of the fixed part of the structure plus the number of bytes required for the variable-length device path string. This parameter is optional and can be **NULL**.

### `DeviceInfoData` [out, optional]

A pointer to a buffer that receives information about the device that supports the requested interface. The caller must set *DeviceInfoData***.cbSize** to **sizeof**(SP_DEVINFO_DATA). This parameter is optional and can be **NULL**.

## Return value

**SetupDiGetDeviceInterfaceDetail** returns **TRUE** if the function completed without error. If the function completed with an error, **FALSE** is returned and the error code for the failure can be retrieved by calling [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Using this function to get details about an interface is typically a two-step process:

1. Get the required buffer size. Call **SetupDiGetDeviceInterfaceDetail** with a **NULL***DeviceInterfaceDetailData* pointer, a *DeviceInterfaceDetailDataSize* of zero, and a valid *RequiredSize* variable. In response to such a call, this function returns the required buffer size at *RequiredSize* and fails with [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returning ERROR_INSUFFICIENT_BUFFER.
2. Allocate an appropriately sized buffer and call the function again to get the interface details.

The interface detail returned by this function consists of a device path that can be passed to Win32 functions such as [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea). Do not attempt to parse the device path symbolic name. The device path can be reused across system starts.

**SetupDiGetDeviceInterfaceDetail** can be used to get just the *DeviceInfoData*. If the interface exists but *DeviceInterfaceDetailData* is **NULL**, this function fails, [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_INSUFFICIENT_BUFFER, and the *DeviceInfoData* structure is filled with information about the device that exposes the interface.

> [!NOTE]
> The setupapi.h header defines SetupDiGetDeviceInterfaceDetail as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SetupDiEnumDeviceInterfaces](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdienumdeviceinterfaces)

[SetupDiGetClassDevs](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassdevsw)