# CM_Get_Resource_Conflict_Count function

## Description

The **CM_Get_Resource_Conflict_Count** function obtains the number of conflicts contained in a specified resource conflict list.

## Parameters

### `clConflictList` [in]

Caller-supplied handle to a conflict list, obtained by a previous call to [CM_Query_Resource_Conflict_List](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_query_resource_conflict_list).

### `pulCount` [out]

Caller-supplied address of a location to receive the conflict count.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

The count value obtained by calling **CM_Get_Resource_Conflict_Count** can be used to determine the number of times to call [CM_Get_Resource_Conflict_Details](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_resource_conflict_detailsw), which supplies information about each conflict.

If there are no entries in the conflict list, the location supplied by *pulCount* will receive zero.