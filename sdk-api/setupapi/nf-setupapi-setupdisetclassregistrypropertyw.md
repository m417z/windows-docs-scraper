# SetupDiSetClassRegistryPropertyW function

## Description

The **SetupDiSetClassRegistryProperty** function sets a specified device class property in the registry.

## Parameters

### `ClassGuid` [in]

A pointer to the GUID that identifies the device class for which a property is to be set.

### `Property` [in]

A value that identifies the property to be set, which must be one of the following:

#### SPCRP_CHARACTERISTICS

The caller supplies flags that specify the device characteristics for the class. For a list of characteristics flags, see the *DeviceCharacteristics* parameter of [IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-iocreatedevice). Device characteristics should be set when the device class is installed and should not be changed after the device class is installed.

#### SPCRP_DEVTYPE

The caller supplies the device type for the class. For more information, see [Specifying Device Types](https://learn.microsoft.com/windows-hardware/drivers/kernel/specifying-device-types). Device type should be set when a device class is installed and should not be changed after the device class is installed.

#### SPCRP_EXCLUSIVE

The caller supplies a DWORD value that specifies whether users can obtain exclusive access to devices for this class. The supplied value is 1 if exclusive access is allowed, or zero otherwise. The exclusive setting for a device should be set when a device class is installed and should not be changed after the device class is installed.

#### SPCRP_LOWERFILTERS

(Windows Vista and later) The caller supplies a REG_MULTI_SZ list of the service names of the lower filter drivers that are installed for the [device setup class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-setup-classes). For more information about how to install a class filter driver, see [Installing a Filter Driver](https://learn.microsoft.com/windows-hardware/drivers/install/installing-a-filter-driver) and [INF ClassInstall32 Section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-classinstall32-section).

#### SPCRP_SECURITY

The caller supplies the device's security descriptor as a SECURITY_DESCRIPTOR structure in self-relative format (described in the Microsoft Windows SDK documentation).

#### SPCRP_SECURITY_SDS

The caller supplies the device's security descriptor as a text string. For information about security descriptor strings, see [Security Descriptor Definition Language (Windows)](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-definition-language). For information about the format of security descriptor strings, see Security Descriptor Definition Language (Windows).

#### SPCRP_UPPERFILTERS

(Windows Vista and later) The caller supplies a REG_MULTI_SZ list of the service names of the upper filter drivers that are installed for the device setup class. For more information about how to install a class filter driver, see [Installing a Filter Driver](https://learn.microsoft.com/windows-hardware/drivers/install/installing-a-filter-driver) and [INF ClassInstall32 Section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-classinstall32-section).

### `PropertyBuffer` [in, optional]

A pointer to a buffer that supplies the specified property. This parameter is optional and can be **NULL**.

### `PropertyBufferSize` [in]

The size, in bytes, of the *PropertyBuffer*  buffer.

### `MachineName` [in, optional]

A pointer to a NULL-terminated string that contains the name of a remote system on which to set the specified device class property. This parameter is optional and can be **NULL**. If this parameter is **NULL**, the property is set on the name of the local system.

> [!CAUTION]
> Using this function to access remote machines is not supported beginning with Windows 8 and Windows Server 2012, as this functionality has been removed.

### `Reserved`

Reserved, must be **NULL**.

##### - Property.SPCRP_CHARACTERISTICS

The caller supplies flags that specify the device characteristics for the class. For a list of characteristics flags, see the *DeviceCharacteristics* parameter of [IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-iocreatedevice). Device characteristics should be set when the device class is installed and should not be changed after the device class is installed.

##### - Property.SPCRP_DEVTYPE

The caller supplies the device type for the class. For more information, see [Specifying Device Types](https://learn.microsoft.com/windows-hardware/drivers/kernel/specifying-device-types). Device type should be set when a device class is installed and should not be changed after the device class is installed.

##### - Property.SPCRP_EXCLUSIVE

The caller supplies a DWORD value that specifies whether users can obtain exclusive access to devices for this class. The supplied value is 1 if exclusive access is allowed, or zero otherwise. The exclusive setting for a device should be set when a device class is installed and should not be changed after the device class is installed.

##### - Property.SPCRP_LOWERFILTERS

(Windows Vista and later) The caller supplies a REG_MULTI_SZ list of the service names of the lower filter drivers that are installed for the [device setup class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-setup-classes). For more information about how to install a class filter driver, see [Installing a Filter Driver](https://learn.microsoft.com/windows-hardware/drivers/install/installing-a-filter-driver) and [INF ClassInstall32 Section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-classinstall32-section).

##### - Property.SPCRP_SECURITY

The caller supplies the device's security descriptor as a SECURITY_DESCRIPTOR structure in self-relative format (described in the Microsoft Windows SDK documentation).

##### - Property.SPCRP_SECURITY_SDS

The caller supplies the device's security descriptor as a text string. For information about security descriptor strings, see [Security Descriptor Definition Language (Windows)](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-definition-language). For information about the format of security descriptor strings, see Security Descriptor Definition Language (Windows).

##### - Property.SPCRP_UPPERFILTERS

(Windows Vista and later) The caller supplies a REG_MULTI_SZ list of the service names of the upper filter drivers that are installed for the device setup class. For more information about how to install a class filter driver, see [Installing a Filter Driver](https://learn.microsoft.com/windows-hardware/drivers/install/installing-a-filter-driver) and [INF ClassInstall32 Section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-classinstall32-section).

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved with a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The caller of this function must be a member of the Administrators group.

To determine the data type for a device class property, call [SetupDiGetClassRegistryProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassregistrypropertya).

> [!NOTE]
> The setupapi.h header defines SetupDiSetClassRegistryProperty as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SetupDiGetClassRegistryProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassregistrypropertya)

[SetupDiGetDeviceRegistryProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceregistrypropertya)

[SetupDiSetDeviceRegistryProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetdeviceregistrypropertya)