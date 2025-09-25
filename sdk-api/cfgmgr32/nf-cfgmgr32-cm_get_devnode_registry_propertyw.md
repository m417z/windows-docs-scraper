# CM_Get_DevNode_Registry_PropertyW function

## Description

 The **CM_Get_DevNode_Registry_Property** function retrieves a specified device property from the registry.

## Parameters

### `dnDevInst` [in]

A caller-supplied device instance handle that is bound to the local machine.

### `ulProperty` [in]

A CM_DRP_-prefixed constant value that identifies the device property to be obtained from the registry. These constants are defined in *Cfgmgr32.h*.

### `pulRegDataType` [out, optional]

Optional, can be **NULL**. A pointer to a location that receives the registry data type, specified as a REG_-prefixed constant defined in *Winnt.h*.

### `Buffer` [out, optional]

Optional, can be **NULL**. A pointer to a caller-supplied buffer that receives the requested device property. If this value is **NULL**, the function supplies only the length of the requested data in the address pointed to by *pulLength*.

### `pulLength` [in, out]

A pointer to a ULONG variable into which the function stores the length, in bytes, of the requested device property.

If the *Buffer* parameter is set to **NULL**, the ULONG variable must be set to zero.

If the *Buffer* parameter is not set to **NULL**, the ULONG variable must be set to the length, in bytes, of the caller-supplied buffer.

### `ulFlags` [in]

Not used, must be zero.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes that are defined in *Cfgmgr32.h*.

## Remarks

For information about how to use device instance handles that are bound to the local machine, see [CM_Get_Child](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child).

## See also

[CM_Get_Child](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child)

[CM_Set_DevNode_Registry_Property](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_set_devnode_registry_propertyw)

[SetupDiGetDeviceRegistryProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceregistrypropertya)