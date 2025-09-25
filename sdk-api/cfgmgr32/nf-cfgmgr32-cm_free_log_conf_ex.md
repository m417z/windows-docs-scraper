# CM_Free_Log_Conf_Ex function

## Description

[Beginning with Windows 8 and Windows Server 2012, this function has been deprecated. Please use [CM_Free_Log_Conf](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_free_log_conf) instead.]

The **CM_Free_Log_Conf_Ex** function removes a [logical configuration](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources) and all associated [resource descriptors](https://learn.microsoft.com/windows-hardware/drivers/) from either a local or a remote machine.

## Parameters

### `lcLogConfToBeFreed` [in]

Caller-supplied handle to a logical configuration. This handle must have been previously obtained by calling one of the following functions:

[CM_Add_Empty_Log_Conf](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_add_empty_log_conf)

[CM_Add_Empty_Log_Conf_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_add_empty_log_conf_ex)

[CM_Get_First_Log_Conf](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_first_log_conf)

[CM_Get_First_Log_Conf_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_first_log_conf_ex)

[CM_Get_Next_Log_Conf](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_next_log_conf)

[CM_Get_Next_Log_Conf_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_next_log_conf_ex)

### `ulFlags` [in]

Not used, must be zero.

### `hMachine` [in, optional]

Caller-supplied machine handle, obtained from a previous call to [CM_Connect_Machine](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_connect_machinew).

**Note** Using this function to access remote machines is not supported beginning with Windows 8 and Windows Server 2012, as this functionality has been removed.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

**Note** Starting with Windows 8, **CM_Free_Log_Conf_Ex** returns CR_CALL_NOT_IMPLEMENTED when used in a Wow64 scenario. To request information about the hardware resources on a local machine it is necessary implement an architecture-native version of the application using the hardware resource APIs. For example: An AMD64 application for AMD64 systems.

## Remarks

Calling **CM_Free_Log_Conf_Ex** can cause the handles returned by [CM_Get_First_Log_Conf_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_first_log_conf_ex) and [CM_Get_Next_Log_Conf_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_next_log_conf_ex) to become invalid. Thus if you want to obtain logical configurations after calling **CM_Free_Log_Conf_Ex**, your code must call **CM_Get_First_Log_Conf_Ex** again and start at the first configuration.

Note that calling **CM_Free_Log_Conf_Ex** frees the configuration, but not the configuration's handle. To free the handle, call **CM_Free_Log_Conf_Handle_Ex**.

Callers of this function must have **SeLoadDriverPrivilege**. (Privileges are described in the Microsoft Windows SDK documentation.)

 Functionality to access remote machines has been removed in Windows 8 and Windows Server 2012 and later operating systems thus you cannot access remote machines when running on these versions of Windows.

## See also

[CM_Free_Log_Conf](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_free_log_conf)