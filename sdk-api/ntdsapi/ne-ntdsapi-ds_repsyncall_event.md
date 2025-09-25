# DS_REPSYNCALL_EVENT enumeration

## Description

The **DS_REPSYNCALL_EVENT** enumeration is used with the [DS_REPSYNCALL_UPDATE](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repsyncall_updatea) structure to define which event the **DS_REPSYNCALL_UPDATE** structure represents.

## Constants

### `DS_REPSYNCALL_EVENT_ERROR:0`

An error occurred. Error data is stored in the **pErrInfo** member of the [DS_REPSYNCALL_UPDATE](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repsyncall_updatea) structure.

### `DS_REPSYNCALL_EVENT_SYNC_STARTED:1`

Synchronization of two servers has started. Both the **pErrInfo** and **pSync** members of the [DS_REPSYNCALL_UPDATE](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repsyncall_updatea) structure are **NULL**.

### `DS_REPSYNCALL_EVENT_SYNC_COMPLETED:2`

Synchronization of two servers has just finished. The servers involved in the synchronization are identified by the **pSync** member of the [DS_REPSYNCALL_UPDATE](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repsyncall_updatea) structure. The **pErrInfo** member of the **DS_REPSYNCALL_UPDATE** structure is **NULL**.

### `DS_REPSYNCALL_EVENT_FINISHED:3`

Execution of [DsReplicaSyncAll](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicasyncalla) is complete. Both the **pErrInfo** and **pSync** members of the [DS_REPSYNCALL_UPDATE](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repsyncall_updatea) structure are **NULL**. The return value of the callback function is ignored.

## See also

[DS_REPSYNCALL_UPDATE](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repsyncall_updatea)