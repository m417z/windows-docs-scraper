# SetupDiCreateDeviceInterfaceRegKeyW function

## Description

The **SetupDiCreateDeviceInterfaceRegKey** function creates a registry key for storing information about a device interface and returns a handle to the key.

## Parameters

### `DeviceInfoSet` [in]

A handle to a [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains the interface for which to create a registry key. The device information set must not contain remote elements.

### `DeviceInterfaceData` [in]

A pointer to an [SP_DEVICE_INTERFACE_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_device_interface_data) structure that specifies the device interface in *DeviceInfoSet*. This pointer is possibly returned by [SetupDiCreateDeviceInterface](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicreatedeviceinterfacea).

### `Reserved`

Reserved. Must be zero.

### `samDesired` [in]

The registry security access that the caller requests for the key that is being created. For information about registry security access values of type REGSAM, see the Microsoft Windows SDK documentation.

### `InfHandle` [in, optional]

The handle to an open INF file that contains a *DDInstall* section to be executed for the newly-created key. This parameter is optional and can be **NULL**. If this parameter is not **NULL**, *InfSectionName* must be specified as well.

### `InfSectionName` [in, optional]

A pointer to the name of an INF *DDInstall* section in the INF file that is specified by *InfHandle*. This section is executed for the newly created key. This parameter is optional and can be **NULL**. If this parameter is specified, *InfHandle* must be specified as well.

## Return value

If **SetupDiCreateDeviceInterfaceRegKey** succeeds, the function returns a handle to the requested registry key in which interface information can be stored and retrieved. If **SetupDiCreateDeviceInterfaceRegKey** fails, the function returns INVALID_HANDLE_VALUE. Call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) to get extended error information.

## Remarks

The caller of this function must be a member of the Administrators group.

If the requested key for the device interface already exists, **SetupDiCreateDeviceInterfaceRegKey** returns a handle to that key; otherwise, **SetupDiCreateDeviceInterfaceRegKey** creates a new nonvolatile registry key for the specified device interface. Callers of this function can store private configuration data for the device interface in this key. The driver for the device can access this key using **Io***Xxx* routines.

Close the handle returned from this function by calling [RegCloseKey](https://learn.microsoft.com/windows/win32/api/winreg/nf-winreg-regclosekey).

For installations that use layout files (specified by the **LayoutFile** entry in an [INF Version section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-version-section)), the layout file must be opened by a call to **SetupOpenAppendInfFile** (described in Windows SDK documentation) before **SetupDiCreateDeviceInterfaceRegKey** is called.

The device information set specified by *DeviceInfoSet* must only contain elements on the local computer.

> [!NOTE]
> The setupapi.h header defines SetupDiCreateDeviceInterfaceRegKey as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SetupDiCreateDeviceInterface](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicreatedeviceinterfacea)

[SetupDiDeleteDeviceInterfaceRegKey](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdideletedeviceinterfaceregkey)

[SetupDiOpenDeviceInterfaceRegKey](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiopendeviceinterfaceregkey)