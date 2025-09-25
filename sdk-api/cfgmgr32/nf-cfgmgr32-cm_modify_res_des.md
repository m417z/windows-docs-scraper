# CM_Modify_Res_Des function

## Description

The **CM_Modify_Res_Des** function modifies a specified resource descriptor on the local machine.

## Parameters

### `prdResDes` [out]

Pointer to a location to receive a handle to the modified resource descriptor.

### `rdResDes` [in]

Caller-supplied handle to the resource descriptor to be modified. This handle must have been previously obtained by calling one of the following functions:

[CM_Add_Res_Des](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_add_res_des)

[CM_Add_Res_Des_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_add_res_des_ex)

[CM_Get_Next_Res_Des](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_next_res_des)

[CM_Get_Next_Res_Des_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_next_res_des_ex)

**CM_Modify_Res_Des**

[CM_Modify_Res_Des_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_modify_res_des_ex)

### `ResourceID` [in]

Caller-supplied resource type identifier. This must be one of the **ResType_**-prefixed constants defined in *Cfgmgr32.h*.

### `ResourceData` [in]

Caller-supplied pointer to a resource descriptor, which can be one of the structures listed under the [CM_Add_Res_Des](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_add_res_des) function's description of *ResourceData*.

### `ResourceLen` [in]

Caller-supplied length of the structure pointed to by *ResourceData*.

### `ulFlags` [in]

Not used, must be zero.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

**Note** Starting with Windows 8, **CM_Modify_Res_Des** returns CR_CALL_NOT_IMPLEMENTED when used in a Wow64 scenario. To request information about the hardware resources on a local machine it is necessary implement an architecture-native version of the application using the hardware resource APIs. For example: An AMD64 application for AMD64 systems.

## Remarks

The caller-supplied resource descriptor data replaces the existing data. The values specified for *ResourceID* and *ResourceLen* do not have to match the existing resource descriptor.

If the value specified for *ResourceID* is **ResType_ClassSpecific**, then the specified resource descriptor must be the last one associated with the logical configuration.

Callers of **CM_Modify_Res_Des** must call [CM_Free_Res_Des_Handle](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_free_res_des_handle) to deallocate the resource descriptor handle, after it is no longer needed.

Callers of this function must have **SeLoadDriverPrivilege**. (Privileges are described in the Microsoft Windows SDK documentation.)

## See also

[CM_Modify_Res_Des_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_modify_res_des_ex)