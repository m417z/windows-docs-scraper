# CM_Add_Empty_Log_Conf function

## Description

The **CM_Add_Empty_Log_Conf** function creates an empty [logical configuration](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources), for a specified configuration type and a specified device instance, on the local machine.

## Parameters

### `plcLogConf` [out]

Address of a location to receive the handle to an empty logical configuration.

### `dnDevInst` [in]

Caller-supplied device instance handle that is bound to the local machine.

### `Priority` [in]

Caller-supplied configuration priority value. This must be one of the constant values listed in the following table. The constants are listed in order of priority, from highest to lowest. (For multiple configurations with the same *ulFlags* value, the system will attempt to use the one with the highest priority first.)

| Priority Constant | Definition |
| --- | --- |
| LCPRI_FORCECONFIG | Result of a [forced configuration](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources). |
| LCPRI_BOOTCONFIG | Result of a [boot configuration](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources). |
| LCPRI_DESIRED | Preferred configuration (better performance). |
| LCPRI_NORMAL | Workable configuration (acceptable performance). |
| LCPRI_LASTBESTCONFIG | *For internal use only.* |
| LCPRI_SUBOPTIMAL | Not a desirable configuration, but it will work. |
| LCPRI_LASTSOFTCONFIG | *For internal use only.* |
| LCPRI_RESTART | The system must be restarted |
| LCPRI_REBOOT | The system must be restarted (same as LCPRI_RESTART). |
| LCPRI_POWEROFF | The system must be shut down and powered off. |
| LCPRI_HARDRECONFIG | A jumper must be changed. |
| LCPRI_HARDWIRED | The configuration cannot be changed. |
| LCPRI_IMPOSSIBLE | The configuration cannot exist. |
| LCPRI_DISABLED | Disabled configuration. |

### `ulFlags` [in]

Caller-supplied flags that specify the type of the logical configuration. One of the following flags must be specified.

| Configuration Type Flags | Definitions |
| --- | --- |
| BASIC_LOG_CONF | Resource descriptors added to this configuration will describe a [basic configuration](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources). |
| FILTERED_LOG_CONF | *Do not use.* (Only the PnP manager can create a [filtered configuration](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources).) |
| ALLOC_LOG_CONF | *Do not use.* (Only the PnP manager can create an [allocated configuration](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources).) |
| BOOT_LOG_CONF | Resource descriptors added to this configuration will describe a [boot configuration](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources). |
| FORCED_LOG_CONF | Resource descriptors added to this configuration will describe a [forced configuration](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources). |
| OVERRIDE_LOG_CONF | Resource descriptors added to this configuration will describe an [override configuration](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources). |

One of the following bit flags can be ORed with the configuration type flag.

| Priority Comparison Flags | Definitions |
| --- | --- |
| PRIORITY_EQUAL_FIRST | If multiple configurations of the same type (*ulFlags*) have the same priority (*Priority*), this configuration is placed at the head of the list. |
| PRIORITY_EQUAL_LAST | (Default) If multiple configurations of the same type (*ulFlags*) have the same priority (*Priority*), this configuration is placed at the tail of the list. |

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

**Note** Starting with Windows 8, **CM_Add_Empty_Log_Conf** returns CR_CALL_NOT_IMPLEMENTED when used in a Wow64 scenario. To request information about the hardware resources on a local machine it is necessary implement an architecture-native version of the application using the hardware resource APIs. For example: An AMD64 application for AMD64 systems.

## Remarks

Calling **CM_Add_Empty_Log_Conf** can cause the handles returned by [CM_Get_First_Log_Conf](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_first_log_conf) and [CM_Get_Next_Log_Conf](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_next_log_conf) to become invalid. Thus if you want to obtain logical configurations after calling **CM_Add_Empty_Log_Conf**, your code must call **CM_Get_First_Log_Conf** again and start at the first configuration.

To remove a logical configuration created by **CM_Add_Empty_Log_Conf**, call [CM_Free_Log_Conf](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_free_log_conf).

The handle received in *plcLogConf* must be explicitly freed by calling [CM_Free_Log_Conf_Handle](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_free_log_conf_handle).

Callers of this function must have **SeLoadDriverPrivilege**. (Privileges are described in the Microsoft Windows SDK documentation.)

For information about using device instance handles that are bound to the local machine, see [CM_Get_Child](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child).

## See also

[CM_Add_Empty_Log_Conf_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_add_empty_log_conf_ex)

[CM_Free_Log_Conf](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_free_log_conf)

[CM_Free_Log_Conf_Handle](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_free_log_conf_handle)

[CM_Get_Child](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child)

[CM_Get_First_Log_Conf](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_first_log_conf)

[CM_Get_Next_Log_Conf](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_next_log_conf)