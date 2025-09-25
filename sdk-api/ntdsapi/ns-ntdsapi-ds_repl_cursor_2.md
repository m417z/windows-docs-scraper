# DS_REPL_CURSOR_2 structure

## Description

The **DS_REPL_CURSOR_2** structure contains inbound replication state data with respect to all replicas of a given naming context, as returned by the
[DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w) function. This structure is an enhanced version of the [DS_REPL_CURSOR](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_cursor) structure.

## Members

### `uuidSourceDsaInvocationID`

Contains the invocation identifier of the originating server to which the **usnAttributeFilter** corresponds.

### `usnAttributeFilter`

Contains the maximum update sequence number to which the destination server can indicate that it has recorded all changes originated by the given server at update sequence numbers less than, or equal to, this update sequence number. This is used to filter changes at replication source servers that the destination server has already applied.

### `ftimeLastSyncSuccess`

Contains a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the date and time of the last successful synchronization operation.

## See also

[DS_REPL_CURSOR](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_cursor)

[DS_REPL_CURSORS_2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_cursors_2)

[DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w)

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)