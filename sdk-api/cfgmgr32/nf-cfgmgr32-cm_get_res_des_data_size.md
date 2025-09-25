# CM_Get_Res_Des_Data_Size function

## Description

The **CM_Get_Res_Des_Data_Size** function obtains the buffer size required to hold the information contained in a specified [resource descriptor](https://learn.microsoft.com/windows-hardware/drivers/) on the local machine.

## Parameters

### `pulSize` [out]

Caller-supplied address of a location to receive the required buffer size.

### `rdResDes` [in]

Caller-supplied handle to a resource descriptor, obtained by a previous call to [CM_Get_Next_Res_Des](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_next_res_des).

### `ulFlags` [in]

Not used, must be zero.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

**Note** Starting with Windows 8, **CM_Get_Res_Des_Data_Size** returns CR_CALL_NOT_IMPLEMENTED when used in a Wow64 scenario. To request information about the hardware resources on a local machine it is necessary implement an architecture-native version of the application using the hardware resource APIs. For example: An AMD64 application for AMD64 systems.

## Remarks

The returned size value represents the size of the appropriate resource structure (see [CM_Add_Res_Des](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_add_res_des)). If the resource descriptor resides in a resource requirements list, the returned size includes both the size of the resource structure and the space allocated for associated range arrays.

## See also

[CM_Get_Res_Des_Data_Size_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_res_des_data_size_ex)