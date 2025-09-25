# CM_Free_Resource_Conflict_Handle function

## Description

The **CM_Free_Resource_Conflict_Handle** function invalidates a handle to a resource conflict list, and frees the handle's associated memory allocation.

## Parameters

### `clConflictList` [in]

Caller-supplied handle to be freed. This conflict list handle must have been previously obtained by calling [CM_Query_Resource_Conflict_List](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_query_resource_conflict_list).

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

An application must call **CM_Free_Resource_Conflict_Handle** after it has finished using the handle that was obtained calling [CM_Query_Resource_Conflict_List](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_query_resource_conflict_list).