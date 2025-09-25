# DS_REPL_PENDING_OPSW structure

## Description

The **DS_REPL_PENDING_OPS** structure contains an array of [DS_REPL_OP](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_opw) structures, which in turn describe the replication tasks currently executing and queued to execute, as returned by the
[DsReplicaGetInfo](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfow) and [DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w) functions. The entries in the queue are processed in priority order, and the first entry is the one currently being executed.

## Members

### `ftimeCurrentOpStarted`

Contains a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the date and time at which the first operation in the queue began executing.

### `cNumPendingOps`

Contains the number of elements in the **rgPendingOps** array.

### `rgPendingOp.size_is`

### `rgPendingOp.size_is.cNumPendingOps`

### `rgPendingOp`

Contains an array of [DS_REPL_OP](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_opw) structures that contain the replication tasks currently executing and queued to execute.

## See also

[DS_REPL_OP](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_opw)

[DsReplicaGetInfo](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfow)

[DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w)