# CM_Add_Res_Des function

## Description

The **CM_Add_Res_Des** function adds a [resource descriptor](https://learn.microsoft.com/windows-hardware/drivers/) to a [logical configuration](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources).

## Parameters

### `prdResDes` [out, optional]

Pointer to a location to receive a handle to the new resource descriptor.

### `lcLogConf` [in]

Caller-supplied handle to the logical configuration to which the resource descriptor should be added. This handle must have been previously obtained by calling one of the following functions:

[CM_Add_Empty_Log_Conf](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_add_empty_log_conf)

[CM_Add_Empty_Log_Conf_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_add_empty_log_conf_ex)

[CM_Get_First_Log_Conf](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_first_log_conf)

[CM_Get_First_Log_Conf_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_first_log_conf_ex)

[CM_Get_Next_Log_Conf](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_next_log_conf)

[CM_Get_Next_Log_Conf_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_next_log_conf_ex)

### `ResourceID` [in]

Caller-supplied resource type identifier, which identifies the type of structure supplied by *ResourceData*. This must be one of the **ResType_**-prefixed constants defined in *Cfgmgr32.h*.

### `ResourceData` [in]

Caller-supplied pointer to one of the resource structures listed in the following table.

| *ResourceID* Parameter | Resource Structure |
| --- | --- |
| **ResType_BusNumber** | [BUSNUMBER_RESOURCE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-busnumber_resource) |
| **ResType_ClassSpecific** | [CS_RESOURCE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-cs_resource) |
| **ResType_DevicePrivate** | [DEVPRIVATE_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/install/devprivate-resource) |
| **ResType_DMA** | [DMA_RESOURCE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-dma_resource) |
| **ResType_IO** | [IO_RESOURCE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-io_resource) |
| **ResType_IRQ** | [IRQ_RESOURCE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-irq_resource_32) |
| **ResType_Mem** | [MEM_RESOURCE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-mem_resource) |
| **ResType_MfCardConfig** | [MFCARD_RESOURCE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-mfcard_resource) |
| **ResType_PcCardConfig** | [PCCARD_RESOURCE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-pccard_resource) |

### `ResourceLen` [in]

Caller-supplied length of the structure pointed to by *ResourceData*.

### `ulFlags` [in]

Not used, must be zero.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

**Note** Starting with Windows 8, **CM_Add_Res_Des** returns CR_CALL_NOT_IMPLEMENTED when used in a Wow64 scenario. To request information about the hardware resources on a local machine it is necessary implement an architecture-native version of the application using the hardware resource APIs. For example: An AMD64 application for AMD64 systems.

## Remarks

Callers of **CM_Add_Res_Des** must call [CM_Free_Res_Des_Handle](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_free_res_des_handle) to deallocate the resource descriptor handle, after it is no longer needed.

Callers of this function must have **SeLoadDriverPrivilege**. (Privileges are described in the Microsoft Windows SDK documentation.)

## See also

[CM_Add_Res_Des_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_add_res_des_ex)

[CM_Free_Res_Des_Handle](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_free_res_des_handle)