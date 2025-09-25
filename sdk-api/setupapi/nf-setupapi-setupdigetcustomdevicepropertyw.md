# SetupDiGetCustomDevicePropertyW function

## Description

The **SetupDiGetCustomDeviceProperty** function retrieves a specified custom device property from the registry.

## Parameters

### `DeviceInfoSet` [in]

A handle to the [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains a device information element that represents the device for which to retrieve a custom device property.

### `DeviceInfoData` [in]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that specifies the device information element in *DeviceInfoSet*.

### `CustomPropertyName` [in]

A registry value name representing a custom property.

### `Flags` [in]

A flag value that indicates how the requested information should be returned. The flag can be zero or one of the following:

#### DICUSTOMDEVPROP_MERGE_MULTISZ

If set, the function retrieves both device instance-specific property values and hardware ID-specific property values, concatenated as a REG_MULTI_SZ-typed string. (For more information, see the **Remarks** section on this reference page.)

### `PropertyRegDataType` [out, optional]

A pointer to a variable of type DWORD that receives the data type of the retrieved property. The data type is specified as one of the REG_-prefixed constants that represents registry data types. This parameter is optional and can be **NULL**.

### `PropertyBuffer` [out]

A pointer to a buffer that receives requested property information.

### `PropertyBufferSize` [in]

The size, in bytes, of the *PropertyBuffer*  buffer.

### `RequiredSize` [out, optional]

A pointer to a variable of type DWORD that receives the buffer size, in bytes, that is required to receive the requested information. This parameter is optional and can be **NULL**. If this parameter is specified, **SetupDiGetCustomDeviceProperty** returns the required size, regardless of whether the *PropertyBuffer* buffer is large enough to receive the requested information.

##### - Flags.DICUSTOMDEVPROP_MERGE_MULTISZ

If set, the function retrieves both device instance-specific property values and hardware ID-specific property values, concatenated as a REG_MULTI_SZ-typed string. (For more information, see the **Remarks** section on this reference page.)

## Return value

If the operation succeeds, **SetupDiGetCustomDeviceProperty** returns **TRUE**. Otherwise, the function returns **FALSE** and the logged error can be retrieved with a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror). If the *PropertyBuffer*  buffer is not large enough to receive the requested information, **SetupDiGetCustomDeviceProperty** returns **FALSE** and a subsequent call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) will return ERROR_INSUFFICIENT_BUFFER.

## Remarks

**SetupDiGetCustomDeviceProperty** retrieves device properties that are associated with a single device instance or with all devices matching a certain hardware ID. (For information about hardware IDs, see [Device Identification Strings](https://learn.microsoft.com/windows-hardware/drivers/install/device-identification-strings)).

Vendors can set properties for a device instance by using [INF AddReg directives](https://learn.microsoft.com/windows-hardware/drivers/install/inf-addreg-directive) in [INF DDInstall.HW sections](https://learn.microsoft.com/windows-hardware/drivers/install/inf-ddinstall-hw-section) and specifying the **HKR** registry root.

Only the system can set properties for hardware IDs. The system supplies an "Icon" property for some hardware IDs.

The function first checks to see if the specified property exists for the specified device instance. If so, the property's value is returned. If not, the function checks to see if the property exists for all devices matching the hardware ID of the specified device instance. If so, the property's value is returned. If DICUSTOMDEVPROP_MERGE_MULTISZ is set in *Flags*, the function returns the property values associated with both the device instance and the hardware ID, if they both exist.

> [!NOTE]
> The setupapi.h header defines SetupDiGetCustomDeviceProperty as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SetupDiGetClassRegistryProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassregistrypropertya)

[SetupDiGetDeviceRegistryProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceregistrypropertya)

[SetupDiOpenDevRegKey](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiopendevregkey)

[SetupDiSetClassRegistryProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetclassregistrypropertya)

[SetupDiSetDeviceRegistryProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetdeviceregistrypropertya)