# DsReplicaConsistencyCheck function

## Description

The **DsReplicaConsistencyCheck** function invokes the Knowledge Consistency Checker (KCC) to verify the replication topology. The KCC dynamically adjusts the data replication topology of your network when domain controllers are added to or removed from the network, when a domain controller is unavailable, or when the data replication schedules are changed.

## Parameters

### `hDS` [in]

Contains a directory service handle obtained from either the
[DSBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda),
[DSBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda), or [DsBindWithSpn](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithspna) function.

### `TaskID` [in]

Identifies the task that the KCC should execute. **DS_KCC_TASKID_UPDATE_TOPOLOGY** is the only currently supported value.

### `dwFlags` [in]

Contains a set of flags that modify the function behavior. This can be zero or a combination of one or more of the following values.

#### DS_KCC_FLAG_ASYNC_OP

The task is queued and then the function returns without waiting for the task to complete.

#### DS_KCC_FLAG_DAMPED

The task will not be added to the queue if another queued task will run soon.

## Return value

If the function performs its operation successfully, the return value is **ERROR_SUCCESS**. If the function fails, the return value can be one of the following.

## See also

[DS_KCC_TASKID](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ne-ntdsapi-ds_kcc_taskid)

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda)

[DsBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda)

[DsBindWithSpn](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithspna)