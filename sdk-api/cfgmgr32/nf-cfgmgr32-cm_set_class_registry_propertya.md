# CM_Set_Class_Registry_PropertyA function

## Description

The **CM_Set_Class_Registry_Property** function sets or deletes a property of a [device setup class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-setup-classes).

## Parameters

### `ClassGuid` [in]

A pointer to the GUID that represents the device setup class for which to set a property.

### `ulProperty` [in]

A value of type ULONG that identifies the property to set. This value must be one of the CM_CRP_*Xxx* values that are described for the *ulProperty* parameter of the [CM_Get_Class_Registry_Property](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_class_registry_propertya) function.

### `Buffer` [in, optional]

A pointer to a buffer that contains the property data. This parameter is optional and can be set to **NULL**. For more information about setting this parameter and the corresponding *ulLength* parameter, see the following **Remarks** section.

### `ulLength` [in]

A value of type ULONG that specifies the size, in bytes, of the property data.

### `ulFlags` [in]

Reserved for internal use only. Must be set to zero.

### `hMachine` [in, optional]

A handle to a remote machine on which to set the specified [device setup class property](https://learn.microsoft.com/windows-hardware/drivers/install/accessing-device-setup-class-properties). This parameter is optional. If set to **NULL**, the property is set on the local machine.

## Return value

If the operation succeeds, **CM_Set_Class_Registry_Property**  returns CR_SUCCESS. Otherwise, the function returns one of the other CR_*Xxx* status codes that are defined in *Cfgmgr32.h*.

## Remarks

If *Buffer* is **NULL**, *ulLength* must be set to zero.

If *ulLength* is set to zero, the function deletes the property.

If *Buffer* is not set to **NULL** and *ulLength* is not set to zero, the supplied value must be the correct size for the REG_*Xxx* data type for the property that is specified in *ulProperty*.

## See also

[CM_Get_Class_Registry_Property](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_class_registry_propertya)
[SetupDiGetClassRegistryProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassregistrypropertya)
[SetupDiSetClassRegistryProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetclassregistrypropertya)