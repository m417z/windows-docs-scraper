# DS_REPL_CURSORS structure

## Description

The **DS_REPL_CURSORS** structure is used with the [DsReplicaGetInfo](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfow) and [DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w) function to provide replication state data with respect to all replicas of a given naming context.

## Members

### `cNumCursors`

Contains the number of elements in the **rgCursor** array.

### `dwReserved`

Reserved for future use.

### `rgCursor.size_is`

### `rgCursor.size_is.cNumCursors`

### `rgCursor`

Contains an array of [DS_REPL_CURSOR](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_cursor) structures that contain the requested replication data. The **cNumCursors** member contains the number of elements in this array.

## See also

[DS_REPL_CURSOR](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_cursor)

[DsReplicaGetInfo](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfow)

[DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w)