# SetupDiSetDeviceRegistryPropertyW function

## Description

The **SetupDiSetDeviceRegistryProperty** function sets a Plug and Play device property for a device.

## Parameters

### `DeviceInfoSet` [in]

A handle to the [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains a device information element that represents the device for which to set a Plug and Play device property.

### `DeviceInfoData` [in, out]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that specifies the device information element in *DeviceInfoSet*. If the **ClassGuid** property is set, *DeviceInfoData.***ClassGuid** is set upon return to the new class for the device.

### `Property` [in]

One of the following values, which identifies the property to be set. For descriptions of these values, see [SetupDiGetDeviceRegistryProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceregistrypropertya).

* SPDRP_CONFIGFLAGS
* SPDRP_EXCLUSIVE
* SPDRP_FRIENDLYNAME
* SPDRP_LOCATION_INFORMATION
* SPDRP_LOWERFILTERS
* SPDRP_REMOVAL_POLICY_OVERRIDE
* SPDRP_SECURITY
* SPDRP_SECURITY_SDS
* SPDRP_UI_NUMBER_DESC_FORMAT
* SPDRP_UPPERFILTERS

> [!NOTE]
> SPDRP_HARDWAREID or SPDRP_COMPATIBLEIDS can only be used when *DeviceInfoData* represents a root-enumerated device. For other devices, the bus driver reports hardware and compatible IDs when enumerating a child device after receiving [IRP_MN_QUERY_ID](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-id).

The following values are reserved for use by the operating system and cannot be used in the *Property* parameter:

* SPDRP_ADDRESS
* SPDRP_BUSNUMBER
* SPDRP_BUSTYPEGUID
* SPDRP_CHARACTERISTICS
* SPDRP_CAPABILITIES
* SPDRP_CLASS
* SPDRP_CLASSGUID
* SPDRP_DEVICE_POWER_DATA
* SPDRP_DEVICEDESC
* SPDRP_DEVTYPE
* SPDRP_DRIVER
* SPDRP_ENUMERATOR_NAME
* SPDRP_INSTALL_STATE
* SPDRP_LEGACYBUSTYPE
* SPDRP_LOCATION_PATHS
* SPDRP_MFG
* SPDRP_PHYSICAL_DEVICE_OBJECT_NAME
* SPDRP_REMOVAL_POLICY
* SPDRP_REMOVAL_POLICY_HW_DEFAULT
* SPDRP_SERVICE
* SPDRP_UI_NUMBER

### `PropertyBuffer` [in, optional]

A pointer to a buffer that contains the new data for the property. If the property is being cleared, then this pointer should be **NULL** and *PropertyBufferSize* must be zero.

### `PropertyBufferSize` [in]

The size, in bytes, of *PropertyBuffer*. If *PropertyBuffer* is **NULL**, then this field must be zero.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved with a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The caller of this function must be a member of the Administrators group.

The class name property cannot be set because it is based on the corresponding class GUID and is automatically updated when that property is changed. When the ClassGUID property changes, **SetupDiSetDeviceRegistryProperty** automatically cleans up any software keys associated with the device.

> [!NOTE]
> The setupapi.h header defines SetupDiSetDeviceRegistryProperty as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SetupDiGetClassRegistryProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassregistrypropertya)

[SetupDiGetDeviceRegistryProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceregistrypropertya)

[SetupDiSetClassRegistryProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetclassregistrypropertya)