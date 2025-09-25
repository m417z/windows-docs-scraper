# CM_Set_DevNode_Registry_PropertyW function

## Description

The **CM_Set_DevNode_Registry_Property** function sets a specified device property in the registry.

## Parameters

### `dnDevInst` [in]

A caller-supplied device instance handle that is bound to the local machine.

### `ulProperty` [in]

A CM_DRP_-prefixed constant value that identifies the device property to be set in the registry. These constants are defined in *Cfgmgr32.h*.

### `Buffer` [in, optional]

A pointer to a caller-supplied buffer that supplies the requested device property, formatted appropriately for the property's data type.

### `ulLength` [in]

The length, in bytes, of the supplied device property.

### `ulFlags` [in]

Not used, must be zero.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes that are defined in *Cfgmgr32.h*.

## Remarks

For information about how to use device instance handles that are bound to the local machine, see [CM_Get_Child](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child).

## See also

[CM_Get_Child](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child)

[CM_Get_DevNode_Registry_Property](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_set_devnode_registry_propertyw)

[SetupDiSetDeviceRegistryProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetdeviceregistrypropertya)