# DS_REPL_CURSOR structure

## Description

The **DS_REPL_CURSOR** structure contains inbound replication state data with respect to all replicas of a given naming context, as returned by the
[DsReplicaGetInfo](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfow) and [DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w) functions.

## Members

### `uuidSourceDsaInvocationID`

Contains the invocation identifier of the originating server to which the **usnAttributeFilter** corresponds.

### `usnAttributeFilter`

Contains the maximum update sequence number to which the destination server can indicate that it has recorded all changes originated by the given server at update sequence numbers less than, or equal to, this update sequence number. This is used to filter changes at replication source servers that the destination server has already applied.

## See also

[DS_REPL_CURSORS](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_cursors)

[DsReplicaGetInfo](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfow)

[DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w)