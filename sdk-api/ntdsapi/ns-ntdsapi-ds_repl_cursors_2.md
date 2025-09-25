# DS_REPL_CURSORS_2 structure

## Description

The **DS_REPL_CURSORS_2** structure is used with the [DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w) function to provide replication state data with respect to all replicas of a given naming context.

## Members

### `cNumCursors`

Contains the number of elements in the **rgCursor** array.

### `dwEnumerationContext`

Contains the zero-based index of the next entry to retrieve if more entries are available. This value is passed for the *dwEnumerationContext* parameter in the next call to [DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w) to retrieve the next block of entries. If no more entries are available, this member contains -1.

### `rgCursor.size_is`

### `rgCursor.size_is.cNumCursors`

### `rgCursor`

Contains an array of [DS_REPL_CURSOR_2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_cursor_2) structures that contain the requested replication data. The **cNumCursors** member contains the number of elements in this array.

## See also

[DS_REPL_CURSOR_2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_cursor_2)

[DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w)