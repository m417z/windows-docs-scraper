# CM_Get_First_Log_Conf_Ex function

## Description

[Beginning with Windows 8 and Windows Server 2012, this function has been deprecated. Please use [CM_Get_First_Log_Conf](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_first_log_conf) instead.]

The **CM_Get_First_Log_Conf_Ex** function obtains the first [logical configuration](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources) associated with a specified [device instance](https://learn.microsoft.com/windows-hardware/drivers/) on a local or a remote machine.

## Parameters

### `plcLogConf` [out, optional]

Address of a location to receive the handle to a logical configuration, or **NULL**. See the **Remarks** section.

### `dnDevInst` [in]

Caller-supplied device instance handle that is bound to the machine handle supplied by *hMachine*.

### `ulFlags` [in]

Caller-supplied flag value indicating the type of logical configuration being requested. For a list of flags, see the *ulFlags* description for [CM_Get_First_Log_Conf](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_first_log_conf).

### `hMachine` [in, optional]

Caller-supplied machine handle to which the caller-supplied device instance handle is bound.

**Note** Using this function to access remote machines is not supported beginning with Windows 8 and Windows Server 2012, as this functionality has been removed.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

**Note** Starting with Windows 8, **CM_Get_First_Log_Conf_Ex** returns CR_CALL_NOT_IMPLEMENTED when used in a Wow64 scenario. To request information about the hardware resources on a local machine it is necessary implement an architecture-native version of the application using the hardware resource APIs. For example: An AMD64 application for AMD64 systems.

## Remarks

Calling [CM_Add_Empty_Log_Conf_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_add_empty_log_conf_ex) or [CM_Free_Log_Conf_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_free_log_conf_ex) can invalidate the handle obtained from a previous call to **CM_Get_First_Log_Conf_Ex**. Thus if you want to obtain logical configurations after calling **CM_Add_Empty_Log_Conf_Ex** or **CM_Free_Log_Conf_Ex**, your code must call **CM_Get_First_Log_Conf_Ex** again and start at the first configuration.

The handle received in *plcLogConf* must be explicitly freed by calling [CM_Free_Log_Conf_Handle](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_free_log_conf_handle).

If **CM_Get_First_Log_Conf_Ex** is called with *plcLogConf* set to **NULL**, no handle is returned. This allows you to use the return status to determine if a configuration exists without the need to subsequently free the handle.

For information about using device instance handles that are bound to a local or a remote machine, see [CM_Get_Child_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child_ex).

 Functionality to access remote machines has been removed in Windows 8 and Windows Server 2012 and later operating systems thus you cannot access remote machines when running on these versions of Windows.

## See also

[CM_Add_Empty_Log_Conf_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_add_empty_log_conf_ex)

[CM_Free_Log_Conf_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_free_log_conf_ex)

[CM_Free_Log_Conf_Handle](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_free_log_conf_handle)

[CM_Get_Child_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child_ex)

**CM_Get_First_Log_Conf**