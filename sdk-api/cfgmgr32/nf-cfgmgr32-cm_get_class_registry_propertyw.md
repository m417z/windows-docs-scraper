# CM_Get_Class_Registry_PropertyW function

## Description

The **CM_Get_Class_Registry_Property** function retrieves a [device setup class property](https://learn.microsoft.com/windows-hardware/drivers/install/accessing-device-setup-class-properties).

## Parameters

### `ClassGuid` [in]

A pointer to the GUID that represents the [device setup class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-setup-classes) for which to retrieve a property.

### `ulProperty` [in]

A value of type ULONG that identifies the property to be retrieved. This value must be one of the following CM_CRP_*Xxx* values that are defined in *Cfgmgr32.h*:

#### CM_CRP_UPPERFILTERS

Represents a REG_MULTI_SZ-type list of strings, where each string contains the name of an upper-level filter driver that is registered for the class.

#### CM_CRP_LOWERFILTERS

Represents a REG_MULTI_SZ-typed list of strings, where each string contains the name of a lower-level filter drivers that is registered for the class.

#### CM_CRP_SECURITY

Represents a value of type REG_BINARY that contains a variable-length, self-relative, [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntifs/ns-ntifs-_security_descriptor) structure.

#### CM_CRP_SECURITY_SDS

Represents a string of type REG_SZ that contains a security descriptor in the [Security Descriptor Definition Language (SDDL)](https://learn.microsoft.com/windows-hardware/drivers/kernel/sddl-for-device-objects) format.

#### CM_CRP_DEVTYPE

Represents a value of type REG_DWORD that indicates the device type for the class. For more information, see [Specifying Device Types](https://learn.microsoft.com/windows-hardware/drivers/kernel/specifying-device-types).

#### CM_CRP_EXCLUSIVE

Represents a value of type REG_DWORD that indicates whether users can obtain exclusive access to devices for this class. The returned value is 1 if exclusive access is allowed, or zero otherwise.

#### CM_CRP_CHARACTERISTICS

Represents a value of type DWORD that indicates the device characteristics for the class. For a list of characteristics flags, see the *DeviceCharacteristics* parameter of the [IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-iocreatedevice) routine.

### `pulRegDataType` [out, optional]

A pointer to a variable of type ULONG that receives the REG_*Xxx* constant that represents the data type of the requested property. The REG_*Xxx* constants are defined in *Winnt.h* and are described in the **Type** member of the [KEY_VALUE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/ns-wdm-_key_value_basic_information) structure. This parameter is optional and can be set to **NULL**.

### `Buffer` [out]

A pointer to a buffer that receives the requested property data. For more information about this parameter and the buffer-size parameter *pulLength*, see the following **Remarks** section.

### `pulLength` [in, out]

A pointer to variable of type ULONG whose value, on input, is the size, in bytes, of the buffer that is supplied by *Buffer*. On return, **CM_Get_Class_Registry_Property**  sets this variable to the size, in bytes, of the requested property.

### `ulFlags` [in]

Reserved for internal use only. Must be set to zero.

### `hMachine` [in, optional]

A handle to a remote machine from which to retrieve the specified device class property. This parameter is optional, and, if it is set to **NULL**, the property is retrieved from the local machine.

## Return value

If the operation succeeds, **CM_Get_Class_Registry_Property**  returns CR_SUCCESS. Otherwise, the function returns one of the other CR_*Xxx* status codes that are defined in *Cfgmgr32.h*.

## Remarks

To determine the size, in bytes, of a property before attempting to retrieve the property, first call **CM_Get_Class_Registry_Property**, supplying a **NULL***Buffer* pointer and a ******pulLength*  value of zero. In response to such a call, the function does not retrieve the property, but sets ******pulLength* to the size of the requested property and returns CR_BUFFER_SMALL. After obtaining the property size, call **CM_Get_Class_Registry_Property** again, supplying a *Buffer* pointer to the buffer to receive the property data and supplying the property size in ******pulLength*.

## See also

[CM_Set_Class_Registry_Property](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_set_class_registry_propertyw)

[KEY_VALUE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/ns-wdm-_key_value_basic_information)

[SetupDiGetClassRegistryProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassregistrypropertya)

[SetupDiSetClassRegistryProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetclassregistrypropertya)