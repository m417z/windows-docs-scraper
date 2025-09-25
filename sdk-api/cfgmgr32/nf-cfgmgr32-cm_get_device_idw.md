# CM_Get_Device_IDW function

## Description

The **CM_Get_Device_ID** function retrieves the [device instance ID](https://learn.microsoft.com/windows-hardware/drivers/install/device-instance-ids) for a specified [device instance](https://learn.microsoft.com/windows-hardware/drivers/) on the local machine.

> [!NOTE]
> In Windows Vista and later versions of Windows, the [unified device property model](https://learn.microsoft.com/windows-hardware/drivers/install/unified-device-property-model--windows-vista-and-later-) uses the [**DEVPKEY_Device_InstanceId**](https://learn.microsoft.com/windows-hardware/drivers/install/devpkey-device-instanceid) [property key](https://learn.microsoft.com/windows-hardware/drivers/install/property-keys) to represent the device instance identifier. See [Retrieving a Device Instance Identifier](https://learn.microsoft.com/windows-hardware/drivers/install/retrieving-a-device-instance-identifier) for details.

## Parameters

### `dnDevInst` [in]

Caller-supplied device instance handle that is bound to the local machine.

### `Buffer` [out]

Address of a buffer to receive a device instance ID string. The required buffer size can be obtained by calling [CM_Get_Device_ID_Size](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_device_id_size), then incrementing the received value to allow room for the string's terminating **NULL**.

### `BufferLen` [in]

Caller-supplied length, in characters, of the buffer specified by *Buffer*.

### `ulFlags` [in]

Not used, must be zero.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

The function appends a NULL terminator to the supplied device instance ID string, unless the buffer is too small to hold the string. In this case, the function supplies as much of the identifier string as will fit into the buffer, and then returns CR_BUFFER_SMALL.

For information about device instance IDs, see [Device Identification Strings](https://learn.microsoft.com/windows-hardware/drivers/install/device-identification-strings).

For information about using device instance handles that are bound to the local machine, see [CM_Get_Child](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child).

## See also

[CM_Get_Child](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child)

[CM_Get_Device_ID_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_device_id_exw)