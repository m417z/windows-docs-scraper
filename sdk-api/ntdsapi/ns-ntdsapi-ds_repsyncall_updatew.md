# DS_REPSYNCALL_UPDATEW structure

## Description

The **DS_REPSYNCALL_UPDATE** structure contains status data about the replication performed by the
[DsReplicaSyncAll](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicasyncalla) function. The **DsReplicaSyncAll** function passes this structure to a callback function in its *pFnCallBack* parameter. For more information about the callback function, see
[SyncUpdateProc](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms677968(v=vs.85)).

## Members

### `event`

Contains a [DS_REPSYNCALL_EVENT](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ne-ntdsapi-ds_repsyncall_event) value that describes the event which the **DS_REPSYNCALL_UPDATE** structure represents.

### `pErrInfo`

Pointer to a
[DS_REPSYNCALL_ERRINFO](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repsyncall_errinfoa) structure that contains error data about the replication performed by the [DsReplicaSyncAll](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicasyncalla) function.

### `pSync`

Pointer to a
[DS_REPSYNCALL_SYNC](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repsyncall_synca) structure that identifies the source and destination servers that have either initiated or finished synchronization.

## See also

[DS_REPSYNCALL_ERRINFO](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repsyncall_errinfoa)

[DS_REPSYNCALL_EVENT](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ne-ntdsapi-ds_repsyncall_event)

[DS_REPSYNCALL_SYNC](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repsyncall_synca)

[Domain Controller and Replication Management Structures](https://learn.microsoft.com/windows/desktop/AD/domain-controller-and-replication-management-structures)

[DsReplicaSyncAll](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicasyncalla)

[SyncUpdateProc](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms677968(v=vs.85))

## Remarks

> [!NOTE]
> The ntdsapi.h header defines DS_REPSYNCALL_UPDATE as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).