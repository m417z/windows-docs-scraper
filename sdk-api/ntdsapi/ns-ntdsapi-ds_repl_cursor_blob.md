# DS_REPL_CURSOR_BLOB structure

## Description

The **DS_REPL_CURSOR_BLOB** structure contains inbound replication state data with respect to all replicas of a given naming context. This structure is similar to the [DS_REPL_CURSOR_3](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_cursor_3w) structure, but is obtained from the [Lightweight Directory Access Protocol API](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/lightweight-directory-access-protocol-ldap-api) functions when obtaining binary data for the **msDS-NCReplCursors** attribute.

## Members

### `uuidSourceDsaInvocationID`

Contains the invocation identifier of the originating server to which the **usnAttributeFilter** corresponds.

### `usnAttributeFilter`

Contains the maximum update sequence number to which the destination server can indicate that it has recorded all changes originated by the given server at update sequence numbers less than, or equal to, this update sequence number. This is used to filter changes at replication source servers that the destination server has already applied.

### `ftimeLastSyncSuccess`

Contains a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the date and time of the last successful synchronization operation.

### `oszSourceDsaDN`

Contains the offset, in bytes, from the address of this structure to a null-terminated Unicode string that contains the distinguished name of the directory service agent that corresponds to the source server to which this replication state data applies.

## See also

[DS_REPL_CURSOR_3](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_cursor_3w)

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)

[Lightweight Directory Access Protocol API](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/lightweight-directory-access-protocol-ldap-api)