# CM_Get_Device_ID_Size function

## Description

The **CM_Get_Device_ID_Size** function retrieves the buffer size required to hold a [device instance ID](https://learn.microsoft.com/windows-hardware/drivers/install/device-instance-ids) for a [device instance](https://learn.microsoft.com/windows-hardware/drivers/) on the local machine.

> [!NOTE]
> In Windows Vista and later versions of Windows, the [unified device property model](https://learn.microsoft.com/windows-hardware/drivers/install/unified-device-property-model--windows-vista-and-later-) uses the [**DEVPKEY_Device_InstanceId**](https://learn.microsoft.com/windows-hardware/drivers/install/devpkey-device-instanceid) [property key](https://learn.microsoft.com/windows-hardware/drivers/install/property-keys) to represent the device instance identifier. See [Retrieving a Device Instance Identifier](https://learn.microsoft.com/windows-hardware/drivers/install/retrieving-a-device-instance-identifier) for details.

## Parameters

### `pulLen` [out]

Receives a value representing the required buffer size, in characters.

### `dnDevInst` [in]

Caller-supplied device instance handle that is bound to the local machine.

### `ulFlags` [in]

Not used, must be zero.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

The **CM_Get_Device_ID_Size** function should be called to determine the buffer size required by [CM_Get_Device_ID](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_device_idw).

The size value supplied in the location pointed to by *pulLen* is less than MAX_DEVICE_ID_LEN, and does not include the identifier string's terminating **NULL**. If the specified device instance does not exist, the function supplies a size value of zero.

For information about device instance IDs, see [Device Identification Strings](https://learn.microsoft.com/windows-hardware/drivers/install/device-identification-strings).

For information about using device instance handles that are bound to the local machine, see [CM_Get_Child](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child).

## See also

[CM_Get_Child](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child)

[CM_Get_Device_ID](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_device_idw)

[CM_Get_Device_ID_Size_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_device_id_size_ex)