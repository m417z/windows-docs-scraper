# CM_Get_Resource_Conflict_DetailsA function

## Description

The **CM_Get_Resource_Conflict_Details** function obtains the details about one of the resource conflicts in a conflict list.

## Parameters

### `clConflictList` [in]

Caller-supplied handle to a conflict list, obtained by a previous call to [CM_Query_Resource_Conflict_List](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_query_resource_conflict_list).

### `ulIndex` [in]

Caller-supplied value used as an index into the conflict list. This value can be from zero to one less than the number returned by [CM_Get_Resource_Conflict_Count](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_resource_conflict_count).

### `pConflictDetails` [in, out]

Caller-supplied address of a [CONFLICT_DETAILS](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-conflict_details_a) structure to receive conflict details. The caller must supply values for the structure's *CD_ulSize* and *CD_ulMask* structures.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

To determine conflicting resource requirements between a specified device and other devices on a machine, use the following steps.

1. Call [CM_Query_Resource_Conflict_List](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_query_resource_conflict_list) to obtain a handle to a list of resource conflicts.
2. Call [CM_Get_Resource_Conflict_Count](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_resource_conflict_count) to determine the number of conflicts contained in the resource conflict list.
3. Call **CM_Get_Resource_Conflict_Details** for each entry in the conflict list.

The following conflicts are typically not reported:

* If there are multiple conflicts for a resource, and the owners of only some of the conflicts can be determined, the conflicts without identifiable owners are not reported.
* Conflicts that appear to be with the specified device (that is, the device conflicts with itself) are not reported.
* If multiple non-Plug and Play devices use the same driver, resource conflicts among these devices might not be reported.

Sometimes, resources assigned to the HAL might be reported as either conflicting with the HAL or not available.