# CM_Get_Res_Des_Data function

## Description

The **CM_Get_Res_Des_Data** function retrieves the information stored in a [resource descriptor](https://learn.microsoft.com/windows-hardware/drivers/) on the local machine.

## Parameters

### `rdResDes` [in]

Caller-supplied handle to a resource descriptor, obtained by a previous call to [CM_Get_Next_Res_Des](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_next_res_des).

### `Buffer` [out]

Address of a buffer to receive the contents of a resource descriptor. The required buffer size should be obtained by calling [CM_Get_Res_Des_Data_Size](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_res_des_data_size).

### `BufferLen` [in]

Caller-supplied length of the buffer specified by *Buffer*.

### `ulFlags` [in]

Not used, must be zero.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

**Note** Starting with Windows 8, **CM_Get_Res_Des_Data** returns CR_CALL_NOT_IMPLEMENTED when used in a Wow64 scenario. To request information about the hardware resources on a local machine it is necessary implement an architecture-native version of the application using the hardware resource APIs. For example: An AMD64 application for AMD64 systems.

## Remarks

Information returned in the buffer supplied by *Buffer* will be formatted as one of the resource type structures listed in the description of [CM_Add_Res_Des](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_add_res_des), based on the resource type that was specified when [CM_Get_Next_Res_Des](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_next_res_des) was called to obtain the resource descriptor handle.

## See also

[CM_Get_Res_Des_Data_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_res_des_data_ex)