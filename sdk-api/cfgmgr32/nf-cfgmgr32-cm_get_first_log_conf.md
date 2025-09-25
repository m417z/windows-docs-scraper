# CM_Get_First_Log_Conf function

## Description

The **CM_Get_First_Log_Conf** function obtains the first [logical configuration](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources), of a specified configuration type, associated with a specified [device instance](https://learn.microsoft.com/windows-hardware/drivers/) on the local machine.

## Parameters

### `plcLogConf` [out, optional]

Address of a location to receive the handle to a logical configuration, or **NULL**. See the following **Remarks** section.

### `dnDevInst` [in]

Caller-supplied device instance handle that is bound to the local machine.

### `ulFlags` [in]

Caller-supplied flag value indicating the type of logical configuration being requested. One of the flags in the following table must be specified.

| Configuration Type Flags | Definitions |
| --- | --- |
| BASIC_LOG_CONF | The caller is requesting [basic configuration](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources) information. |
| FILTERED_LOG_CONF | The caller is requesting [filtered configuration](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources) information. |
| ALLOC_LOG_CONF | The caller is requesting [allocated configuration](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources) information. |
| BOOT_LOG_CONF | The caller is requesting [boot configuration](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources) information. |
| FORCED_LOG_CONF | The caller is requesting [forced configuration](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources) information. |
| OVERRIDE_LOG_CONF | The caller is requesting [override configuration](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources) information. |

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

**Note** Starting with Windows 8, **CM_Get_First_Log_Conf** returns CR_CALL_NOT_IMPLEMENTED when used in a Wow64 scenario. To request information about the hardware resources on a local machine it is necessary implement an architecture-native version of the application using the hardware resource APIs. For example: An AMD64 application for AMD64 systems.

## Remarks

Calling [CM_Add_Empty_Log_Conf](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_add_empty_log_conf) or [CM_Free_Log_Conf](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_free_log_conf) can invalidate the handle obtained from a previous call to **CM_Get_First_Log_Conf**. Thus if you want to obtain logical configurations after calling **CM_Add_Empty_Log_Conf** or **CM_Free_Log_Conf**, your code must call **CM_Get_First_Log_Conf** again and start at the first configuration.

The handle received in *plcLogConf* must be explicitly freed by calling [CM_Free_Log_Conf_Handle](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_free_log_conf_handle).

If **CM_Get_First_Log_Conf** is called with *plcLogConf* set to **NULL**, no handle is returned. This allows you to use the return status to determine if a configuration exists without the need to subsequently free the handle.

For information about using device instance handles that are bound to the local machine, see [CM_Get_Child](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child).

## See also

[CM_Add_Empty_Log_Conf](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_add_empty_log_conf)

[CM_Free_Log_Conf](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_free_log_conf)

[CM_Free_Log_Conf_Handle](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_free_log_conf_handle)

[CM_Get_Child](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child)

[CM_Get_First_Log_Conf_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_first_log_conf_ex)