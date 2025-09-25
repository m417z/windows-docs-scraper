# CM_Add_Empty_Log_Conf_Ex function

## Description

[Beginning with Windows 8 and Windows Server 2012, this function has been deprecated. Please use [CM_Add_Empty_Log_Conf](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_add_empty_log_conf) instead.]

The **CM_Add_Empty_Log_Conf_Ex** function creates an empty [logical configuration](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources), for a specified configuration type and a specified device instance, on either the local or a remote machine.

## Parameters

### `plcLogConf` [out]

Pointer to a location to receive the handle to an empty logical configuration.

### `dnDevInst` [in]

Caller-supplied device instance handle that is bound to the machine handle supplied by *hMachine*.

### `Priority` [in]

Caller-supplied configuration priority value. For a list of values, see the *Priority* description for [CM_Add_Empty_Log_Conf](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_add_empty_log_conf).

### `ulFlags` [in]

Caller-supplied flags that specify the type of the logical configuration. For a list of flags, see the description *ulFlags* description for [CM_Add_Empty_Log_Conf](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_add_empty_log_conf).

### `hMachine` [in, optional]

Caller-supplied machine handle to which the caller-supplied device instance handle is bound.

**Note** Using this function to access remote machines is not supported beginning with Windows 8 and Windows Server 2012, as this functionality has been removed.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

**Note** Starting with Windows 8, **CM_Add_Empty_Log_Conf_Ex** returns CR_CALL_NOT_IMPLEMENTED when used in a Wow64 scenario. To request information about the hardware resources on a local machine it is necessary implement an architecture-native version of the application using the hardware resource APIs. For example: An AMD64 application for AMD64 systems.

## Remarks

Calling **CM_Add_Empty_Log_Conf_Ex** can cause the handles returned by [CM_Get_First_Log_Conf_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_first_log_conf_ex) and [CM_Get_Next_Log_Conf_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_next_log_conf_ex) to become invalid. Thus if you want to obtain logical configurations after calling **CM_Add_Empty_Log_Conf_Ex**, your code must call **CM_Get_First_Log_Conf_Ex** again and start at the first configuration.

To remove a logical configuration created by **CM_Add_Empty_Log_Conf_Ex**, call [CM_Free_Log_Conf_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_free_log_conf_ex).

The handle received in *plcLogConf* must be explicitly freed by calling [CM_Free_Log_Conf_Handle](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_free_log_conf_handle).

Callers of this function must have **SeLoadDriverPrivilege**. (Privileges are described in the Microsoft Windows SDK documentation.)

For information about using device instance handles that are bound to a local or a remote machine, see [CM_Get_Child_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child_ex).

Functionality to access remote machines has been removed in Windows 8 and Windows Server 2012 and later operating systems thus you cannot access remote machines when running on these versions of Windows.

## See also

[CM_Add_Empty_Log_Conf](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_add_empty_log_conf)

[CM_Free_Log_Conf_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_free_log_conf_ex)

[CM_Free_Log_Conf_Handle](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_free_log_conf_handle)

[CM_Get_Child_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child_ex)

[CM_Get_First_Log_Conf_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_first_log_conf_ex)

[CM_Get_Next_Log_Conf_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_next_log_conf_ex)