# CM_Query_Resource_Conflict_List function

## Description

The **CM_Query_Resource_Conflict_List** function identifies device instances having resource requirements that conflict with a specified device instance's resource description.

## Parameters

### `pclConflictList` [out]

Caller-supplied address of a location to receive a handle to a conflict list.

### `dnDevInst` [in]

Caller-supplied device instance handle that is bound to the machine handle supplied by *hMachine*.

### `ResourceID` [in]

Caller-supplied resource type identifier. This must be one of the **ResType_**-prefixed constants defined in *Cfgmgr32.h*.

### `ResourceData` [in]

Caller-supplied pointer to a resource descriptor, which can be one of the structures listed under the [CM_Add_Res_Des](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_add_res_des) function's description of *ResourceData*.

### `ResourceLen` [in]

Caller-supplied length of the structure pointed to by *ResourceData*.

### `ulFlags` [in]

Not used, must be zero.

### `hMachine` [in, optional]

Caller-supplied machine handle to which the caller-supplied device instance handle is bound.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

**Note** Starting with Windows 8, **CM_Query_Resource_Conflict_List** returns CR_CALL_NOT_IMPLEMENTED when used in a Wow64 scenario. To request information about the hardware resources on a local machine it is necessary implement an architecture-native version of the application using the hardware resource APIs. For example: An AMD64 application for AMD64 systems.

## Remarks

When calling **CM_Query_Resource_Conflict_List**, specify a device instance handle and resource descriptor. (Resource descriptors for existing device nodes can be obtained by calling [CM_Get_Res_Des_Data](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_res_des_data).) These parameters indicate the specific resources you'd like a specific device to use. The resulting conflict list identifies devices that use the same resources, along with resources reserved by the machine.

After calling **CM_Query_Resource_Conflict_List**, an application can call [CM_Get_Resource_Conflict_Count](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_resource_conflict_count) to determine the number of conflicts contained in the resource conflict list. (The number of conflicts can be zero.) Then the application can call [CM_Get_Resource_Conflict_Details](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_resource_conflict_detailsw) for each entry in the conflict list.

After an application has finished using the handle received for *pclConflictList*, it must call [CM_Free_Resource_Conflict_Handle](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_free_resource_conflict_handle).

For information about using device instance handles that are bound to a local or a remote machine, see [CM_Get_Child_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child_ex).

## See also

[CM_Free_Resource_Conflict_Handle](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_free_resource_conflict_handle)

[CM_Get_Child_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child_ex)

[CM_Get_Res_Des_Data](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_res_des_data)

[CM_Get_Resource_Conflict_Count](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_resource_conflict_count)

[CM_Get_Resource_Conflict_Details](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_resource_conflict_detailsw)