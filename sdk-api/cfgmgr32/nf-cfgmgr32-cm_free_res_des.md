# CM_Free_Res_Des function

## Description

The **CM_Free_Res_Des** function removes a [resource descriptor](https://learn.microsoft.com/windows-hardware/drivers/) from a [logical configuration](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources) on the local machine.

## Parameters

### `prdResDes` [out]

Caller-supplied location to receive a handle to the configuration's previous resource descriptor. This parameter can be **NULL**. For more information, see the following **Remarks** section.

### `rdResDes` [in]

Caller-supplied handle to the resource descriptor to be removed. This handle must have been previously obtained by calling one of the following functions:

[CM_Add_Res_Des](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_add_res_des)

[CM_Add_Res_Des_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_add_res_des_ex)

[CM_Get_Next_Res_Des](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_next_res_des)

[CM_Get_Next_Res_Des_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_next_res_des_ex)

[CM_Modify_Res_Des](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_modify_res_des)

[CM_Modify_Res_Des_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_modify_res_des_ex)

### `ulFlags` [in]

Not used, must be zero.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

**Note** Starting with Windows 8, **CM_Free_Res_Des** returns CR_CALL_NOT_IMPLEMENTED when used in a Wow64 scenario. To request information about the hardware resources on a local machine it is necessary implement an architecture-native version of the application using the hardware resource APIs. For example: An AMD64 application for AMD64 systems.

## Remarks

Resource descriptors for each configuration are stored in an array. If you specify an address for *prdResDes*, then **CM_Free_Res_Des** returns a handle to the resource descriptor that was previous, in the array, to the one removed. If the handle specified by *rdResDes* represents the resource descriptor located first in the array, then *prdResDes* receives a handle to the logical configuration.

Note that calling **CM_Free_Res_Des** frees the resource descriptor, but not the descriptor's handle. To free the handle, call **CM_Free_Res_Des_Handle**.

Callers of this function must have **SeLoadDriverPrivilege**. (Privileges are described in the Microsoft Windows SDK documentation.)

## See also

[CM_Free_Res_Des_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_free_res_des_ex)