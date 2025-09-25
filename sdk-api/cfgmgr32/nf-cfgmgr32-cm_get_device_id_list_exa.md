# CM_Get_Device_ID_List_ExA function

## Description

[Beginning with Windows 8 and Windows Server 2012, this function has been deprecated. Please use [CM_Get_Device_ID_List](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_device_id_lista) instead.]

The **CM_Get_Device_ID_List_Ex** function retrieves a list of [device instance IDs](https://learn.microsoft.com/windows-hardware/drivers/install/device-instance-ids) for the [device instances](https://learn.microsoft.com/windows-hardware/drivers/) on a local or a remote machine.

## Parameters

### `pszFilter` [in, optional]

Caller-supplied pointer to a character string specifying a subset of the machine's device instance identifiers, or **NULL**. See the following description of *ulFlags*.

### `Buffer` [out]

Address of a buffer to receive a set of NULL-terminated device instance identifier strings. The end of the set is terminated by an extra **NULL**. The required buffer size should be obtained by calling [CM_Get_Device_ID_List_Size_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_device_id_list_size_exa).

### `BufferLen` [in]

Caller-supplied length, in characters, of the buffer specified by *Buffer*.

### `ulFlags` [in]

One of the optional, caller-supplied bit flags that specify search filters. If no flags are specified, the function supplies all instance identifiers for all device instances. For a list of bit flags, see the *ulFlags* description for [CM_Get_Device_ID_List](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_device_id_lista).

### `hMachine` [in, optional]

Caller-supplied machine handle, obtained from a previous call to [CM_Connect_Machine](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_connect_machinea).

**Note** Using this function to access remote machines is not supported beginning with Windows 8 and Windows Server 2012, as this functionality has been removed.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

For information about device instance IDs, see [Device Identification Strings](https://learn.microsoft.com/windows-hardware/drivers/install/device-identification-strings).

Functionality to access remote machines has been removed in Windows 8 and Windows Server 2012 and later operating systems thus you cannot access remote machines when running on these versions of Windows.