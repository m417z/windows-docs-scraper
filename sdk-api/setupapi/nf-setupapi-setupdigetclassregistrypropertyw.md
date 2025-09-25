# SetupDiGetClassRegistryPropertyW function

## Description

The **SetupDiGetClassRegistryProperty** function retrieves a property for a specified [device setup class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-setup-classes) from the registry.

## Parameters

### `ClassGuid` [in]

A pointer to a GUID representing the device setup class for which a property is to be retrieved.

### `Property` [in]

A value that identifies the property to be retrieved. This must be one of the following values:

#### SPCRP_CHARACTERISTICS

The function returns flags indicating device characteristics for the class. For a list of characteristics flags, see the *DeviceCharacteristics* parameter to [IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-iocreatedevice).

#### SPCRP_DEVTYPE

The function returns a DWORD value that represents the device type for the class. For more information, see [Specifying Device Types](https://learn.microsoft.com/windows-hardware/drivers/kernel/specifying-device-types).

#### SPCRP_EXCLUSIVE

The function returns a DWORD value indicating whether users can obtain exclusive access to devices for this class. The returned value is one if exclusive access is allowed, or zero otherwise.

#### SPCRP_LOWERFILTERS

(Windows Vista and later) The function returns a REG_MULTI_SZ list of the service names of the lower filter drivers that are installed for the device setup class.

#### SPCRP_SECURITY

The function returns the device's security descriptor as a SECURITY_DESCRIPTOR structure in self-relative format (described in the Microsoft Windows SDK documentation).

#### SPCRP_SECURITY_SDS

The function returns the device's security descriptor as a text string. For information about security descriptor strings, see [Security Descriptor Definition Language (Windows)](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-definition-language). For information about the format of security descriptor strings, see Security Descriptor Definition Language (Windows).

#### SPCRP_UPPERFILTERS

(Windows Vista and later) The function returns a REG_MULTI_SZ list of the service names of the upper filter drivers that are installed for the device setup class.

### `PropertyRegDataType` [out, optional]

A pointer to a variable of type DWORD that receives the property data type as one of the REG_-prefixed registry data types. This parameter is optional and can be **NULL**. If this parameter is **NULL**, **SetupDiGetClassRegistryProperty** does not return the data type.

### `PropertyBuffer` [out]

A pointer to a buffer that receives the requested property.

### `PropertyBufferSize` [in]

The size, in bytes, of the *PropertyBuffer*  buffer.

### `RequiredSize` [out, optional]

A pointer to a variable of type DWORD that receives the required size, in bytes, of the *PropertyBuffer*  buffer. If the *PropertyBuffer* buffer is too small, and *RequiredSize* is not **NULL**, the function sets *RequiredSize* to the minimum buffer size that is required to receive the requested property.

### `MachineName` [in, optional]

A pointer to a NULL-terminated string that contains the name of a remote system from which to retrieve the specified device class property. This parameter is optional and can be **NULL**. If this parameter is **NULL**, the property is retrieved from the local system.

> [!CAUTION]
> Using this function to access remote machines is not supported beginning with Windows 8 and Windows Server 2012, as this functionality has been removed.

### `Reserved`

Reserved, must be **NULL**.

##### - Property.SPCRP_CHARACTERISTICS

The function returns flags indicating device characteristics for the class. For a list of characteristics flags, see the *DeviceCharacteristics* parameter to [IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-iocreatedevice).

##### - Property.SPCRP_DEVTYPE

The function returns a DWORD value that represents the device type for the class. For more information, see [Specifying Device Types](https://learn.microsoft.com/windows-hardware/drivers/kernel/specifying-device-types).

##### - Property.SPCRP_EXCLUSIVE

The function returns a DWORD value indicating whether users can obtain exclusive access to devices for this class. The returned value is one if exclusive access is allowed, or zero otherwise.

##### - Property.SPCRP_LOWERFILTERS

(Windows Vista and later) The function returns a REG_MULTI_SZ list of the service names of the lower filter drivers that are installed for the device setup class.

##### - Property.SPCRP_SECURITY

The function returns the device's security descriptor as a SECURITY_DESCRIPTOR structure in self-relative format (described in the Microsoft Windows SDK documentation).

##### - Property.SPCRP_SECURITY_SDS

The function returns the device's security descriptor as a text string. For information about security descriptor strings, see [Security Descriptor Definition Language (Windows)](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-definition-language). For information about the format of security descriptor strings, see Security Descriptor Definition Language (Windows).

##### - Property.SPCRP_UPPERFILTERS

(Windows Vista and later) The function returns a REG_MULTI_SZ list of the service names of the upper filter drivers that are installed for the device setup class.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved with a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[SetupDiGetDeviceRegistryProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceregistrypropertya)

[SetupDiSetClassRegistryProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetclassregistrypropertya)

[SetupDiSetDeviceRegistryProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetdeviceregistrypropertya)

## Remarks

> [!NOTE]
> The setupapi.h header defines SetupDiGetClassRegistryProperty as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).