# DsReplicaFreeInfo function

## Description

The **DsReplicaFreeInfo** function frees the replication state data structure allocated by the [DsReplicaGetInfo](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfow) or [DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w) functions.

## Parameters

### `InfoType` [in]

Contains one of the [DS_REPL_INFO_TYPE](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ne-ntdsapi-ds_repl_info_type) values that specifies the type of replication data structure contained in *pInfo*. This must be the same value passed to the [DsReplicaGetInfo](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfow) or [DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w) function when the structure was allocated.

### `pInfo` [in]

Pointer to the replication data structure allocated by the [DsReplicaGetInfo](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfow) or [DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w) functions.

## See also

[DS_REPL_INFO_TYPE](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ne-ntdsapi-ds_repl_info_type)

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsReplicaGetInfo](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfow)

[DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w)