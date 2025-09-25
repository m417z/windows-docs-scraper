# CM_Get_Next_Res_Des function

## Description

The **CM_Get_Next_Res_Des** function obtains a handle to the next [resource descriptor](https://learn.microsoft.com/windows-hardware/drivers/), of a specified resource type, for a [logical configuration](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources) on the local machine.

## Parameters

### `prdResDes` [out]

Pointer to a location to receive a resource descriptor handle.

### `rdResDes` [in]

Caller-supplied handle to either a resource descriptor or a logical configuration. For more information, see the following **Remarks** section.

### `ForResource` [in]

Caller-supplied resource type identifier, indicating the type of resource descriptor being requested. This must be one of the **ResType_**-prefixed constants defined in *Cfgmgr32.h*.

### `pResourceID` [out, optional]

Pointer to a location to receive a resource type identifier, if *ForResource* specifies **ResType_All**. For any other *ForResource* value, callers should set this to **NULL**.

### `ulFlags` [in]

Not used, must be zero.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

**Note** Starting with Windows 8, **CM_Get_Next_Res_Des** returns CR_CALL_NOT_IMPLEMENTED when used in a Wow64 scenario. To request information about the hardware resources on a local machine it is necessary implement an architecture-native version of the application using the hardware resource APIs. For example: An AMD64 application for AMD64 systems.

## Remarks

To enumerate a logical configuration's resource descriptors, begin by calling **CM_Get_Next_Res_Des** with the logical configuration's handle as the argument for *rdResDes*. This obtains a handle to the first resource descriptor of the type specified by *ForResource*. Then for each subsequent call to **CM_Get_Next_Res_Des**, specify the most recently obtained descriptor handle as the argument for *rdResDes*. Repeat until the function returns CR_NO_MORE_RES_DES.

To retrieve the information stored in a resource descriptor, call [CM_Get_Res_Des_Data](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_res_des_data).

To modify the information stored in a resource descriptor, call [CM_Modify_Res_Des](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_modify_res_des).

Callers of **CM_Get_Next_Res_Des** must call [CM_Free_Res_Des_Handle](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_free_res_des_handle) to deallocate the resource descriptor handle, after it is no longer needed.

## See also

[CM_Get_Next_Res_Des_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_next_res_des_ex)