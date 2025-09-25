# CM_Get_Log_Conf_Priority_Ex function

## Description

[Beginning with Windows 8 and Windows Server 2012, this function has been deprecated. Please use [CM_Get_Log_Conf_Priority](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_log_conf_priority) instead.]

The **CM_Get_Log_Conf_Priority_Ex** function obtains the configuration priority of a specified [logical configuration](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources) on a local or a remote machine.

## Parameters

### `lcLogConf` [in]

Caller-supplied handle to a logical configuration. This handle must have been previously obtained by calling one of the following functions:

[CM_Add_Empty_Log_Conf](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_add_empty_log_conf)

[CM_Add_Empty_Log_Conf_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_add_empty_log_conf_ex)

[CM_Get_First_Log_Conf](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_first_log_conf)

[CM_Get_First_Log_Conf_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_first_log_conf_ex)

[CM_Get_Next_Log_Conf](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_next_log_conf)

[CM_Get_Next_Log_Conf_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_next_log_conf_ex)

### `pPriority` [out]

Caller-supplied address of a location to receive a configuration priority value. For a list of priority values, see the description of *Priority* for [CM_Add_Empty_Log_Conf_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_add_empty_log_conf_ex).

### `ulFlags` [in]

Not used, must be zero.

### `hMachine` [in, optional]

Caller-supplied machine handle, obtained from a previous call to [CM_Connect_Machine](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_connect_machinew).

**Note** Using this function to access remote machines is not supported beginning with Windows 8 and Windows Server 2012, as this functionality has been removed.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

**Note** Starting with Windows 8, **CM_Get_Log_Conf_Priority_Ex** returns CR_CALL_NOT_IMPLEMENTED when used in a Wow64 scenario. To request information about the hardware resources on a local machine it is necessary implement an architecture-native version of the application using the hardware resource APIs. For example: An AMD64 application for AMD64 systems.

## Remarks

 Functionality to access remote machines has been removed in Windows 8 and Windows Server 2012 and later operating systems thus you cannot access remote machines when running on these versions of Windows.

## See also

[CM_Get_Log_Conf_Priority](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_log_conf_priority)