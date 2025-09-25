# CM_Get_Device_ID_ExW function

## Description

[Beginning with Windows 8 and Windows Server 2012, this function has been deprecated. Please use [CM_Get_Device_ID](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_device_idw) instead.]

The **CM_Get_Device_ID_Ex** function retrieves the [device instance ID](https://learn.microsoft.com/windows-hardware/drivers/install/device-instance-ids) for a specified [device instance](https://learn.microsoft.com/windows-hardware/drivers/) on a local or a remote machine.

## Parameters

### `dnDevInst` [in]

Caller-supplied device instance handle that is bound to the machine handle supplied by *hMachine*.

### `Buffer` [out]

Address of a buffer to receive a device instance ID string. The required buffer size can be obtained by calling [CM_Get_Device_ID_Size_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_device_id_size_ex), then incrementing the received value to allow room for the string's terminating **NULL**.

### `BufferLen` [in]

Caller-supplied length, in characters, of the buffer specified by *Buffer*.

### `ulFlags` [in]

Not used, must be zero.

### `hMachine` [in, optional]

Caller-supplied machine handle to which the caller-supplied device instance handle is bound.

**Note** Using this function to access remote machines is not supported beginning with Windows 8 and Windows Server 2012, as this functionality has been removed.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

The function appends a NULL terminator to the supplied [device instance ID](https://learn.microsoft.com/windows-hardware/drivers/install/device-instance-ids) string, unless the buffer is too small to hold the string. In this case, the function supplies as much of the identifier string as will fit into the buffer, and then returns CR_BUFFER_SMALL.

For information about device instance IDs, see [Device Identification Strings](https://learn.microsoft.com/windows-hardware/drivers/install/device-identification-strings).

For information about using device instance handles that are bound to a local or a remote machine, see [CM_Get_Child_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child_ex).

 Functionality to access remote machines has been removed in Windows 8 and Windows Server 2012 and later operating systems thus you cannot access remote machines when running on these versions of Windows.

## See also

[CM_Get_Child_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child_ex)

[CM_Get_Device_ID](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_device_idw)