# CM_Delete_Device_Interface_KeyW function

## Description

The **CM_Delete_Device_Interface_Key** function deletes the registry subkey that is used by applications and drivers to store interface-specific information.

## Parameters

### `pszDeviceInterface` [in]

Pointer to a string that identifies the device interface instance of the registry subkey to delete.

### `ulFlags` [in]

Reserved. Must be set to zero.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## See also

[CM_Open_Device_Interface_Key](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_open_device_interface_keyw)

[SetupDiDeleteDeviceInterfaceRegKey](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdideletedeviceinterfaceregkey)