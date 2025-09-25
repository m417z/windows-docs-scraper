# CM_Get_Device_ID_List_Size_ExW function

## Description

[Beginning with Windows 8 and Windows Server 2012, this function has been deprecated. Please use [CM_Get_Device_ID_List_Size](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_device_id_list_sizea) instead.]

The **CM_Get_Device_ID_List_Size_Ex** function retrieves the buffer size required to hold a list of [device instance IDs](https://learn.microsoft.com/windows-hardware/drivers/install/device-instance-ids) for a local or a remote machine's [device instances](https://learn.microsoft.com/windows-hardware/drivers/).

## Parameters

### `pulLen` [out]

Receives a value representing the required buffer size, in characters.

### `pszFilter` [in, optional]

Caller-supplied pointer to a character string specifying a subset of the machine's device instance identifiers, or **NULL**. See the following description of *ulFlags*.

### `ulFlags` [in]

One of the optional, caller-supplied bit flags that specify search filters. If no flags are specified, the function supplies the buffer size required to hold all instance identifiers for all device instances. For a list of bit flags, see the *ulFlags* description for [CM_Get_Device_ID_List_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_device_id_list_exw).

### `hMachine` [in, optional]

Caller-supplied machine handle, obtained from a previous call to [CM_Connect_Machine](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_connect_machinew).

**Note** Using this function to access remote machines is not supported beginning with Windows 8 and Windows Server 2012, as this functionality has been removed.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

The **CM_Get_Device_ID_List_Size_Ex** function should be called to determine the buffer size required by [CM_Get_Device_ID_List_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_device_id_list_exw).

The size value supplied in the location pointed to by *pulLen* is guaranteed to represent a buffer size large enough to hold all device instance identifier strings and terminating NULLs. The supplied value might actually represent a buffer size that is larger than necessary, so don't assume the value represents the true length of the character strings that [CM_Get_Device_ID_List_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_device_id_list_exw) will provide.

For information about device instance IDs, see [Device Identification Strings](https://learn.microsoft.com/windows-hardware/drivers/install/device-identification-strings).

 Functionality to access remote machines has been removed in Windows 8 and Windows Server 2012 and later operating systems thus you cannot access remote machines when running on these versions of Windows.

## See also

[CM_Get_Device_ID_List_Size](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_device_id_list_sizea)