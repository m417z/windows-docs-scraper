# CM_Get_Next_Log_Conf function

## Description

The **CM_Get_Next_Log_Conf** function obtains the next [logical configuration](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources) associated with a specific [device instance](https://learn.microsoft.com/windows-hardware/drivers/) on the local machine.

## Parameters

### `plcLogConf` [out, optional]

Address of a location to receive the handle to a logical configuration, or **NULL**. (See the following **Remarks** section.

### `lcLogConf` [in]

Caller-supplied handle to a logical configuration. This handle must have been previously obtained by calling one of the following functions:

[CM_Get_First_Log_Conf](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_first_log_conf)

**CM_Get_Next_Log_Conf**

### `ulFlags` [in]

Not used, must be zero.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

**Note** Starting with Windows 8, **CM_Get_Next_Log_Conf** returns CR_CALL_NOT_IMPLEMENTED when used in a Wow64 scenario. To request information about the hardware resources on a local machine it is necessary implement an architecture-native version of the application using the hardware resource APIs. For example: An AMD64 application for AMD64 systems.

## Remarks

To enumerate the logical configurations associated with a device instance, call [CM_Get_First_Log_Conf](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_first_log_conf) to obtain the first logical configuration of a specified configuration type, then call **CM_Get_Next_Log_Conf** repeatedly until it returns CR_NO_MORE_LOG_CONF.

Calling [CM_Add_Empty_Log_Conf](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_add_empty_log_conf) or [CM_Free_Log_Conf](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_free_log_conf) can invalidate the handle obtained from a previous call to **CM_Get_Next_Log_Conf**. Thus if you want to obtain logical configurations after calling **CM_Add_Empty_Log_Conf** or **CM_Free_Log_Conf**, your code must call **CM_Get_First_Log_Conf** again and start at the first configuration.

The handle received in *plcLogConf* must be explicitly freed by calling [CM_Free_Log_Conf_Handle](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_free_log_conf_handle).

If **CM_Get_Next_Log_Conf** is called with *plcLogConf* set to **NULL**, no handle is returned. This allows you to use the return status to determine if a configuration exists without the need to subsequently free the handle.

## See also

[CM_Get_Next_Log_Conf_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_next_log_conf_ex)