# SetupDiGetDeviceInstanceIdW function

## Description

The **SetupDiGetDeviceInstanceId** function retrieves the [device instance ID](https://learn.microsoft.com/windows-hardware/drivers/install/device-instance-ids) that is associated with a device information element.

> [!NOTE]
> In Windows Vista and later versions of Windows, the [unified device property model](https://learn.microsoft.com/windows-hardware/drivers/install/unified-device-property-model--windows-vista-and-later-) uses the [**DEVPKEY_Device_InstanceId**](https://learn.microsoft.com/windows-hardware/drivers/install/devpkey-device-instanceid) [property key](https://learn.microsoft.com/windows-hardware/drivers/install/property-keys) to represent the device instance identifier. See [Retrieving a Device Instance Identifier](https://learn.microsoft.com/windows-hardware/drivers/install/retrieving-a-device-instance-identifier) for details.

## Parameters

### `DeviceInfoSet` [in]

A handle to the [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains the device information element that represents the device for which to retrieve a device instance ID.

### `DeviceInfoData` [in]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that specifies the device information element in *DeviceInfoSet*.

### `DeviceInstanceId` [out, optional]

A pointer to the character buffer that will receive the NULL-terminated device instance ID for the specified device information element. For information about device instance IDs, see [Device Identification Strings](https://learn.microsoft.com/windows-hardware/drivers/install/device-identification-strings).

### `DeviceInstanceIdSize` [in]

The size, in characters, of the *DeviceInstanceId* buffer.

### `RequiredSize` [out, optional]

A pointer to the variable that receives the number of characters required to store the device instance ID.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved by making a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data)

[SetupDiCreateDevRegKey](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicreatedevregkeya)

[SetupDiCreateDeviceInfo](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicreatedeviceinfoa)

[SetupDiOpenDevRegKey](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiopendevregkey)

[SetupDiOpenDeviceInfo](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiopendeviceinfoa)

## Remarks

> [!NOTE]
> The setupapi.h header defines SetupDiGetDeviceInstanceId as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).